CC = gcc
CCFLAGS = -g -W -Wall

FLEX = flex
FLEX_OPTS = -Pmachine

BISON = bison
BISON_OPTS = -t -pmachine

OBJS = Absyn.o Lexer.o Parser.o Traverser.o Vector.o

.PHONY: clean distclean

all: main

clean:
	rm -f *.o shm machine.aux machine.log machine.pdf machine.dvi machine.ps machine

distclean: clean
	rm -f Absyn.h Absyn.c Test.c Parser.c Parser.h Lexer.c Traverser.c Traverser.h Makefile machine.l machine.y machine.tex Vector.c Vector.h

main: ${OBJS} main.o
	@echo "Linking main..."
	${CC} ${CCFLAGS} ${OBJS} main.o -o shm

Absyn.o: Absyn.c Absyn.h
	${CC} ${CCFLAGS} -c Absyn.c

Lexer.c: machine.l
	${FLEX} ${FLEX_OPTS} -oLexer.c machine.l

Parser.c: machine.y
	${BISON} ${BISON_OPTS} machine.y -o Parser.c

Lexer.o: Lexer.c Parser.h
	${CC} ${CCFLAGS} -c Lexer.c 

Parser.o: Parser.c Absyn.h
	${CC} ${CCFLAGS} -c Parser.c

Traverser.o: Traverser.c Traverser.h
	${CC} ${CCFLAGS} -c Traverser.c

Vector.o: Vector.c Vector.h
	${CC} ${CCFLAGS} -c Vector.c

main.o: main.c Parser.h Traverser.h Absyn.h
	${CC} ${CCFLAGS} -c main.c

