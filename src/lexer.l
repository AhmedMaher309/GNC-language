/* ############ Declarations ############ */
/* ### Auxiliary declarations ### */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
extern FILE* io_readfile();
extern FILE* io_writefile();
extern int io_closefile(FILE*);
%}

/* ### Regular Definitions ### */
%option noyywrap
%option reentrant
%option bison-bridge
%option bison-locations
%option yylineno

TYPE_INT    "int"
TYPE_FLOAT  "float"
TYPE_CHAR   "char"
TYPE_BOOL   "bool"
TYPE_STRING "string"
TYPE_VOID   "void"
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*
INTEGER     [-+]?[0-9]+
FLOAT       [-+]?[0-9]+.[0-9]+
BOOL        true|false
CHAR        \'.?\'
STRING      \".*\"
CONSTANT    "const"

%%
    /* ############ Rules ############ */

    /* Variable tokens section */
{INTEGER}                                               { yylval->ivalue.value = strdup(yytext); return INTEGER; }
{FLOAT}                                                 { yylval->fvalue.value = strdup(yytext); return FLOAT; }
{BOOL}                                                  { if (strcmp(yytext, "true") == 0) {yylval->bvalue.value = "1";} else {yylval->bvalue.value = "0";} return BOOL; }
{CHAR}                                                  { yylval->cvalue.value = strdup(yytext); return CHAR; }
{STRING}                                                { yylval->svalue.value = strdup(yytext); return STRING; }

    /* Data type tokens */
{TYPE_INT}                                              { return TYPE_INT; }
{TYPE_FLOAT}                                            { return TYPE_FLOAT; }
{TYPE_CHAR}                                             { return TYPE_CHAR; }
{TYPE_BOOL}                                             { return TYPE_BOOL; }
{TYPE_STRING}                                           { return TYPE_STRING; }
{TYPE_VOID}                                             { return TYPE_VOID; }
{CONSTANT}                                              { return CONSTANT; }

"enum"                                                    { return ENUM; }
    /* Loops and breaks */
"while"                                                   { return WHILE; }
"for"                                                     { return FOR; }
"break"                                                   { return BREAK; }
 
    /* if, else, elseif, switch cases */
"if"                                                      { return IF; }
"else"                                                    { return ELSE; }
"switch"                                                  { return SWITCH; }
"case"                                                    { return CASE; }
"default"                                                 { return DEFAULT; }
"return"                                                  { return RETURN; }


     /* printing */
"print"                                                   { return PRINT; }

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

    /* scopes and special chars*/
[();{}:,]                                               { return *yytext; }

    /* repeat until */
"repeat"                                                { return REPEAT; }
"until"                                                 { return UNTIL; }

    /* functions keywords */

    /* comments */
"/*".*"*/"                                              { return COMMENT; }

{IDENTIFIER}                                            { yylval->gvalue.type = "ID"; yylval->gvalue.value = strdup(yytext); fprintf(yyout, "Identifier Token: %s\n", yytext); return IDENTIFIER;}
 
[ \t\r\n]                                               { /* ignore whitespace */; }
.                                                       { fprintf(yyout, "invalid character\n"); }

%%
/* ############ Auxiliary Functions ############ */

void lex_init(void*& scanner)
{
    yylex_init (&scanner);

    FILE* file;

    fprintf(stdout, "Getting input file. Leave empty for default input (stdin)\n");
    file = io_readfile();
    if (file != NULL)
    {
        fprintf(stdout, "Successfully opened input file\n");
        yyset_in(file, scanner);
    }
    else
    {
        fprintf(stderr, "Error opening input file\n");
        fprintf(stdout, "Defaulting input to stdin\n");
        yyset_in(stdin, scanner);;
    }

    fprintf(stdout, "Getting output file. Leave empty for default output (stdout)\n");
    file = io_writefile();
    if (file != NULL)
    {
        fprintf(stdout, "Successfully opened output file\n");
        yyset_out(file, scanner);
    }
    else
    {
        fprintf(stderr, "Error opening output file\n");
        fprintf(stdout, "Defaulting output to stdout\n");
        yyset_out(stdout, scanner);
    }    
}

void lex_deinit(void*& scanner)
{
    if (yyget_in(scanner) != stdin)
    {
        if (io_closefile(yyget_in(scanner)) == 0)
        {
            fprintf(stdout, "Successfully closed input file\n");
        }
        else
        {
            fprintf(stderr, "Error closing input file\n");
        }
    }

    if (yyget_out(scanner) != stdout)
    {
        if (io_closefile(yyget_out(scanner)) == 0)
        {
            fprintf(stdout, "Successfully closed output file\n");
        }
        else
        {
            fprintf(stderr, "Error closing output file\n");
        }
    }

    yylex_destroy (scanner);
}
