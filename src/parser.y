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
    extern void lex_init(void);
    extern void lex_deinit(void);
    extern int yyleng;
    extern int yy_flex_debug;
    extern int yydebug;
    extern int yylex(void);
    int yyerror(const char* s);
%}

/* ### Regular Definitions ### */
%union {
    int ivalue;
    float fvalue;
    char cvalue;
    char* svalue;
   //TODO node type will be put here to be the type of any scopes tokens
};

%token <ivalue> INTEGER
%token <fvalue> FLOAT
%token <ivalue> BOOL
%token <cvalue> CHAR
%token <svalue> STRING
%token TYPE_INT TYPE_FLOAT TYPE_CHAR TYPE_BOOL TYPE_STRING TYPE_VOID
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
%token IDENTIFIER
%token COMMENT



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

genn_stmt:  type IDENTIFIER ';'
           | type IDENTIFIER EQU func_call ';'
           | IDENTIFIER EQU func_call ';'
           | CONSTANT type IDENTIFIER EQU rvalue ';'
           | IDENTIFIER EQU expr ';'
           | type IDENTIFIER EQU expr ';'
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

type: TYPE_INT
      | TYPE_FLOAT
      | TYPE_CHAR
      | TYPE_BOOL
      | TYPE_STRING
      ;

parameters: type IDENTIFIER
	  | type IDENTIFIER ',' parameters
      |%empty
      ;

rvalue: INTEGER
        | FLOAT
        | CHAR
        | BOOL
        | STRING
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

expr: rvalue
     | IDENTIFIER
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


    Symbol* sym1 = new Symbol("first", "int");
    Symbol* sym2 = new Symbol("second", "float");
    Symbol* sym3 = new Symbol("third", "char");
    Symbol* sym4 = new Symbol("fourth", "double");
    Symbol* sym5 = new Symbol("fifth", "bool");

    SymbolTable table;

    table.addSymbolInTable(sym1);
    table.addSymbolInTable(sym2);
    table.addSymbolInTable(sym3);
    table.addSymbolInTable(sym4);
    table.addSymbolInTable(sym5);

    table.modifySymbolInTable(sym1, "5");
    table.modifySymbolInTable(sym2, "5.45");
    table.modifySymbolInTable(sym5, "true");

    table.printSymbolTable();

    table.removeSymbolFromTable(sym3);
    table.printSymbolTable();

    return 0;
}

int yyerror(char const *s)
{
    return fprintf(stderr, "%s\n", s);
}
