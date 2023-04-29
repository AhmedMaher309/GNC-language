LEX = flex
YACC = bison
CC = gcc

IN = testcases/input.txt
OUT = testcases/output.txt

# link rule
build: lexer parser src/iohandler.c 
	$(CC) -o compiler.out src/lex.yy.c src/y.tab.c src/iohandler.c

# link rule
cleanbuild: lexer_silent parser_silent src/iohandler.c
	$(CC) -o compiler.out src/lex.yy.c src/y.tab.c src/iohandler.c
	rm -f src/y.* src/lex.*

# run rule
run: 
	(echo r_$(IN) && echo w_$(OUT)) | ./compiler.out

# clean rule
clean: 
	rm -f src/y.* src/lex.*

# clear rule
clear: 
	rm -f src/y.* src/lex.*
	rm -f testcases/*.txt
	rm -f compiler.out

####################################################################################################

# compile rule
lexer: src/lexer.l
	$(LEX) -o src/lex.yy.c --debug --verbose src/lexer.l

# compile rule
lexer_silent: src/lexer.l
	$(LEX) -o src/lex.yy.c --debug src/lexer.l

# compile rule
parser: src/parser.y
	$(YACC) -o src/y.tab.c -d --debug --verbose src/parser.y

# compile rule
parser_silent: src/parser.y
	$(YACC) -o src/y.tab.c -d --debug src/parser.y
