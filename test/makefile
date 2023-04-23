LEX = flex
CC = gcc

# Build rules
lexer: lexer.l
	$(LEX) -o lexer.c lexer.l
	$(CC) -o lexer lexer.c

# Clean rule
clean:
	rm -f lexer lexer.c

# Run rule
run: lexer
	./lexer
