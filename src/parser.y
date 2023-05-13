/* ############ Declarations ############ */
/* ### Auxiliary declarations ### */
%{
    /*To enable yacc debugging (tracing the grammar rules) set the ENABLE_YACC_DEBUG flag to 1 (default: 0)*/
    #define ENABLE_YACC_DEBUG 0

    /*To enable lex debugging (tracing the token rules) set the ENABLE_LEX_DEBUG flag to 1 (default: 0)*/
    #define ENABLE_LEX_DEBUG 0
%}

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symboltable.h"
    #include "validator.h"
    extern void lex_init(void*&);
    extern void lex_deinit(void*&);
    extern int yylex(union YYSTYPE*, struct YYLTYPE*, void*);
    int yyerror(struct YYLTYPE*, void*, const char*);

    void* scanner;
    extern void yyset_debug(int, void*);
    extern int yyget_leng(void*);

    SymbolTable table;
    Validator valid;
%}

/* ### Regular Definitions ### */
%define api.pure full
%lex-param {void* scanner}
%parse-param {void* scanner}

%locations
%define parse.error custom

%union {

    struct 
    {
        const char* type;
        const char* value;
    } ivalue;

    struct 
    {
        const char* type;
        const char* value;
    } fvalue;

    struct 
    {
        const char* type;
        const char* value;
    } cvalue;

    struct 
    {
        const char* type;
        const char* value;
    } bvalue;

    struct 
    {
        const char* type;
        const char* value;
    } svalue;

    struct 
    {
        const char* type;
        const char* value;
    } gvalue;

   //TODO node type will be put here to be the type of any scopes tokens
};

%token <ivalue> INTEGER
%token <fvalue> FLOAT
%token <bvalue> BOOL
%token <cvalue> CHAR
%token <svalue> STRING
%token <gvalue> TYPE_INT TYPE_FLOAT TYPE_CHAR TYPE_BOOL TYPE_STRING TYPE_VOID
%token CONSTANT
%token ENUM
%token WHILE FOR BREAK
%token IF ELSE RETURN
%token SWITCH CASE DEFAULT
%token PRINT
%token MINUS MULT PLUS DIV MODULE POWER EQU INC DEC
%token MORE LESS EQU_EQU MORE_OR_EQU LESS_OR_EQU NOT_EQU
%token AND OR NOT
%token REPEAT UNTIL
%token <gvalue> IDENTIFIER
%token COMMENT

%type <gvalue> type
%type <gvalue> expr
%type <gvalue> rvalue

/*to specify the precedence and associativity of operators*/
%left PLUS MINUS
%left MULT DIV
%left MODULE
%right POWER
%right INC DEC
%left EQU_EQU NOT_EQU MORE LESS MORE_OR_EQU LESS_OR_EQU
%right EQU 
%nonassoc OR 
%nonassoc AND
%nonassoc NOT 

%start program 

%% 
    /* ############ Rules ############ */

 /*///////////// the most general rule (program rule)////////////*/

program: program stmt
         | stmt
         ;


 /*////////////////// second degreee ////////////////////////////*/

stmt: genn_stmt
      | func_stmt
      | print_stmt
      | for_stmt
      | if_stmt
      | enum_stmt
      | while_stmt
      | repeat_stmt
      | switch_stmt
      | COMMENT
      ;

stmt_list: stmt
         | stmt_list stmt
         ;

func_stmt_list: stmt_list RETURN expr ';'
                |  RETURN expr ';'
                ;

break_stmt_list: stmt_list BREAK ';' 
               | BREAK ';' 
               ;


 /*/////////////////// third degree /////////////////////////////*/

