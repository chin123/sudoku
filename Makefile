OPTS= -g -O3 -march=native
CC=gcc

all: main

sudoku: sudoku.c sudoku.h
	$(CC) $(OPTS) sudoku.c -c

main: sudoku main.c
	$(CC) $(OPTS) main.c sudoku.o -o main

clean:
	rm *.o main
