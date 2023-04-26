/* ############ Declarations ############ */

/* ### Auxiliary declarations ### */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
extern YYSTYPE yylval;
%}

/* ### Regular Definitions ### */
%option noyywrap

TYPE_INT    "int"
TYPE_FLOAT  "float"
TYPE_CHAR   "char"
TYPE_BOOL   "bool"
TYPE_VOID   "void"
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*
INTEGER     [-+]?[0-9]+
FLOAT       [-+]?[0-9]+.[0-9]+
BOOL        true|false
CHAR        '.'
CONSTANT    "const"

%%
    /* ############ Rules ############ */

    /* Variable tokens section */
{INTEGER}                                               { yylval.ivalue = atoi(yytext); return INTEGER; }
{FLOAT}                                                 { yylval.fvalue = atof(yytext); return FLOAT; }
{BOOL}                                                  { yylval.cvalue = (strcmp(yytext, "true") == 0) ? 1 : 0; return BOOL; }
{CHAR}                                                  { yylval.cvalue = yytext[1]; return CHAR; } 

    /* Data type tokens */
{TYPE_INT}                                              { return TYPE_INT; }
{TYPE_FLOAT}                                            { return TYPE_FLOAT; }
{TYPE_CHAR}                                             { return TYPE_CHAR; }
{TYPE_BOOL}                                             { return TYPE_BOOL; }
{TYPE_VOID}                                             { return TYPE_VOID; }
{CONSTANT}                                              { return CONSTANT; }

enum                                                    { return ENUM; }
    /* Loops and breaks */
while                                                   { return WHILE; }
for                                                     { return FOR; }
break                                                   { return BREAK; }
continue                                                { return CONTINUE; }
 
    /* if, else, elseif, switch cases */
if                                                      { return IF; }
else                                                    { return ELSE; }
elseif                                                  { return ELSEIF; }
switch                                                  { return SWITCH; }
case                                                    { return CASE; }
default                                                 { return DEFAULT; }
return                                                  { return RETURN; }

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

    /* others */ /* TODO: include these operators*/
"!="                                                    { return NOT_EQU; }
"++"                                                    { return INC; }
"--"                                                    { return DEC; }

    /* logical operators */
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
":"                                                     { return COLON; }

    /* repeat until */
"repeat"                                                { return REPEAT; }
"until"                                                 { return UNTIL; }

    /* functions keywords */

    /* comments */
"/*".*"*/"                                              { return COMMENT; }

{IDENTIFIER}                                            { fprintf(yyout, "Identifier Token: %s\n", yytext); return IDENTIFIER; }
 
[ \t\r\n]                                               { /* ignore whitespace */; }
.                                                       { fprintf(yyout, "invalid character\n"); }

%%
/* ############ Auxiliary Functions ############ */

