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
%token <ivalue> BOOL
%token <cvalue> CHAR
%token TYPE_INT
%token TYPE_FLOAT
%token TYPE_CHAR
%token TYPE_BOOL
%token CONSTANT
%token WHILE
%token FOR
%token DO
%token BREAK
%token CONTINUE
%token IF
%token ELSE
%token ELSEIF
%token SWITCH
%token CASE
%token PRINT
%token PLUS
%token MINUS
%token MULT
%token DIV
%token MODULE
%token POWER
%token EQU
%token MORE
%token LESS
%token EQU_EQU
%token MORE_OR_EQU
%token LESS_OR_EQU
%token AND
%token OR
%token NOT
%token OPEN_CURL
%token CLOSE_CURL
%token OPEN_BRAC
%token CLOSE_BRAC
%token SEMICOLON
%token COMMA
%token REPEAT
%token UNTIL
%token VOID
%token IDENTIFIER
%token COMMENT

%type <ivalue> itoken
%type <fvalue> ftoken
%type <cvalue> ctoken

%left PLUS MINUS
%left MULT DIV
%nonassoc EQU

%start tokens
 
%%
    /* ############ Rules ############ */
tokens:   tokens token  { fprintf(yyout, "PROCESSED A TOKEN!\n"); }
        | /*empty*/
        
token:    itoken       { fprintf(yyout, "MATCHED INT! %d, len = %d\n", $1, yyleng); }
        | ftoken       { fprintf(yyout, "MATCHED FLOAT! %f, len = %d\n", $1, yyleng); }
        | ctoken       { fprintf(yyout, "MATCHED CHAR! %c, len = %d\n", $1, yyleng); }
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
        | PRINT
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

itoken:   INTEGER       { $$ = $1; }
        | BOOL          { $$ = $1; }

ftoken:   FLOAT         { $$ = $1; }

ctoken:   CHAR          { $$ = $1; }


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