/*/////////////////////// Header Section /////////////////////////////////////////////////*/
%{
#include <stdio.h>

double yylval;

%}



/*//////////////////////////////////Optional Section /////////////////////////////////////*/
%option noyywrap 

TYPE_INT    "int"
TYPE_FLOAT  "float"
TYPE_CHAR   "char"
TYPE_BOOL   "bool"
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*
INTEGER     [-+]?[0-9]+  
FLOAT       [-+]?[0-9]+.[0-9]+ 
BOOL        true|false
CHAR        '.'
CONSTANT    "const"


/* Tokens Definition */
%{
#define INTEGER          1
#define FLOAT            2
#define BOOL             3
#define CHAR             4
#define TYPE_INT         5
#define TYPE_FLOAT       6
#define TYPE_CHAR        7
#define TYPE_BOOL        8
#define CONSTANT         9
#define WHILE            10
#define FOR              11
#define DO               12
#define BREAK            13
#define CONTINUE         14
#define IF               15
#define ELSE             16
#define ELSEIF           17
#define PLUS_OP          18
#define MINUS_OP         19
#define MULT_OP          20
#define DIV_OP           21
#define MODULE_OP        22
#define POWER_OP         23
#define EQU_OP           24
#define MORE_OP          25
#define LESS_OP          26
#define EQU_EQU_OP       27
#define MORE_OR_EQU_OP   27
#define LESS_OR_EQU_OP   29
#define OPEN_CURL        30
#define CLOSE_CURL       31
#define OPEN_BRAC        32
#define CLOSE_BRAC       33
#define SEMICOLON        34
#define COMMA            35
#define REPEAT           36
#define UNTIL            37
#define VOID             38
#define IDENTIFIER       39
%}



/*////////////////////// Rules section //////////////////////////////////////////////////////*/
%%  
  /* Variable tokens section */
{INTEGER}                                               { yylval = atoi(yytext); return INTEGER; }
{FLOAT}                                                 { yylval = atof(yytext); return FLOAT; }
{BOOL}                                                  { yylval = (strcmp(yytext, "true") == 0) ? 1 : 0; return BOOL; }
{CHAR}                                                  { yylval = yytext[1]; return CHAR; } 

 /* Data type tokens */
{TYPE_INT}                                              { return TYPE_INT; }
{TYPE_FLOAT}                                            { return TYPE_FLOAT; }
{TYPE_CHAR}                                             { return TYPE_CHAR; }
{TYPE_BOOL}                                             { return TYPE_BOOL; }
{CONSTANT}                                              { return CONSTANT; }

 /* Loops and breaks*/
 while                                                  { return WHILE;}
 for                                                    { return FOR;}
 do                                                     { return DO;}
 break                                                  { return BREAK;}
 continue                                               { return CONTINUE;}
 
 /* if, else, elseif */
 if                                                     { return IF;}
 else                                                   { return ELSE;}
 elseif                                                 { return ELSEIF;}

 /* mathematical operators */
"+"                                                     { return PLUS_OP; }
"-"                                                     { return MINUS_OP; }
"*"                                                     { return MULT_OP; }
"/"                                                     { return DIV_OP; }
"%"                                                     { return MODULE_OP; }
"^"                                                     { return POWER_OP; }
"="                                                     { return EQU_OP; }

 /* logical operators */
">"                                                     { return MORE_OP; }
"<"                                                     { return LESS_OP; }
"=="                                                    { return EQU_EQU_OP; }
"<="                                                    { return MORE_OR_EQU_OP; }
">="                                                    { return LESS_OR_EQU_OP; }

 /* scopes */
"{"                                                     { return OPEN_CURL; }
"}"                                                     { return CLOSE_CURL; }
"("                                                     { return OPEN_BRAC; }
")"                                                     { return CLOSE_BRAC; }

";"                                                     { return SEMICOLON; }
","                                                     { return COMMA; }

 /* Repeat until*/
"repeat"                                                { return REPEAT; }
"until"                                                 { return UNTIL; }

 /* functions keywords */
"void"                                                  { return VOID; }

{IDENTIFIER}                                            { return IDENTIFIER; }
 
[ \t\n]                                                 { /* ignore whitespace */ }
.                                                       { printf("invalid character\n"); }

%%

/*/////////////////////// Optional Supporting Code Seciton//////////////////////////////////////*/
/*
any optional C supporting code
*/

/*///////////////////////////////////// Main Secton //////////////////////////////////////////*/
int main() {
    int token;
    while ((token = yylex()) != 0)
    {
        printf("Token: %d\n", token);
    }
    return 0;
}

