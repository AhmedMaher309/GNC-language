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
%token IF ELSE ELSEIF
%token SWITCH CASE DEFAULT
%token MINUS MULT PLUS DIV MODULE POWER EQU INC DEC
%token MORE LESS EQU_EQU MORE_OR_EQU LESS_OR_EQU NOT_EQU
%token AND OR NOT
%token OPEN_CURL CLOSE_CURL OPEN_BRAC CLOSE_BRAC SEMICOLON COMMA COLON
%token REPEAT UNTIL
%token IDENTIFIER
%token COMMENT

%type <cvalue> tokens
%type <cvalue> token

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

%start tokens
 
%%
    /* ############ Rules ############ */
tokens:   tokens token
        | token
        ;

token:  enum_declaration
        | function_prototype SEMICOLON
        | function_declaration
        | in_scope_statement
        ;

in_scope_statements: in_scope_statement 
                    |in_scope_statements in_scope_statement 

                    ;

in_scope_statement:
        variable_declaration SEMICOLON
        | constant_declaration SEMICOLON
        | expression SEMICOLON
        | assignment SEMICOLON
        /*| function_call SEMICOLON*/
        | if_statement
        | while_statement
        | for_statement
        | switch_statement
        | repeat_until_statement SEMICOLON
        | enum_variable_declaration SEMICOLON
        | COMMENT
        | BREAK SEMICOLON
        | CONTINUE SEMICOLON /*****//* to add them spcefically in for and while loops*/
;

/*
enum week_days {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY = 5,
    THURSDAY,
    FRIDAY,
    SATURDAY = 10,
    SUNDAY
}; 
*//*****/
/*****/ /* TODO: add support for return statement */

in_enum_statement:
    IDENTIFIER EQU INTEGER
    | IDENTIFIER 
    | IDENTIFIER EQU INTEGER COMMA in_enum_statement
    | IDENTIFIER COMMA in_enum_statement
    ;

enum_variable_declaration: ENUM IDENTIFIER IDENTIFIER EQU IDENTIFIER; /* enum colors my_color = RED; */

type: TYPE_INT
    | TYPE_FLOAT
    | TYPE_CHAR
    | TYPE_BOOL 
    | TYPE_VOID;

parameter_or_empty: OPEN_BRAC parameters CLOSE_BRAC 
		  | OPEN_BRAC CLOSE_BRAC ;

parameters: type IDENTIFIER 
	  | type IDENTIFIER COMMA parameters;

argument_or_empty:  OPEN_BRAC arguments CLOSE_BRAC 
		 | OPEN_BRAC CLOSE_BRAC ;

arguments: expression 
	 | expression COMMA arguments;

enum_declaration: ENUM IDENTIFIER OPEN_CURL in_enum_statement CLOSE_CURL SEMICOLON;

function_prototype: type IDENTIFIER parameter_or_empty;

function_declaration: function_prototype OPEN_CURL in_scope_statements CLOSE_CURL;

variable_declaration: type IDENTIFIER 
		    | type IDENTIFIER EQU expression;

constant_declaration: CONSTANT type IDENTIFIER EQU constant_right_hand_side; 

expression: operand 
            | expression PLUS expression 
            | expression MINUS expression 
            | expression MULT expression 
            | expression DIV expression 
            | expression MODULE expression 
            | expression POWER expression
            | operand INC
            | operand DEC
            | expression LESS_OR_EQU expression
            | expression MORE_OR_EQU expression 
            | expression LESS expression 
            | expression MORE expression 
            | expression EQU_EQU expression
            | expression AND expression 
            | expression OR expression 
            | expression NOT_EQU expression
            | NOT expression  
            | OPEN_BRAC expression CLOSE_BRAC
            ;

operand: IDENTIFIER 
       | constant_right_hand_side 
       | function_call ;

constant_right_hand_side: INTEGER 
			| FLOAT 
                        | CHAR 
                        | BOOL ;

assignment: IDENTIFIER EQU expression;

function_call: IDENTIFIER argument_or_empty;

statements_or_empty: OPEN_CURL in_scope_statements CLOSE_CURL | OPEN_CURL CLOSE_CURL ;

if_statement: IF OPEN_BRAC expression CLOSE_BRAC statements_or_empty
              | IF OPEN_BRAC expression CLOSE_BRAC   statements_or_empty ELSE   statements_or_empty 
              | IF OPEN_BRAC expression CLOSE_BRAC OPEN_CURL in_scope_statements CLOSE_CURL
                elseif_statment
                ELSE OPEN_CURL in_scope_statements CLOSE_CURL;

elseif_statment: ELSEIF OPEN_BRAC expression CLOSE_BRAC   statements_or_empty 
                 | elseif_statment ELSEIF OPEN_BRAC expression CLOSE_BRAC OPEN_CURL in_scope_statements CLOSE_CURL;

while_statement: WHILE OPEN_BRAC expression CLOSE_BRAC OPEN_CURL in_scope_statements CLOSE_CURL;

for_statement: FOR OPEN_BRAC counter_variable SEMICOLON expression SEMICOLON expression CLOSE_BRAC OPEN_CURL in_scope_statements CLOSE_CURL; /*****//* specific expression for first expression?*/

counter_variable: variable_declaration 
		| assignment;

switch_statement: SWITCH OPEN_BRAC expression CLOSE_BRAC OPEN_CURL in_switch_statement CLOSE_CURL;

in_switch_statement: cases
		   | cases default;

cases: case 
     |case cases;

case: CASE operand COLON  in_scope_statements BREAK SEMICOLON;

default: DEFAULT COLON in_scope_statements BREAK SEMICOLON;

repeat_until_statement: REPEAT   statements_or_empty UNTIL OPEN_BRAC expression CLOSE_BRAC;


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
