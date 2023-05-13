LEX = flex
YACC = bison
CC = g++

IN = testcases/input.txt
OUT = testcases/output.txt

# link rule
build: lexer parser  src/RulesFiles/iohandler.c  src/SymbolTable/symbol.cpp  src/SymbolTable/symboltable.cpp  src/Validator/validator.cpp
	$(CC) -o compiler.out  src/RulesFiles/lex.yy.c  src/RulesFiles/y.tab.c  src/RulesFiles/iohandler.c  src/SymbolTable/symbol.cpp  src/SymbolTable/symboltable.cpp  src/Validator/validator.cpp

# link rule
cleanbuild: lexer_silent parser_silent  src/RulesFiles/iohandler.c  src/SymbolTable/symbol.cpp  src/SymbolTable/symboltable.cpp  src/Validator/validator.cpp
	$(CC) -o compiler.out src/RulesFiles/lex.yy.c  src/RulesFiles/y.tab.c src/RulesFiles/iohandler.c  src/SymbolTable/symbol.cpp  src/SymbolTable/symboltable.cpp  src/Validator/validator.cpp
	rm -f src/RulesFiles/y.* src/RulesFiles/lex.*

# run rule
run: 
	(echo r_$(IN) && echo w_$(OUT)) | ./compiler.out

# clean rule
clean: 
	rm -f src/y.* src/lex.*

# clear rule
clear: 
	rm -f src/RulesFiles/y.* src/RulesFiles/lex.*
	rm -f testcases/*.txt
	rm -f compiler.out

####################################################################################################

# compile rule
lexer: src/RulesFiles/lexer.l
	$(LEX) -o src/RulesFiles/lex.yy.c --debug --verbose src/RulesFiles/lexer.l

# compile rule
lexer_silent: src/RulesFiles/lexer.l
	$(LEX) -o src/RulesFiles/lex.yy.c --debug src/RulesFiles/lexer.l

# compile rule
parser: src/RulesFiles/parser.y
	$(YACC) -o src/RulesFiles/y.tab.c -d --debug --verbose src/RulesFiles/parser.y

# compile rule
parser_silent: src/RulesFiles/parser.y
	$(YACC) -o src/RulesFiles/y.tab.c -d --debug src/RulesFiles/parser.y
