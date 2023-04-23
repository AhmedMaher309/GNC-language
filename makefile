LEX = flex
YACC = bison
CC = gcc

IN = input.txt
OUT = output.txt

# link rule
build: lexer parser
	$(CC) -o compiler.out src/lex.yy.c src/y.tab.c

# link rule
cleanbuild: lexer_silent parser_silent
	$(CC) -o compiler.out src/lex.yy.c src/y.tab.c
	rm -f src/y.* src/lex.*

# run rule
run: 
	./compiler.out ./inputs/$(IN) ./outputs/$(OUT)

# clean rule
clean: 
	rm -f src/y.* src/lex.*

# clear rule
clear: 
	rm -f src/y.* src/lex.*
	rm -f inputs/*.txt
	rm -f outputs/*.txt
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
