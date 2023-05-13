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
    extern void lex_init(void);
    extern void lex_deinit(void);
    extern int yyleng;
    extern int yy_flex_debug;
    extern int yydebug;
    extern int yylex(void);
    int yyerror(const char* s);

    SymbolTable table;
    Validator valid;
%}

/* ### Regular Definitions ### */
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

genn_stmt:  type IDENTIFIER ';' {  table.addSymbolInTable(new Symbol($2.value,$1.value)); }
           | type IDENTIFIER EQU func_call ';'
           | IDENTIFIER EQU func_call ';'
           | CONSTANT type IDENTIFIER EQU rvalue ';' {Symbol* sy= new Symbol($3.value, $2.value); sy->setIsInitialised(1); sy->setIsConstant(1);bool checker = valid.check_syntax(sy->getVarType(),$5.value,sy->checkInitialisation());bool constchecker= valid.check_constant(sy->checkInitialisation(),sy->checkConstant()); if (checker && constchecker) {table.addSymbolInTable(sy); table.modifySymbolInTable(sy,$5.value);} else {printf("error mismatching \n");}}
           | IDENTIFIER EQU expr ';' {Symbol* sy = table.getSymbolObjectbyName($1.value); sy->setIsInitialised(1); bool checker = valid.check_syntax(sy->getVarType(),$3.value,sy->checkInitialisation());if(checker) {table.setSymbolByNameInTable($1.value, $3.value);} else {printf("error mismatching\n");table.removeSymbolFromTable(sy);}}
           | type IDENTIFIER EQU expr ';' { Symbol* sy = new Symbol($2.value,$1.value); sy->setIsInitialised(1); bool checker = valid.check_syntax(sy->getVarType(),$4.value,sy->checkInitialisation()); if (checker) {table.addSymbolInTable(sy); table.setSymbolByNameInTable($2.value, $4.value);} else {printf("error mismatching \n");} }
           | expr ';'
           ;


func_stmt: func_proto
	       | func_define
           | func_call
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
      |%empty
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

case_list:  case_list CASE rvalue ':' stmt_list BREAK ';' 
            | CASE rvalue ':' stmt_list BREAK ';' 
            ;

case_default: DEFAULT ':' stmt_list BREAK ';'
            ;
            
expr_list: expr
         | expr_list ',' expr
         ;

expr: rvalue { $$ = $1; /*printf($1.type); printf($1.value);*/ }
     | IDENTIFIER { $$.type = $1.type/*ELMAFROUD HENA NEGIB TYPE EL SYMBOL*/; $$.value = table.getSymbolByNameInTable($1.value); }
     | expr PLUS expr
     | expr MINUS expr
     | expr MULT expr
     | expr DIV expr
     | expr POWER expr
     | expr MODULE expr
     | expr EQU_EQU expr
     | expr NOT_EQU expr 
     | expr MORE_OR_EQU expr
     | expr LESS_OR_EQU expr
     | expr MORE expr
     | expr LESS expr
     | expr AND expr
     | expr OR expr
     | expr INC 
     | expr DEC
     | NOT expr
     ;

%%
     
/* ############ Auxiliary Functions ############ */

int main(int argc, char **argv) { 
    yydebug = ENABLE_YACC_DEBUG;
    yy_flex_debug = ENABLE_LEX_DEBUG;

    lex_init();
    yyparse();
    lex_deinit();

    table.printSymbolTable(); 

    return 0;
}

int yyerror(char const *s)
{
    return fprintf(stderr, "%s\n", s);
}


//Symbol* sy = table.getSymbolObjectByName($$.value); table.modifySymbolInTable(sy,table.getSymbolByNameInTable($1.value));

/* 
     std::string val = table.getSymbolByNameInTable($1.value);
      char* buffer = new char[val.length() + 1]; 
      strcpy(buffer, val.c_str()); 
      printf(buffer); 
      $$.value = (char*) malloc(val.length() + 1);
      strcpy($$.value, val.c_str());
      $$.value[val.length()] = '\0'; */