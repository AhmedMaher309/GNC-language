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
    #include "../Scopes/scopestack.h"
    #include "../QuadGenerator/quadgenerator.h"
    #include "../FunctionTable/functiontable.h"
    #include "../semanticAnalysis/SemanticAnalyser.h"
    extern void lex_init(void*&);
    extern void lex_deinit(void*&);
    extern int yylex(union YYSTYPE*, struct YYLTYPE*, void*);
    int yyerror(struct YYLTYPE*, void*, const char*);

    void* scanner;
    extern void yyset_debug(int, void*);
    extern int yyget_leng(void*);

    ScopeStack scope;
    QuadGenerator generator;
    SymbolTable* table = scope.getGlobals();

    FunctionTable functions;
    Function* func = NULL;

    SemanticAnalyser symanticAnalyser;
%}

/* ### Regular Definitions ### */
%define api.pure full
%lex-param {void* scanner}
%parse-param {void* scanner}

%locations
%define parse.error custom

%union {

    struct 
    {
        const char* type;
        const char* value;
    } ivalue;

    struct 
    {
        const char* type;
        const char* value;
    } fvalue;

    struct 
    {
        const char* type;
        const char* value;
    } cvalue;

    struct 
    {
        const char* type;
        const char* value;
    } bvalue;

    struct 
    {
        const char* type;
        const char* value;
    } svalue;

    struct 
    {
        const char* type;
        const char* value;
    } gvalue;

   //TODO node type will be put here to be the type of any scopes tokens
};

%token <ivalue> INTEGER
%token <fvalue> FLOAT
%token <bvalue> BOOL
%token <cvalue> CHAR
%token <svalue> STRING
%token <gvalue> TYPE_INT TYPE_FLOAT TYPE_CHAR TYPE_BOOL TYPE_STRING
%token TYPE_VOID
%token CONSTANT
%token ENUM
%token WHILE FOR BREAK
%token IF ELSE RETURN
%token SWITCH CASE DEFAULT
%token PRINT
%token MINUS MULT PLUS DIV MODULE POWER EQU INC DEC
%token MORE LESS EQU_EQU MORE_OR_EQU LESS_OR_EQU NOT_EQU
%token AND OR NOT
%token REPEAT UNTIL
%token <gvalue> IDENTIFIER
%token COMMENT

%type <gvalue> type
%type <gvalue> arthimetic_expr
%type <gvalue> compare_and_logic_expr
%type <gvalue> expr_terminal
%type <gvalue> rvalue
%type <gvalue> func_sgnt
%type <gvalue> ret_func_sgnt
%type <gvalue> func_call
%type <gvalue> enum_define

/*to specify the precedence and associativity of operators*/
%left EQU_EQU NOT_EQU MORE LESS MORE_OR_EQU LESS_OR_EQU
%left PLUS MINUS
%left MULT DIV
%left MODULE
%right POWER
%right INC DEC
%right EQU 
%nonassoc OR 
%nonassoc AND
%nonassoc NOT 

%start program 

%% 
    /* ############ Rules ############ */

 /*///////////// the most general rule (program rule)////////////*/

program: program stmt
         | stmt
         ;


 /*////////////////////////////////////////////////////////// second degreee ////////////////////////////////////////////////////////////////*/

stmt: genn_stmt // {printf("genn_stmt\n");}
      | func_stmt
      | print_stmt
      | for_stmt
      | if_stmt
      | enum_stmt
      | while_stmt
      | repeat_stmt
      | switch_stmt
      | COMMENT
      ;

stmt_list: stmt             
         | stmt_list stmt   
         ;

func_stmt_list: stmt_list RETURN arthimetic_expr ';'      
                |  RETURN arthimetic_expr ';'
                ;

break_stmt_list: stmt_list BREAK ';' 
               | BREAK ';' 
               ;


 /*/////////////////////////////////////////////////////////////// third degree ///////////////////////////////////////////////////////////////////*/

