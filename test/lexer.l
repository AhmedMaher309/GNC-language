/*/////////////////////// Header Section /////////////////////////////////////////////////*/
%{
#include <stdio.h>

double yylval;
%}


/*////////////////////////////////// Optional Section /////////////////////////////////////*/
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
#define ENUM             46
#define IF               15
#define ELSE             16
#define ELSEIF           17
#define SWITCH           18
#define CASE             19
#define PLUS             20
#define MINUS            21
#define MULT             22
#define DIV              23
#define MODULE           24
#define POWER            25
#define EQU              26
#define MORE             27
#define LESS             28
#define EQU_EQU          29
#define MORE_OR_EQU      30
#define LESS_OR_EQU      31
#define AND              32
#define OR               33
#define NOT              34
#define OPEN_CURL        35
#define CLOSE_CURL       36
#define OPEN_BRAC        37
#define CLOSE_BRAC       38
#define SEMICOLON        39
#define COMMA            40
#define REPEAT           41
#define UNTIL            42
#define VOID             43
#define IDENTIFIER       44
#define COMMENT          45

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

enum                                                   { return ENUM; }
     /* Loops and breaks*/
while                                                   { return WHILE; }
for                                                     { return FOR; }
do                                                      { return DO; }
break                                                   { return BREAK; }
continue                                                { return CONTINUE; }
 
 /* if, else, elseif, switch cases */
if                                                      { return IF; }
else                                                    { return ELSE; }
elseif                                                  { return ELSEIF; }
switch                                                  { return SWITCH; }
case                                                    { return CASE; }

 /* mathematical operators */
"+"                                                     { return PLUS; }
"-"                                                     { return MINUS; }
"*"                                                     { return MULT; }
"/"                                                     { return DIV; }
"%"                                                     { return MODULE; }
"^"                                                     { return POWER; }
"="                                                     { return EQU; }

 /* comparison operators */
">"                                                     { return MORE; }
"<"                                                     { return LESS; }
"=="                                                    { return EQU_EQU; }
">="                                                    { return MORE_OR_EQU; }
"<="                                                    { return LESS_OR_EQU; }

 /* logical operators*/
"&&"                                                    { return AND; }
"||"                                                    { return OR; }
"!"                                                     { return NOT; }

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

 /* comments */
"/*".*"*/"                                              { return COMMENT; }

{IDENTIFIER}                                            { return IDENTIFIER; }
 
[ \t\n]                                                 { /* ignore whitespace */ }
.                                                       { printf("invalid character\n"); }

%%

/* /////////////////////// Optional Supporting Code Seciton ////////////////////////////////////// */
/*
any optional C supporting code
*/

/* ///////////////////////////////////// Main Secton //////////////////////////////////////// */
int main() {
    int token;
    while ((token = yylex()) != 0)
    {
        printf("Token: %d\n", token);
    }
    return 0;
}