genn_stmt:  type IDENTIFIER ';'                         {   table.addSymbolInTable(new Symbol($2.value,$1.value));
                                                            printf("ID @ %d:%d\n", @2.first_line, @2.first_column);
                                                        }
           | type IDENTIFIER EQU func_call ';'
           | IDENTIFIER EQU func_call ';'
           | CONSTANT type IDENTIFIER EQU rvalue ';'    {
                                                            Symbol* sym= new Symbol($3.value, $2.value);
                                                            sym->setIsInitialised(1); sym->setIsConstant(1);
                                                            bool checker = valid.checkSyntax(sym->getVarType(),$5.value); 
                                                            if (checker) {
                                                                table.addSymbolInTable(sym);
                                                                table.modifySymbolInTable(sym,$5.value);
                                                                }
                                                            else {
                                                                printf("error mismatching \n");
                                                                }
                                                            printf("ID @ %d:%d\n", @3.first_line, @3.first_column);
                                                        }
           | IDENTIFIER EQU expr ';'                    {
                                                            Symbol* sym = table.getSymbolObjectbyName($1.value); 
                                                            if (sym != NULL)
                                                            {
                                                                bool checker = valid.checkSyntax(sym->getVarType(),$3.value);
                                                                if(checker) {
                                                                    table.setSymbolByNameInTable($1.value, $3.value);
                                                                    }
                                                                else {
                                                                    printf("error mismatching\n");
                                                                    }
                                                            }
                                                            printf("ID @ %d:%d\n", @1.first_line, @1.first_column);
                                                        }
           | type IDENTIFIER EQU expr ';'               { 
                                                            Symbol* sym = new Symbol($2.value,$1.value);
                                                            sym->setIsInitialised(1); 
                                                            bool checker = valid.checkSyntax(sym->getVarType(),$4.value); 
                                                        if (checker) {
                                                                table.addSymbolInTable(sym); 
                                                                table.setSymbolByNameInTable($2.value, $4.value);
                                                                } 
                                                            else {
                                                                printf("error mismatching \n");
                                                                }
                                                            printf("ID @ %d:%d\n", @2.first_line, @2.first_column);
                                                        }
           | expr ';'
           ;


func_stmt: func_proto
	       | func_define
           | func_call
           ;


print_stmt: PRINT '(' expr ')' ';'
            ;


for_stmt: for_proto
	      | for_define
          ;

if_stmt: if_proto
         | if_define
         ;

enum_stmt: enum_declare
	  | enum_define
           ;


while_stmt: while_proto
           | while_define
           ;
           
repeat_stmt: REPEAT '{' stmt_list '}' UNTIL '(' expr ')' ';'
                  | REPEAT '{' '}' UNTIL '(' expr ')' ';'
                  ;
                  
switch_stmt:   SWITCH '(' IDENTIFIER ')' '{' case_list case_default '}' ';'
                | SWITCH '(' IDENTIFIER ')' '{' case_default '}' ';'
                ;


 /*///////////////////// forth degree /////////////////////////*/
func_proto: type IDENTIFIER '(' parameters ')' ';'
	        | TYPE_VOID IDENTIFIER '(' parameters ')' ';' 
            ;


func_define: type IDENTIFIER '(' parameters ')' '{' func_stmt_list '}'
             | TYPE_VOID IDENTIFIER '(' parameters ')' '{' stmt_list '}'
             ;
        

func_call: IDENTIFIER '(' expr_list ')' ;



for_proto: FOR '(' IDENTIFIER EQU expr ';' expr ';' expr ')' ';'
	       | FOR '(' expr ';' expr ';' expr ')' ';'
           ;

for_define: FOR '(' IDENTIFIER EQU expr ';' expr ';' expr ')' '{' stmt_list '}' 
	        | FOR '(' IDENTIFIER EQU expr ';' expr ';' expr ')' '{' break_stmt_list '}' 
            | FOR '(' expr ';' expr ';' expr ')' '{' stmt_list '}' 
            | FOR '(' expr ';' expr ';' expr ')' '{' break_stmt_list '}' 
            ;


if_proto: IF '(' expr ')' ';' 
        ;

if_define: IF '(' expr ')' '{' stmt_list '}' 
           |  IF '(' expr ')' '{' stmt_list '}' ELSE '{' stmt_list '}'
           |  IF '(' expr ')' '{' stmt_list '}' ELSE '{' '}'
           |  IF '(' expr ')' '{' stmt_list '}' ELSE ';'
	       |  IF '(' expr ')' '{' '}' 
           |  IF '(' expr ')' '{' '}' ELSE '{'stmt_list '}'
           |  IF '(' expr ')' '{' '}' ELSE '{' '}'
           |  IF '(' expr ')' '{' '}' ELSE ';'
           ;


enum_declare: ENUM IDENTIFIER '{' enum_list '}' ';' ;

enum_define: ENUM IDENTIFIER IDENTIFIER EQU IDENTIFIER ';'