genn_stmt:  type IDENTIFIER ';'                         {
                                                            Symbol* sym = table->getSymbolObjectbyName($2.value);
                                                            if (sym == NULL)
                                                            {
                                                                Symbol* sym = new Symbol($2.value,$1.value);
                                                                table->addSymbolInTable(sym); 

                                                                const char* name = generator.addAssignment(sym);
                                                                generator.addQuad("ALLOC",$2.value,"",name);
                                                            }
                                                            else
                                                            {
                                                                symanticAnalyser.raiseError("Variable is defined before", @1.first_line);
                                                            }
                                                        }

           | type IDENTIFIER EQU func_call ';'          {  
                                                            Symbol* sym = table->getSymbolObjectbyName($2.value);
                                                            if (sym == NULL)
                                                            {
                                                                Symbol* sym = new Symbol($2.value,$1.value);
                                                                const char* name = generator.addAssignment(sym);
                                                                generator.addQuad("ALLOC",$2.value,"",name);
                                                                generator.addQuad("ASSIGN",$4.value,"",name);
                                                            }
                                                        }

           | IDENTIFIER EQU func_call ';'

           | CONSTANT type IDENTIFIER EQU rvalue ';'    {
                                                            

                                                            Symbol* sym = table->getSymbolObjectbyName($3.value);
                                                            if (sym == NULL)
                                                            {
                                                                Symbol* sym = new Symbol($3.value, $2.value);
                                                                sym->setIsInitialised(1); 
                                                                sym->setConstant(1);
                                                                if(symanticAnalyser.checkType(sym->getVarType(), $5.type)){
                                                                    table->addSymbolInTable(sym);
                                                                    table->modifySymbolInTable(sym,symanticAnalyser.TypeConversion(sym->getVarType(), $5.type, $5.value));

                                                                        const char* name = generator.addAssignment(sym);
                                                                        generator.addQuad("CONST_ALLOC",$3.value,"",name);
                                                                        generator.addQuad("ASSIGN",$5.value,"",name);
                                                                }
                                                                else
                                                                {
                                                                    symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                }     
                                                            }
                                                            else
                                                            {
                                                                symanticAnalyser.raiseError("Variable is defined before", @1.first_line);
                                                            }
                                                        }

           | IDENTIFIER EQU arthimetic_expr ';'                    {
                                                            SymbolTable* table = scope.getSymbolTableFromStack($1.value);
                                                            if (table != NULL)
                                                            {
                                                                Symbol* sym = table->getSymbolObjectbyName($1.value);

                                                                const char* exprValue = generator.getTemp($3.value);
                                                                const char* exprType = $3.type;

                                                                if (strcmp(exprType,"ID") == 0)
                                                                {
                                                                    SymbolTable* exprtable = scope.getSymbolTableFromStack(exprValue);
                                                                    if (exprtable != NULL)
                                                                    {
                                                                        Symbol* exprsym = exprtable->getSymbolObjectbyName(exprValue);
                                                                        exprValue = generator.getAssignment(exprsym);
                                                                        exprType = exprsym->getVarTypeAsCStr();
                                                                    }
                                                                    else
                                                                    {
                                                                        symanticAnalyser.raiseError("undefined variable", @1.first_line);
                                                                    }
                                                                }

                                                                if(strcmp(exprType,"ID") != 0)
                                                                {
                                                                    if(sym->checkConstant())
                                                                    {
                                                                        symanticAnalyser.raiseError("Constant cannot be reassigned", @1.first_line);
                                                                    }
                                                                    else if(symanticAnalyser.checkType(sym->getVarType(), exprType)){
                                                                        table->modifySymbolInTable(sym,symanticAnalyser.TypeConversion(sym->getVarType(), exprType, exprValue));
                                                                        generator.addQuad("ASSIGN",$3.value,"",generator.getAssignment(sym));
                                                                    }
                                                                    else
                                                                    {
                                                                        symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                    }     
                                                                }
                                                            }
                                                            else
                                                            {
                                                                symanticAnalyser.raiseError("undefined variable", @1.first_line); 
                                                            }
                                                            generator.clearTemps();
                                                        }

           | type IDENTIFIER EQU arthimetic_expr ';'               { 
                                                            Symbol* sym = table->getSymbolObjectbyName($2.value);
                                                            if (sym == NULL)
                                                            {
                                                                Symbol* sym = new Symbol($2.value,$1.value);

                                                                const char* exprValue = generator.getTemp($4.value);
                                                                const char* exprType = $4.type;

                                                                if (strcmp(exprType,"ID") == 0)
                                                                {
                                                                    SymbolTable* exprtable = scope.getSymbolTableFromStack(exprValue);
                                                                    if (exprtable != NULL)
                                                                    {
                                                                        Symbol* exprsym = exprtable->getSymbolObjectbyName(exprValue);
                                                                        exprValue = generator.getAssignment(exprsym);
                                                                        exprType = exprsym->getVarTypeAsCStr();
                                                                    }
                                                                    else
                                                                    {
                                                                        symanticAnalyser.raiseError("undefined variable", @1.first_line);
                                                                    }
                                                                }

                                                                if (strcmp(exprType,"ID") != 0)
                                                                {    
                                                                    if (symanticAnalyser.checkType(sym->getVarType(), exprType)) {
                                                                        sym->setIsInitialised(1); 
                                                                        table->addSymbolInTable(sym); 
                                                                        table->modifySymbolInTable(sym,symanticAnalyser.TypeConversion(sym->getVarType(), exprType, exprValue));

                                                                        const char* name = generator.addAssignment(sym);
                                                                        generator.addQuad("ALLOC",$2.value,"",name);
                                                                        generator.addQuad("ASSIGN",$4.value,"",name);
                                                                    }  
                                                                    else
                                                                    {
                                                                        symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                    }                                               
                                                                }
                                                            }
                                                            else
                                                            {
                                                                symanticAnalyser.raiseError("Variable is defined before", @1.first_line);
                                                            }
                                                            generator.clearTemps();
                                                        }
           ;


