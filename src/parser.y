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
    extern FILE *yyin;
    extern FILE *yyout;
    extern int yyleng;
    extern int yy_flex_debug;
    int yydebug;
    extern int yylex(void);
    int yyerror(const char* s);
%}

/* ### Regular Definitions ### */
%union {
    int ivalue;
    float fvalue;
    char cvalue;
};

%token <ivalue> INTEGER
%token <fvalue> FLOAT
%token <cvalue> BOOL
%token <cvalue> CHAR
%token TYPE_INT TYPE_FLOAT TYPE_CHAR TYPE_BOOL TYPE_VOID
%token CONSTANT
%token ENUM
%token WHILE FOR BREAK CONTINUE 
%token IF ELSE ELSEIF RETURN
%token SWITCH CASE DEFAULT
%token MINUS MULT PLUS DIV MODULE POWER EQU INC DEC
%token MORE LESS EQU_EQU MORE_OR_EQU LESS_OR_EQU NOT_EQU
%token AND OR NOT
%token OPEN_CURL CLOSE_CURL OPEN_BRAC CLOSE_BRAC SEMICOLON COMMA COLON
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
 /*/////////////////Rules///////////////////////*/

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
      ;

stmt_list: stmt
         | stmt_list stmt
         ;

func_stmt_list: RETURN expr ';'
	             | stmt func_stmt_list 
                 ;

for_stmt_list: BREAK ';' 
               |stmt for_stmt_list
               ;

 /*/////////////////// third degree /////////////////////////////*/

genn_stmt: type IDENTIFIER ';'
           | type IDENTIFIER EQU IDENTIFIER ';'
           | type IDENTIFIER EQU rvalue ';'
           | CONSTANT type IDENTIFIER EQU IDENTIFIER ';'
           | IDENTIFIER EQU expr ';'
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
           ;

 /*///////////////////// forth degree /////////////////////////*/

func_proto: type IDENTIFIER '(' parameters ')' ';'
	        | TYPE_VOID IDENTIFIER '(' parameters ')' ';' 
            ;

func_define: type IDENTIFIER '(' parameters ')' '{' stmt_list '}'
            | TYPE_VOID IDENTIFIER '(' parameters ')' '{' stmt_list '}'
            | type IDENTIFIER '(' parameters ')' '{' func_stmt_list '}'
            | TYPE_VOID IDENTIFIER '(' parameters ')' '{' func_stmt_list '}'
            ;
        

func_call: IDENTIFIER '(' expr_list ')' ;



for_proto: FOR '(' IDENTIFIER EQU expr ';' expr ';' expr ')';
	      | FOR '(' expr ';' expr ';' expr ')';
          ;

for_define: FOR '(' IDENTIFIER EQU expr ';' expr ';' expr ')' '{' stmt_list '}' ';'
	        | FOR '(' IDENTIFIER EQU expr ';' expr ';' expr ')' '{' for_stmt_list '}' ';'
            | FOR '(' expr ';' expr ';' expr ')' '{' stmt_list '}' ';'
            | FOR '(' expr ';' expr ';' expr ')' '{' for_stmt_list '}' ';' 
            ;


if_proto: IF '(' expr ')' ';' ;
        ;

if_define: IF '(' expr ')' '{' stmt_list '}' ';'
	       |  IF '(' expr ')' '{' '}' ';'
           ;


enum_declare: ENUM IDENTIFIER '{' enum_list '}' ';' ;


 /*//////////////////////fifth degree /////////////////////////////// */

type: TYPE_INT
      | TYPE_FLOAT
      | TYPE_CHAR
      | TYPE_BOOL

parameters: IDENTIFIER
	  | IDENTIFIER ',' parameters
          ;

rvalue: INTEGER
        | FLOAT
        | CHAR
        | BOOL
        ;

enum_list: IDENTIFIER 
	       | IDENTIFIER EQU INTEGER
           | IDENTIFIER EQU INTEGER ',' enum_list
           | IDENTIFIER ',' enum_list
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

%%
     
/* ############ Auxiliary Functions ############ */

int main(int argc, char **argv) { 
    yydebug = ENABLE_YACC_DEBUG;
    yy_flex_debug = ENABLE_LEX_DEBUG;

    if (argc == 1)
    {
        fprintf(stdout, "No arguments provided!\nInput will default to input.txt\nOutput will default to output.txt\n");
        yyin = fopen("input.txt", "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "Input file not found!\nDefaulting input to factorinal\n[use ctrl+D to exit]\n");
            yyin = stdin;
        }
        yyout = fopen("output.txt", "w");
    }
    if (argc == 2)
    {
        fprintf(stdout, "Input set to \"%s\"\nOutput will default to output.txt\n",argv[1]);

        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "Input file not found!\nDefaulting input to factorinal\n[use ctrl+D to exit]\n");
            yyin = stdin;
        }
        yyout = fopen("output.txt", "w");
    }
    if (argc == 3)
    {
        fprintf(stdout, "Input set to \"%s\"\nOutput set to \"%s\"\n", argv[1], argv[2]);

        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "Input file not found!\nDefaulting input to factorinal\n[use ctrl+D to exit]\n");
            yyin = stdin;
        }
        yyout = fopen(argv[2], "w");
    }
    if (argc > 3)
    {
        fprintf(stdout, "Input set to \"%s\"\nOutput set to \"%s\"\nExtra arguments skipped!\n", argv[1], argv[2]);
        
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "Input file not found!\nDefaulting input to factorinal\n[use ctrl+D to exit]\n");
            yyin = stdin;
        }
        yyout = fopen(argv[2], "w");
    }

    yyparse();

    if (yyin != stdin)
    {
        fclose(yyin);
    }
    fclose(yyout);

    return 0;
}

int yyerror(char const *s)
{
    fprintf(stderr, "%s\n", "HIII");
    return fprintf(stderr, "%s\n", s);
}










