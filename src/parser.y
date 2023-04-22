/* ############ Declarations ############ */

/* ### Auxiliary declarations ### */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    extern int yylex(void);
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

%left PLUS, MINUS
%left MULT, DIV
%nonassoc EQU

%start tokens
 
%%
/* ############ Rules ############ */
tokens:   tokens token 
        |               { /*NOTIHNG*/; };
token:    INTEGER
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
        | COMMENT   { printf("MATCH!"); };

%%
/* ############ Auxiliary Functions ############ */

int main(int argc, char **argv) { 

    yyparse();
    return 0;
}