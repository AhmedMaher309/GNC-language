/* ############ Declarations ############ */

/* ### Auxiliary declarations ### */
%{
    #define ENABLE_YACC_DEBUG 0
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
%token <cvalue> TYPE_INT
%token <cvalue> TYPE_FLOAT
%token <cvalue> TYPE_CHAR
%token <cvalue> TYPE_BOOL
%token <cvalue> CONSTANT
%token <cvalue> WHILE
%token <cvalue> FOR
%token <cvalue> DO
%token <cvalue> BREAK
%token <cvalue> CONTINUE
%token <cvalue> IF
%token <cvalue> ELSE
%token <cvalue> ELSEIF
%token <cvalue> SWITCH
%token <cvalue> CASE
%token <cvalue> PLUS
%token <cvalue> MINUS
%token <cvalue> MULT
%token <cvalue> DIV
%token <cvalue> MODULE
%token <cvalue> POWER
%token <cvalue> EQU
%token <cvalue> MORE
%token <cvalue> LESS
%token <cvalue> EQU_EQU
%token <cvalue> MORE_OR_EQU
%token <cvalue> LESS_OR_EQU
%token <cvalue> AND
%token <cvalue> OR
%token <cvalue> NOT
%token <cvalue> OPEN_CURL
%token <cvalue> CLOSE_CURL
%token <cvalue> OPEN_BRAC
%token <cvalue> CLOSE_BRAC
%token <cvalue> SEMICOLON
%token <cvalue> COMMA
%token <cvalue> REPEAT
%token <cvalue> UNTIL
%token <cvalue> VOID
%token <cvalue> IDENTIFIER
%token <cvalue> COMMENT

%type <cvalue> tokens
%type <cvalue> token

%left PLUS MINUS
%left MULT DIV
%nonassoc EQU

%start tokens
 
%%
    /* ############ Rules ############ */
tokens:   tokens token  { fprintf(yyout, "PROCESSED %c!\n", $$), $$ = $2; }
        |               
token:    INTEGER       { fprintf(yyout, "MATCH! %d, len = %d\n", $1, yyleng); $$ = $1; }
        | FLOAT
        | BOOL
        | CHAR
        | TYPE_INT
        | TYPE_FLOAT
        | TYPE_CHAR
        | TYPE_BOOL
        | CONSTANT
        | WHILE
        | FOR
        | DO
        | BREAK
        | CONTINUE
        | IF
        | ELSE
        | ELSEIF
        | SWITCH
        | CASE
        | PLUS
        | MINUS
        | MULT
        | DIV
        | MODULE
        | POWER
        | EQU
        | MORE
        | LESS
        | EQU_EQU
        | MORE_OR_EQU
        | LESS_OR_EQU
        | AND
        | OR
        | NOT
        | OPEN_CURL
        | CLOSE_CURL
        | OPEN_BRAC
        | CLOSE_BRAC
        | SEMICOLON
        | COMMA
        | REPEAT
        | UNTIL
        | VOID
        | IDENTIFIER
        | COMMENT   

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
            fprintf(stderr, "Input file not found!\nDefaulting input to terminal\n[use ctrl+D to exit]\n");
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
            fprintf(stderr, "Input file not found!\nDefaulting input to terminal\n[use ctrl+D to exit]\n");
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
            fprintf(stderr, "Input file not found!\nDefaulting input to terminal\n[use ctrl+D to exit]\n");
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
            fprintf(stderr, "Input file not found!\nDefaulting input to terminal\n[use ctrl+D to exit]\n");
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
    return fprintf(stderr, "%s\n", s);
}