func_stmt: func_proto
	       | func_define
           | func_call
           ;


print_stmt: PRINT '(' arthimetic_expr ')' ';'
            ;


for_stmt: for_proto
	      | for_define
          ;

if_stmt: if_proto
         | if_define
         ;

enum_stmt: enum_declare
	  | enum_define
           ;


while_stmt: while_proto
           | while_define
           ;
           
repeat_stmt: REPEAT scope_begin stmt_list scope_end UNTIL '(' compare_and_logic_expr ')' ';'              { 
                                                                                            table = scope.removeScope("repeat");
                                                                                            generator.endScope("repeat"); 
                                                                                        }

                  | REPEAT scope_begin scope_end UNTIL '(' compare_and_logic_expr ')' ';'                 { 
                                                                                            table = scope.removeScope("repeat");
                                                                                            generator.endScope("repeat"); 
                                                                                        }
                  ;
                  
switch_stmt:   SWITCH '(' IDENTIFIER ')' scope_begin case_list case_default scope_end   { 
                                                                                            table = scope.removeScope("switch");
                                                                                            generator.endScope("switch"); 
                                                                                        }

                | SWITCH '(' IDENTIFIER ')' scope_begin case_default scope_end          { 
                                                                                            table = scope.removeScope("switch");
                                                                                            generator.endScope("switch"); 
                                                                                        }
                ;


 /*/////////////////////////////////////////////////////////////////// forth degree //////////////////////////////////////////////////////////////////////////////*/


func_proto: func_sgnt parameters ';'                                                    { 
                                                                                            functions.addFunctionInTable(func); func = NULL; 
                                                                                        }

          | ret_func_sgnt parameters ';'                                                { 
                                                                                            functions.addFunctionInTable(func); func = NULL; 
                                                                                        }
          ;

func_define: func_sgnt parameters scope_begin stmt_list scope_end                       { 
                                                                                            table = scope.removeScope($1.value);
                                                                                            generator.endScope($1.value); 
                                                                                            func->setIsDefined(1); 
                                                                                            functions.addFunctionInTable(func); 
                                                                                            func = NULL; 
                                                                                        }

           | ret_func_sgnt parameters scope_begin func_stmt_list scope_end              { 
                                                                                            table = scope.removeScope($1.value);
                                                                                            generator.endScope($1.value); 
                                                                                            func->setIsDefined(1); 
                                                                                            functions.addFunctionInTable(func); 
                                                                                            func = NULL; 
                                                                                        }
           ;
        
func_call: IDENTIFIER '(' arthimetic_expr_list ')'  ';'                                              { /*Check function table to make sure function exists and correct parameters*/ }
          ;                                               



for_proto: FOR '(' IDENTIFIER EQU arthimetic_expr ';' compare_and_logic_expr ';' IDENTIFIER EQU arthimetic_expr ')' ';'
           ;

for_define: FOR '(' IDENTIFIER EQU arthimetic_expr ';' compare_and_logic_expr ';' IDENTIFIER EQU arthimetic_expr ')' scope_begin stmt_list scope_end                   {
                                                                                                                                    table = scope.removeScope("for");
                                                                                                                                    generator.endScope("for");
                                                                                                                                }

	        | FOR '(' IDENTIFIER EQU arthimetic_expr ';' compare_and_logic_expr ';' IDENTIFIER EQU arthimetic_expr ')' scope_begin break_stmt_list scope_end           {
                                                                                                                                    table = scope.removeScope("for");
                                                                                                                                    generator.endScope("for");
                                                                                                                                }

            ;


