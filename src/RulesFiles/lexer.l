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
{INTEGER}                                               { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; yylval->ivalue.value = strdup(yytext); return INTEGER; }
{FLOAT}                                                 { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; yylval->fvalue.value = strdup(yytext); return FLOAT; }
{BOOL}                                                  { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; if (strcmp(yytext, "true") == 0) {yylval->bvalue.value = "1";} else {yylval->bvalue.value = "0";} return BOOL; }
{CHAR}                                                  { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; yylval->cvalue.value = strdup(yytext); return CHAR; }
{STRING}                                                { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; yylval->svalue.value = strdup(yytext); return STRING; }

    /* Data type tokens */
{TYPE_INT}                                              { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return TYPE_INT; }
{TYPE_FLOAT}                                            { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return TYPE_FLOAT; }
{TYPE_CHAR}                                             { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return TYPE_CHAR; }
{TYPE_BOOL}                                             { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return TYPE_BOOL; }
{TYPE_STRING}                                           { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return TYPE_STRING; }
{TYPE_VOID}                                             { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return TYPE_VOID; }
{CONSTANT}                                              { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return CONSTANT; }

"enum"                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return ENUM; }
    /* Loops and breaks */
"while"                                                   { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return WHILE; }
"for"                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return FOR; }
"break"                                                   { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return BREAK; }
 
    /* if, else, elseif, switch cases */
"if"                                                      { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return IF; }
"else"                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return ELSE; }
"switch"                                                  { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return SWITCH; }
"case"                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return CASE; }
"default"                                                 { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return DEFAULT; }
"return"                                                  { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return RETURN; }


     /* printing */
"print"                                                   { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return PRINT; }

    /* mathematical operators */
"+"                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return PLUS; }
"-"                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return MINUS; }
"*"                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return MULT; }
"/"                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return DIV; }
"%"                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return MODULE; }
"^"                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return POWER; }
"="                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return EQU; }

    /* comparison operators */
">"                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return MORE; }
"<"                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return LESS; }
"=="                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return EQU_EQU; }
">="                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return MORE_OR_EQU; }
"<="                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return LESS_OR_EQU; }

    /* others */ /* TODO: include these operators*/
"!="                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return NOT_EQU; }
"++"                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return INC; }
"--"                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return DEC; }

    /* logical operators */
"&&"                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return AND; }
"||"                                                    { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return OR; }
"!"                                                     { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return NOT; }

    /* scopes and special chars*/
[();{}:,]                                               { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return *yytext; }

    /* repeat until */
"repeat"                                                { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return REPEAT; }
"until"                                                 { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return UNTIL; }

    /* functions keywords */

    /* comments */
"/*".*"*/"                                              { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; return COMMENT; }

{IDENTIFIER}                                            { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; yylval->gvalue.type = "ID"; yylval->gvalue.value = strdup(yytext); fprintf(yyout, "Identifier Token: %s\n", yytext); return IDENTIFIER;}
 
[ \t]                                                   { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; /* ignore whitespace */; }
[\r\n]                                                  { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column = 1; yylloc->last_line += 1; /* ignore newlines */; }

.                                                       { yylloc->first_column = yylloc->last_column; yylloc->first_line = yylloc->last_line; yylloc->last_column += yyleng; fprintf(yyout, "invalid character\n"); }

%%
/* ############ Auxiliary Functions ############ */

void lex_init(void*& scanner)
{
    yylex_init(&scanner);

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

    yylex_destroy(scanner);
}
