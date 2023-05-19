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
    #include "../Scopes/scopestack.h"
    #include "../FunctionTable/functiontable.h"
    #include "../Validator/validator.h"
    extern void lex_init(void*&);
    extern void lex_deinit(void*&);
    extern int yylex(union YYSTYPE*, struct YYLTYPE*, void*);
    int yyerror(struct YYLTYPE*, void*, const char*);

    void* scanner;
    extern void yyset_debug(int, void*);
    extern int yyget_leng(void*);

    ScopeStack scope;
    SymbolTable* table = scope.getGlobals();

    FunctionTable functions;
    Function* func = NULL;

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
%token <gvalue> TYPE_INT TYPE_FLOAT TYPE_CHAR TYPE_BOOL TYPE_STRING
%token TYPE_VOID
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

stmt: genn_stmt // {printf("genn_stmt\n");}
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

stmt_list: stmt             //{printf("stmt\n");}
         | stmt_list stmt   //{printf("stmt_list stmt\n");}
         ;

func_stmt_list: stmt_list RETURN expr ';'       {/*Check func Vartype with expr type*/}
                |  RETURN expr ';'
                ;

break_stmt_list: stmt_list BREAK ';' 
               | BREAK ';' 
               ;


 /*/////////////////// third degree /////////////////////////////*/