if_proto: IF '(' compare_and_logic_expr ')' ';'
        ;

if_define: if_scope 
         | if_scope else_scope
         ;

if_scope: IF '(' compare_and_logic_expr ')' scope_begin stmt_list scope_end           {
                                                                                table = scope.removeScope("if");
                                                                                generator.endScope("if");
                                                                                printf("if\n");
                                                                            }

        | IF '(' compare_and_logic_expr ')' scope_begin scope_end                             {
                                                                                table = scope.removeScope("if");
                                                                                generator.endScope("if");
                                                                                printf("if\n");
                                                                            }
        ;

else_scope: ELSE scope_begin stmt_list scope_end                            {
                                                                                table = scope.removeScope("else");
                                                                                generator.endScope("else");
                                                                            }

          | ELSE scope_begin scope_end                                      {
                                                                                table = scope.removeScope("else");
                                                                                generator.endScope("else");
                                                                            }
          | ELSE ';'
          ;

enum_declare: ENUM IDENTIFIER scope_begin enum_list scope_end ';'           {
                                                                                table = scope.removeScope("enum");
                                                                                generator.endScope("enum");
                                                                            }
            ;

enum_define: ENUM IDENTIFIER IDENTIFIER EQU IDENTIFIER ';'                  {
                                                                    
                                                                            Symbol* sym = new Symbol($3.value,"int");
                                                                            sym->setIsInitialised(1);
                                                                            table->addSymbolInTable(sym);
                                                                            }                
           ;

while_proto: WHILE '(' compare_and_logic_expr ')' ';' ;


while_define: WHILE '(' compare_and_logic_expr ')' scope_begin stmt_list scope_end            {
                                                                                table = scope.removeScope("while");
                                                                                generator.endScope("while");
                                                                            }

             | WHILE '(' compare_and_logic_expr ')' scope_begin break_stmt_list scope_end     {
                                                                                table = scope.removeScope("while");
                                                                                generator.endScope("while");                                                                            
                                                                            }
             ;



 /*/////////////////////////////////////////////fifth degree ////////////////////////////////////////////////////////////////////////////// */


func_sgnt: TYPE_VOID IDENTIFIER '('                                         { 
                                                                                $$.type = "void"; 
                                                                                $$.value = $2.value; 
                                                                                func = new Function($2.value, "void"); 
                                                                            }
         ;

ret_func_sgnt: type IDENTIFIER '('                                          { 
                                                                                $$.type = $1.type; 
                                                                                $$.value = $2.value; 
                                                                                func = new Function($2.value, $1.value); 
                                                                            }
             ;


parameters: type IDENTIFIER ')'                                             { 
                                                                                func->addParameter(new Symbol($2.value, $1.value)); 
                                                                            }

	  | type IDENTIFIER ',' parameters                                      { 
                                                                                func->addParameter(new Symbol($2.value, $1.value)); 
                                                                            }
      | ')'
      ;

enum_list:  IDENTIFIER 
	       | IDENTIFIER EQU INTEGER
           | IDENTIFIER EQU INTEGER ',' enum_list
           | IDENTIFIER ',' enum_list
           ;

case_list:  case_list CASE rvalue case_scope_begin break_stmt_list          { 
                                                                                table = scope.removeScope("case");
                                                                                generator.endScope("case"); 

                                                                            }

            | CASE rvalue case_scope_begin break_stmt_list                  { 
                                                                                table = scope.removeScope("case");
                                                                                generator.endScope("case"); 
                                                                            }
            ;

case_default: DEFAULT case_scope_begin break_stmt_list                      { 
                                                                                table = scope.removeScope("case");
                                                                                generator.endScope("case"); 
                                                                            }
            ;


arthimetic_expr_list: arthimetic_expr
         | arthimetic_expr ',' arthimetic_expr_list
         ;


//////////////////////////////////////////////////// sixth degree//////////////////////////////////////////////////////////////////////////////////