while_proto: WHILE '(' expr ')' ';' ;


while_define: WHILE '(' expr ')' '{' stmt_list '}'
             | WHILE '(' expr ')' '{' break_stmt_list '}'
             ;



 /*//////////////////////fifth degree /////////////////////////////// */

type: TYPE_INT { $$.type = "TYPE"; $$.value = "int"; }
      | TYPE_FLOAT { $$.type = "TYPE"; $$.value = "float"; }
      | TYPE_CHAR { $$.type = "TYPE"; $$.value = "char"; }
      | TYPE_BOOL { $$.type = "TYPE"; $$.value = "bool"; }
      | TYPE_STRING { $$.type = "TYPE"; $$.value = "string"; }
      ;

parameters: type IDENTIFIER
	  | type IDENTIFIER ',' parameters
      | %empty
      ;

rvalue: INTEGER { $$.type = "int"; $$.value = $1.value; }
        | FLOAT { $$.type = "float"; $$.value = $1.value; }
        | CHAR { $$.type = "char"; $$.value = $1.value; }
        | BOOL { $$.type = "bool"; $$.value = $1.value; }
        | STRING { $$.type = "string"; $$.value = $1.value; }
        ;

enum_list: IDENTIFIER 
	       | IDENTIFIER EQU INTEGER
           | IDENTIFIER EQU INTEGER ',' enum_list
           | IDENTIFIER ',' enum_list
           ;

case_list:  case_list CASE rvalue ':' break_stmt_list 
            | CASE rvalue ':' break_stmt_list   
            ;

case_default: DEFAULT ':' break_stmt_list 
            ;
            
expr_list: expr
         | expr_list ',' expr
         ;

expr: rvalue { $$ = $1; }
     | IDENTIFIER { $$.type = $1.type/*ELMAFROUD HENA NEGIB TYPE EL SYMBOL*/; $$.value = table.getSymbolByNameInTable($1.value); if($$.value == NULL) {$$.value = "TEMP";}; }
     | expr PLUS expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr MINUS expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr MULT expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr DIV expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr POWER expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr MODULE expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr EQU_EQU expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr NOT_EQU expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr MORE_OR_EQU expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr LESS_OR_EQU expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr MORE expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr LESS expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr AND expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr OR expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr INC  { $$.type = "TEMP"; $$.value = "TEMP"; }
     | expr DEC { $$.type = "TEMP"; $$.value = "TEMP"; }
     | NOT expr { $$.type = "TEMP"; $$.value = "TEMP"; }
     ;

%%
     
/* ############ Auxiliary Functions ############ */

int main(int argc, char **argv) { 
    lex_init(scanner);

    yydebug = ENABLE_YACC_DEBUG;
    yyset_debug(ENABLE_LEX_DEBUG, scanner);

    yyparse(scanner);

    lex_deinit(scanner);
    
    table.printSymbolTable(); 

    return 0;
}

int yyerror(struct YYLTYPE* yylloc, void* scanner, const char *s)
{
    return fprintf(stderr, "%s\n", s);
}

/*CODE COPIED FROM BISON DOCUMENTATION, JUST FOR TESTING, CAN CHANGE LATER*/
static int yyreport_syntax_error(const yypcontext_t *ctx, void* scanner)
{
    int res = 0;
    YYLOCATION_PRINT(stderr, yypcontext_location(ctx));
    fprintf(stderr, ": syntax error");

    // Report the tokens expected at this point.
    {
        yysymbol_kind_t expected[5];
        int n = yypcontext_expected_tokens(ctx, expected, 5);
        if (n < 0)
        {
          // Forward errors to yyparse.
          res = n;
        }
        else
        {
          for (int i = 0; i < n; ++i)
          {
              fprintf(stderr, "%s %s", i == 0 ? ": expected" : " or", yysymbol_name(expected[i]));
          }  
        }     
    }

    // Report the unexpected token.
    {
        yysymbol_kind_t lookahead = yypcontext_token(ctx);
        if (lookahead != YYSYMBOL_YYEMPTY)
        {
            fprintf(stderr, " before %s, len = %d", yysymbol_name(lookahead), yyget_leng(scanner));
        }
    }

    fprintf(stderr, "\n");
    return res;
}