genn_stmt:  type IDENTIFIER ';'                         {    printf("hello \n");table->addSymbolInTable(new Symbol($2.value,$1.value));}
           | type IDENTIFIER EQU func_call ';'
           | IDENTIFIER EQU func_call ';'
           | CONSTANT type IDENTIFIER EQU rvalue ';'    {
                                                            Symbol* sym = new Symbol($3.value, $2.value);
                                                            sym->setIsInitialised(1); 
                                                            sym->setIsConstant(1);
                                                            if (sym->getVarType()==$5.type || (sym->getVarType()=="int" && $5.type=="float")|| (sym->getVarType()=="float" && $5.type=="int")) 
                                                            {
                                                                table->addSymbolInTable(sym);
                                                                table->modifySymbolInTable(sym,valid.TypeConversion(sym->getVarType(), $5.type, $5.value));
                                                            }
                                                            else{
                                                                printf("ERROR! Type Mismatching \n");
                                                            }
                                                        }

           | IDENTIFIER EQU expr ';'                    {
                                                            SymbolTable* firstTable = scope.getSymbolTableFromStack($1.value);
                                                            if (firstTable != NULL)
                                                            {
                                                                Symbol* sym = firstTable->getSymbolObjectbyName($1.value);
                                                                if(sym->getVarType()==$3.type || (sym->getVarType()=="int" && $3.type=="float") || (sym->getVarType()=="float" && $3.type=="int")) 
                                                                {
                                                                    firstTable->setSymbolByNameInTable($1.value,valid.TypeConversion(sym->getVarType(), $3.type, $3.value));
                                                                }
                                                                else if(  strcmp($3.type, "ID") != 0 ) // condition to account for undefined variables
                                                                {
                                                                        printf("ERROR! Type Mismatching\n");
                                                                }
                                                            }
                                                        }

           | type IDENTIFIER EQU expr ';'               { 
                                                            Symbol* sym = table->getSymbolObjectbyName($2.value);
                                                            if (sym == NULL)
                                                            {
                                                                Symbol* sym = new Symbol($2.value,$1.value);
                                                                bool out = valid.checkType(sym->getVarType(), $4.type, @1.first_line);
                                                                if (out/*sym->getVarType()==$4.type*/ || (sym->getVarType()=="int" && $4.type=="float") || (sym->getVarType()=="float" && $4.type=="int")) {
                                                                    sym->setIsInitialised(1); 
                                                                    table->addSymbolInTable(sym); 
                                                                    table->setSymbolByNameInTable($2.value,valid.TypeConversion(sym->getVarType(), $4.type, $4.value));
                                                                    }
                                                                else if ( strcmp($4.type, "ID") != 0 ) { // condition to account for undefined variables
                                                                    printf("ERROR! Type Mismatching \n");
                                                                }
                                                            }
                                                            else{
                                                                   printf("ERROR! variable defined before \n");
                                                            }
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
           
repeat_stmt: REPEAT scope_begin stmt_list scope_end UNTIL '(' expr ')' ';'
                  | REPEAT scope_begin scope_end UNTIL '(' expr ')' ';'
                  ;
                  
switch_stmt:   SWITCH '(' IDENTIFIER ')' scope_begin case_list case_default scope_end ';'
                | SWITCH '(' IDENTIFIER ')' scope_begin case_default scope_end ';'
                ;


 /*///////////////////// forth degree /////////////////////////*/
func_proto: func_sgnt parameters ';'                                                    { functions.addFunctionInTable(func); func = NULL; };
          | ret_func_sgnt parameters ';'                                                { functions.addFunctionInTable(func); func = NULL; };
          ;

func_define: func_sgnt parameters scope_begin stmt_list scope_end                       { func->setIsDefined(1); functions.addFunctionInTable(func); func = NULL; };
           | ret_func_sgnt parameters scope_begin func_stmt_list scope_end              { func->setIsDefined(1); functions.addFunctionInTable(func); func = NULL; };
           ;
        
func_call: IDENTIFIER '(' expr_list ')'                                                 { /*Check function table to make sure function exists and correct parameters*/ };



for_proto: FOR '(' IDENTIFIER EQU expr ';' expr ';' expr ')' ';'
	       | FOR '(' expr ';' expr ';' expr ')' ';'
           ;

for_define: FOR '(' IDENTIFIER EQU expr ';' expr ';' expr ')' scope_begin stmt_list scope_end 
	        | FOR '(' IDENTIFIER EQU expr ';' expr ';' expr ')' scope_begin break_stmt_list scope_end 
            | FOR '(' expr ';' expr ';' expr ')' scope_begin stmt_list scope_end 
            | FOR '(' expr ';' expr ';' expr ')' scope_begin break_stmt_list scope_end 
            ;


if_proto: IF '(' expr ')' ';' 
        ;

if_define: IF '(' expr ')' scope_begin stmt_list scope_end 
           |  IF '(' expr ')' scope_begin stmt_list scope_end ELSE scope_begin stmt_list scope_end
           |  IF '(' expr ')' scope_begin stmt_list scope_end ELSE scope_begin scope_end
           |  IF '(' expr ')' scope_begin stmt_list scope_end ELSE ';'
	       |  IF '(' expr ')' scope_begin scope_end 
           |  IF '(' expr ')' scope_begin scope_end ELSE scope_begin stmt_list scope_end
           |  IF '(' expr ')' scope_begin scope_end ELSE scope_begin scope_end
           |  IF '(' expr ')' scope_begin scope_end ELSE ';'
           ;


enum_declare: ENUM IDENTIFIER scope_begin enum_list scope_end ';' ;

enum_define: ENUM IDENTIFIER IDENTIFIER EQU IDENTIFIER ';'

while_proto: WHILE '(' expr ')' ';' ;


while_define: WHILE '(' expr ')' scope_begin stmt_list scope_end    
             | WHILE '(' expr ')' scope_begin break_stmt_list scope_end
             ;



 /*//////////////////////fifth degree /////////////////////////////// */

type: TYPE_INT { $$.type = "TYPE"; $$.value = "int"; }
      | TYPE_FLOAT { $$.type = "TYPE"; $$.value = "float"; }
      | TYPE_CHAR { $$.type = "TYPE"; $$.value = "char"; }
      | TYPE_BOOL { $$.type = "TYPE"; $$.value = "bool"; }
      | TYPE_STRING { $$.type = "TYPE"; $$.value = "string"; }
      ;


func_sgnt: TYPE_VOID IDENTIFIER '('             { func = new Function($2.value, "void"); };
         ;

ret_func_sgnt: type IDENTIFIER '('              { func = new Function($2.value, $1.value); };
             ;


parameters: type IDENTIFIER ')'             { func->addParameter(new Symbol($2.value, $1.value)); };
	  | type IDENTIFIER ',' parameters      { func->addParameter(new Symbol($2.value, $1.value)); };
      | ')'
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

case_list:  case_list CASE rvalue case_scope_begin break_stmt_list      { table = scope.removeScope(); }
            | CASE rvalue case_scope_begin break_stmt_list              { table = scope.removeScope(); }
            ;

case_default: DEFAULT case_scope_begin break_stmt_list                  { table = scope.removeScope(); }
            ;
            
expr_list: expr
         | expr ',' expr_list
         ;

expr: rvalue { $$ = $1; }
     | IDENTIFIER               { 
                                    SymbolTable* firstTable = scope.getSymbolTableFromStack($1.value);
                                    if (firstTable != NULL)
                                    {
                                        Symbol* sym = firstTable->getSymbolObjectbyName($1.value);
                                        sym->setIsUsed(1);
                                        $$.type =firstTable->getSymbolTypeByNameInTable($1.value);
                                        $$.value = firstTable->getSymbolByNameInTable($1.value);
                                        if(!sym->checkInitialisation()) 
                                        { 
                                            printf("warning: Variable not initialized\n");
                                        }
                                    } 
                                    else 
                                    {
                                        printf("Error: Unidentified variable\n");
                                    }
                                }
     | expr PLUS expr           {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr MINUS expr          {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr MULT expr           {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr DIV expr            {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr POWER expr          {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr MODULE expr         {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr EQU_EQU expr        {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr NOT_EQU expr        {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr MORE_OR_EQU expr    {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr LESS_OR_EQU expr    {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr MORE expr           {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr LESS expr           {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr AND expr            {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr OR expr             {valid.checkType($1.type, $3.type, @1.first_line);}
     | expr INC                 {
                                    if (!($1.type == "int") || !($1.type == "float")){
                                        { printf("Error: Cant increment variable of this type\n");}
                                    }
                                }
     | expr DEC                 {
                                    if (!($1.type == "int") || !($1.type == "float")){
                                        { printf("Error: Cant decrement variable of this type\n");}
                                    }
                                }
     | NOT expr                 {
                                    if (!($2.type == "int") || !($2.type == "bool")){
                                        { printf("Error: Cant negate variable of this type\n");}
                                    }
                                }
     ;

scope_begin: '{'            {
                                table = scope.addScope();
                                if(func != NULL) 
                                {
                                    for(int i = 0; i < func->getCount(); i++)
                                    {
                                        table->addSymbolInTable(func->getParameter(i));
                                    }
                                }
                            }
             ;

scope_end: '}'              {
                                table->checkSymbolTable(); 
                                table = scope.removeScope();
                            }
           ;

case_scope_begin: ':'       {table = scope.addScope();}
                ;

%%
     
/* ############ Auxiliary Functions ############ */

int main(int argc, char **argv) { 
    lex_init(scanner);

    yydebug = ENABLE_YACC_DEBUG;
    yyset_debug(ENABLE_LEX_DEBUG, scanner);

    yyparse(scanner);

    scope.printSymbolTables();
    functions.printFunctionTable();

    lex_deinit(scanner);

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