arthimetic_expr: expr_terminal

     | arthimetic_expr PLUS arthimetic_expr           {
                                                            const char* name1 = generator.getTemp($1.value);
                                                            const char* type1 = $1.type;
                                                            if (strcmp(type1, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                name1 = generator.getAssignment(sym); 
                                                                type1 = sym->getVarTypeAsCStr();
                                                            }
                                                            const char* name2 = generator.getTemp($3.value);
                                                            const char* type2 = $3.type;
                                                            if (strcmp(type2, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                name2 = generator.getAssignment(sym); 
                                                                type2 = sym->getVarTypeAsCStr();
                                                            }
                                                            if(!symanticAnalyser.checkType(type1, type2))
                                                            {
                                                                symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                            }
                                                            const char* name = generator.addTemp(name1 , "+" , name2);
                                                            generator.addQuad("ADD", $1.value, $3.value, name);
                                                            $$.value = name; 
                                                            $$.type = type1;
                                                        }

     | arthimetic_expr MINUS arthimetic_expr           {
                                                            const char* name1 = generator.getTemp($1.value);
                                                            const char* type1 = $1.type;
                                                            if (strcmp(type1, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                name1 = generator.getAssignment(sym); 
                                                                type1 = sym->getVarTypeAsCStr();
                                                            }
                                                            const char* name2 = generator.getTemp($3.value);
                                                            const char* type2 = $3.type;
                                                            if (strcmp(type2, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                name2 = generator.getAssignment(sym); 
                                                                type2 = sym->getVarTypeAsCStr();
                                                            }
                                                            if(!symanticAnalyser.checkType(type1, type2))
                                                            {
                                                                symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                            }
                                                            const char* name = generator.addTemp(name1 , "-" , name2);
                                                            generator.addQuad("SUB", $1.value, $3.value, name);
                                                            $$.value = name; 
                                                            $$.type = type1;
                                                        }

     | arthimetic_expr MULT arthimetic_expr             {
                                                            const char* name1 = generator.getTemp($1.value);
                                                            const char* type1 = $1.type;
                                                            if (strcmp(type1, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                name1 = generator.getAssignment(sym); 
                                                                type1 = sym->getVarTypeAsCStr();
                                                            }
                                                            const char* name2 = generator.getTemp($3.value);
                                                            const char* type2 = $3.type;
                                                            if (strcmp(type2, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                name2 = generator.getAssignment(sym); 
                                                                type2 = sym->getVarTypeAsCStr();
                                                            }
                                                            if(!symanticAnalyser.checkType(type1, type2))
                                                            {
                                                                symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                            }
                                                            const char* name = generator.addTemp(name1 , "*" , name2);
                                                            generator.addQuad("MUL", $1.value, $3.value, name);
                                                            $$.value = name; 
                                                            $$.type = type1;
                                                        }

     | arthimetic_expr DIV arthimetic_expr              {
                                                            const char* name1 = generator.getTemp($1.value);
                                                            const char* type1 = $1.type;
                                                            if (strcmp(type1, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                name1 = generator.getAssignment(sym); 
                                                                type1 = sym->getVarTypeAsCStr();
                                                            }
                                                            const char* name2 = generator.getTemp($3.value);
                                                            const char* type2 = $3.type;
                                                            if (strcmp(type2, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                name2 = generator.getAssignment(sym); 
                                                                type2 = sym->getVarTypeAsCStr();
                                                            }
                                                            if(!symanticAnalyser.checkType(type1, type2))
                                                            {
                                                                symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                            }
                                                            const char* name = generator.addTemp(name1 , "/" , name2);
                                                            generator.addQuad("DIV", $1.value, $3.value, name);
                                                            $$.value = name; 
                                                            $$.type = type1;
                                                        }

     | arthimetic_expr POWER arthimetic_expr            {
                                                            const char* name1 = generator.getTemp($1.value);
                                                            const char* type1 = $1.type;
                                                            if (strcmp(type1, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                name1 = generator.getAssignment(sym); 
                                                                type1 = sym->getVarTypeAsCStr();
                                                            }
                                                            const char* name2 = generator.getTemp($3.value);
                                                            const char* type2 = $3.type;
                                                            if (strcmp(type2, "ID") == 0) {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                name2 = generator.getAssignment(sym); 
                                                                type2 = sym->getVarTypeAsCStr();
                                                            }
                                                            if(!symanticAnalyser.checkType(type1, type2))
                                                            {
                                                                symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                            }
                                                            const char* name = generator.addTemp(name1 , "^" , name2);
                                                            generator.addQuad("POW", $1.value, $3.value, name);
                                                            $$.value = name; 
                                                            $$.type = type1;                                 
                                                        }

     | arthimetic_expr MODULE arthimetic_expr           {
                                                            const char* name1 = generator.getTemp($1.value);
                                                            const char* type1 = $1.type;
                                                            if (strcmp(type1, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                name1 = generator.getAssignment(sym); 
                                                                type1 = sym->getVarTypeAsCStr();
                                                            }
                                                            const char* name2 = generator.getTemp($3.value);
                                                            const char* type2 = $3.type;
                                                            if (strcmp(type2, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                name2 = generator.getAssignment(sym); 
                                                                type2 = sym->getVarTypeAsCStr();
                                                            }
                                                            if(!symanticAnalyser.checkType(type1, type2))
                                                            {
                                                                symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                            }
                                                            const char* name = generator.addTemp(name1 , "%" , name2);
                                                            generator.addQuad("MOD", $1.value, $3.value, name);
                                                            $$.value = name; 
                                                            $$.type = type1;
                                                        }
       ;



compare_and_logic_expr:   expr_terminal


               | compare_and_logic_expr EQU_EQU compare_and_logic_expr          {
                                                                const char* name1 = generator.getTemp($1.value);
                                                                const char* type1 = $1.type;
                                                                if (strcmp(type1, "ID") == 0) {
                                                                    Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                    name1 = generator.getAssignment(sym); 
                                                                    type1 = sym->getVarTypeAsCStr();
                                                                }
                                                                const char* name2 = generator.getTemp($3.value);
                                                                const char* type2 = $3.type;
                                                                if (strcmp(type2, "ID") == 0) {
                                                                    Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                    name2 = generator.getAssignment(sym); 
                                                                    type2 = sym->getVarTypeAsCStr();
                                                                }
                                                                if(!symanticAnalyser.checkType(type1, type2))
                                                                {
                                                                    symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                }
                                                                const char* name = generator.addTemp(name1 , "==" , name2);
                                                                generator.addQuad("EQU", $1.value, $3.value, name);
                                                                $$.value = name;  
                                                                $$.type = "bool";
                                                            }

            | compare_and_logic_expr NOT_EQU compare_and_logic_expr          {
                                                                    const char* name1 = generator.getTemp($1.value);
                                                                    const char* type1 = $1.type;
                                                                    if (strcmp(type1, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                        name1 = generator.getAssignment(sym); 
                                                                        type1 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    const char* name2 = generator.getTemp($3.value);
                                                                    const char* type2 = $3.type;
                                                                    if (strcmp(type2, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                        name2 = generator.getAssignment(sym); 
                                                                        type2 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    if(!symanticAnalyser.checkType(type1, type2))
                                                                    {
                                                                        symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                    }
                                                                    const char* name = generator.addTemp(name1 , "!=" , name2);
                                                                    generator.addQuad("NOTEQU", $1.value, $3.value, name);
                                                                    $$.value = name;  
                                                                    $$.type = "bool";
                                                                }

            | compare_and_logic_expr MORE_OR_EQU compare_and_logic_expr      {
                                                                    const char* name1 = generator.getTemp($1.value);
                                                                    const char* type1 = $1.type;
                                                                    if (strcmp(type1, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                        name1 = generator.getAssignment(sym); 
                                                                        type1 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    const char* name2 = generator.getTemp($3.value);
                                                                    const char* type2 = $3.type;
                                                                    if (strcmp(type2, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                        name2 = generator.getAssignment(sym); 
                                                                        type2 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    if(!symanticAnalyser.checkType(type1, type2))
                                                                    {
                                                                        symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                    }
                                                                    const char* name = generator.addTemp(name1 , ">=" , name2);
                                                                    generator.addQuad("MOREEQU", $1.value, $3.value, name);
                                                                    $$.value = name;  
                                                                    $$.type = "bool";
                                                                }

            | compare_and_logic_expr LESS_OR_EQU compare_and_logic_expr      {
                                                                    const char* name1 = generator.getTemp($1.value);
                                                                    const char* type1 = $1.type;
                                                                    if (strcmp(type1, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                        name1 = generator.getAssignment(sym); 
                                                                        type1 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    const char* name2 = generator.getTemp($3.value);
                                                                    const char* type2 = $3.type;
                                                                    if (strcmp(type2, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                        name2 = generator.getAssignment(sym); 
                                                                        type2 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    if(!symanticAnalyser.checkType(type1, type2))
                                                                    {
                                                                        symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                    }
                                                                    const char* name = generator.addTemp(name1 , "<=" , name2);
                                                                    generator.addQuad("LESSEQU", $1.value, $3.value, name);
                                                                    $$.value = name; 
                                                                    $$.type = "bool";
                                                                }

            | compare_and_logic_expr MORE compare_and_logic_expr             {
                                                                    const char* name1 = generator.getTemp($1.value);
                                                                    const char* type1 = $1.type;
                                                                    if (strcmp(type1, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                        name1 = generator.getAssignment(sym); 
                                                                        type1 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    const char* name2 = generator.getTemp($3.value);
                                                                    const char* type2 = $3.type;
                                                                    if (strcmp(type2, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                        name2 = generator.getAssignment(sym); 
                                                                        type2 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    if(!symanticAnalyser.checkType(type1, type2))
                                                                    {
                                                                        symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                    }
                                                                    const char* name = generator.addTemp(name1 , ">" , name2);
                                                                    generator.addQuad("MORE", $1.value, $3.value, name);
                                                                    $$.value = name; 
                                                                    $$.type = "bool";
                                                                }

            | compare_and_logic_expr LESS compare_and_logic_expr             {
                                                                    const char* name1 = generator.getTemp($1.value);
                                                                    const char* type1 = $1.type;
                                                                    if (strcmp(type1, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                        name1 = generator.getAssignment(sym); 
                                                                        type1 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    const char* name2 = generator.getTemp($3.value);
                                                                    const char* type2 = $3.type;
                                                                    if (strcmp(type2, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                        name2 = generator.getAssignment(sym); 
                                                                        type2 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    if(!symanticAnalyser.checkType(type1, type2))
                                                                    {
                                                                        symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                    }
                                                                    const char* name = generator.addTemp(name1 , "<" , name2);
                                                                    generator.addQuad("LESS", $1.value, $3.value, name);
                                                                    $$.value = name; 
                                                                    $$.type = "bool";
                                                                }
                                        
            | compare_and_logic_expr AND compare_and_logic_expr                    {
                                                                    const char* name1 = generator.getTemp($1.value);
                                                                    const char* type1 = $1.type;
                                                                    if (strcmp(type1, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                        name1 = generator.getAssignment(sym); 
                                                                        type1 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    const char* name2 = generator.getTemp($3.value);
                                                                    const char* type2 = $3.type;
                                                                    if (strcmp(type2, "ID") == 0) 
                                                                    {
                                                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                        name2 = generator.getAssignment(sym); 
                                                                        type2 = sym->getVarTypeAsCStr();
                                                                    }
                                                                    if(!symanticAnalyser.checkType(type1, type2))
                                                                    {
                                                                        symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                    }
                                                                    const char* name = generator.addTemp(name1 , "&&" , name2);
                                                                    generator.addQuad("AND", $1.value, $3.value, name);
                                                                    $$.value = name;  
                                                                    $$.type = type1;
                                                                }

            | compare_and_logic_expr OR compare_and_logic_expr                     {
                                                                const char* name1 = generator.getTemp($1.value);
                                                                const char* type1 = $1.type;
                                                                if (strcmp(type1, "ID") == 0) 
                                                                {
                                                                    Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                    name1 = generator.getAssignment(sym); 
                                                                    type1 = sym->getVarTypeAsCStr();
                                                                }
                                                                const char* name2 = generator.getTemp($3.value);
                                                                const char* type2 = $3.type;
                                                                if (strcmp(type2, "ID") == 0) 
                                                                {
                                                                    Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                                                    name2 = generator.getAssignment(sym); 
                                                                    type2 = sym->getVarTypeAsCStr();
                                                                }
                                                                if(!symanticAnalyser.checkType(type1, type2))
                                                                {
                                                                    symanticAnalyser.raiseError("Type mismatch", @1.first_line);
                                                                }
                                                                const char* name = generator.addTemp(name1 , "||" , name2);
                                                                generator.addQuad("OR", $1.value, $3.value, name);
                                                                $$.value = name; 
                                                                $$.type = type1;
                                                            }

            |NOT compare_and_logic_expr                          {
                                                            const char* name1 = generator.getTemp($2.value);
                                                            const char* type1 = $2.type;
                                                            if (strcmp(type1, "ID") == 0) 
                                                            {
                                                                Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                                                name1 = generator.getAssignment(sym); 
                                                                type1 = sym->getVarTypeAsCStr();
                                                            }
                                                            if (strcmp(type1, "int") != 0 && strcmp(type1, "bool") != 0)
                                                            {
                                                                symanticAnalyser.raiseError("Cant invert variable of this type", @1.first_line);
                                                            }
                                                            const char* name = generator.addTemp("!" , name1, "");
                                                            generator.addQuad("NOT", $2.value, "", name);
                                                            $$.value = name; 
                                                            $$.type = type1;
                                                        }

            ;




expr_terminal: rvalue                                  { 
                                                            const char* name = generator.addTemp($1.value , "" , "");
                                                            generator.addQuad("ASSIGN", $1.value, "", name);

                                                            $$.value = name; 
                                                            $$.type = $1.type;
                                                        }

            | IDENTIFIER                               { 
                                                            SymbolTable* table = scope.getSymbolTableFromStack($1.value);
                                                            if (table != NULL)
                                                            {
                                                                Symbol* sym = table->getSymbolObjectbyName($1.value);
                                                                sym->setIsUsed(1);
                                                                
                                                                const char* name = generator.addTemp(sym->getName() , "" , "");
                                                                generator.addQuad("ASSIGN", generator.getAssignment(sym), "", name);

                                                                $$.value = name;
                                                                $$.type = $1.type; 
                                                                symanticAnalyser.checkIntializedVariable(sym->checkInitialisation(), @1.first_line);
                                                            } 
                                                            else 
                                                            {
                                                                symanticAnalyser.raiseError("unidentified variable", @1.first_line);
                                                            }

                                                        }
            ;

type: TYPE_INT                                                              { $$.type = "TYPE"; $$.value = "int"; }
      | TYPE_FLOAT                                                          { $$.type = "TYPE"; $$.value = "float"; }
      | TYPE_CHAR                                                           { $$.type = "TYPE"; $$.value = "char"; }
      | TYPE_BOOL                                                           { $$.type = "TYPE"; $$.value = "bool"; }
      | TYPE_STRING                                                         { $$.type = "TYPE"; $$.value = "string"; }
      ;

rvalue: INTEGER                                                             { $$.type = "int"; $$.value = $1.value; }
        | FLOAT                                                             { $$.type = "float"; $$.value = $1.value; }
        | CHAR                                                              { $$.type = "char"; $$.value = $1.value; }
        | BOOL                                                              { $$.type = "bool"; $$.value = $1.value; }
        | STRING                                                            { $$.type = "string"; $$.value = $1.value; }
        ;

scope_begin: '{'            {                            
                                table = scope.addScope();
                                if(func != NULL) 
                                {
                                    for(int i = 0; i < func->getCount(); i++)
                                    {
                                        table->addSymbolInTable(func->getParameter(i));
                                    }
                                }
                                generator.startScope();
                            }
             ;


scope_end: '}'              {
                                table->checkSymbolTable(@1.first_line); 
                            }
           ;

case_scope_begin: ':'       {   
                                table = scope.addScope();
                                generator.startScope();
                            }
                ;

%%
     
/* ############ Auxiliary Functions ############ */

int main(int argc, char **argv) { 
    lex_init(scanner);

    yydebug = ENABLE_YACC_DEBUG;
    yyset_debug(ENABLE_LEX_DEBUG, scanner);

    yyparse(scanner);

    scope.printSymbolTablesToFile();
    functions.printFunctionTableToFile();
    generator.printQuadsToFile();

    symanticAnalyser.printErrorList();
    symanticAnalyser.printWarningList();

    lex_deinit(scanner);

    return 0;
}

int yyerror(struct YYLTYPE* yylloc, void* scanner, const char *s)
{
    return fprintf(stderr, "%s\n", s);
}

/*CODE COPIED FROM BISON DOCUMENTATION, JUST FOR TESTING, CAN CHANGE LATER*/
static int yyreport_syntax_error(const yypcontext_t *ctx, void* scanner)
{
    int res = 0;
    YYLOCATION_PRINT(stderr, yypcontext_location(ctx));
    fprintf(stderr, ": syntax error");

    // Report the tokens expected at this point.
    {
        yysymbol_kind_t expected[5];
        int n = yypcontext_expected_tokens(ctx, expected, 5);
        if (n < 0)
        {
          // Forward errors to yyparse.
          res = n;
        }
        else
        {
          for (int i = 0; i < n; ++i)
          {
              fprintf(stderr, "%s %s", i == 0 ? ": expected" : " or", yysymbol_name(expected[i]));
          }  
        }     
    }

    // Report the unexpected token.
    {
        yysymbol_kind_t lookahead = yypcontext_token(ctx);
        if (lookahead != YYSYMBOL_YYEMPTY)
        {
            fprintf(stderr, " before %s, len = %d", yysymbol_name(lookahead), yyget_leng(scanner));
        }
    }

    fprintf(stderr, "\n");
    return res;
}