#include <stdio.h>
#include "sudoku.h"

void setup(sudoku *s, char *board) {  
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			s->board[i][j] = board[i*SIZE + j] - '0';
			if (board[i*SIZE + j] == '_') {
				s->board[i][j] = EMPTY;
			}
		}
	}
}

void solvesudoku(sudoku *s) {
	int row = 0, col = -1;
	nextvalid(s, &row, &col);
	solve(s, row, col);
}

int solve(sudoku *s, int row, int col) {
	if (row >= SIZE || col >= SIZE) {
		return 1;
	}
	for (int i = 1; i <= SIZE; i++) {
		if (isvalid(s, row, col, i)) {
			int nextrow = row, nextcol = col;
			s->board[row][col] = i;
			nextvalid(s, &nextrow, &nextcol);
			int issolved = solve(s, nextrow, nextcol);
			if (issolved) {
				s->board[row][col] = i;
				return 1;
			}
			s->board[row][col] = EMPTY;
		}
	}
	return 0;
}

void nextvalid(sudoku *s, int *row, int *col) {
	for (*row = 0; *row < SIZE; (*row)++) {
		for (*col = 0; *col < SIZE; (*col)++) {
			if (s->board[*row][*col] == EMPTY) {
				return;
			}
		}
	}
}

int isvalid(sudoku *s, int row, int col, int number) {
	if (!isvalidrow(s, row, col, number) 
			|| !isvalidcolumn(s, row, col, number) 
			|| !isvalidbox(s, row, col, number)) {
		return 0;
	}
	return 1;
}

int isvalidrow(sudoku *s, int row, int col, int number) {
	for (int i = 0; i < SIZE; i++) {
		if (i != col && s->board[row][i] == number) {
			return 0;
		}
	}
	return 1;
}

int isvalidcolumn(sudoku *s, int row, int col, int number) {
	for (int i = 0; i < SIZE; i++)
		if (i != row && s->board[i][col] == number)
			return 0;
	return 1;
}

int isvalidbox(sudoku *s, int row, int col, int number) {
	int rowstart = row - (row % 3);
	int colstart = col - (col % 3);
	int currentnumber;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (rowstart + i == row && colstart + j == col)
				continue;
			currentnumber = s->board[rowstart + i][colstart + j];
			if (number == currentnumber)
				return 0;
		}
	}
	return 1;
}

void printsudoku(sudoku *s) {
	for (int i = 0; i < SIZE; i++) {
		if (i % 3 == 0) {
			printf("+");
			for (int j = 0; j < 2*SIZE + 5; j++) {
				if ((j+1) % 8 == 0)
					printf("+");
				else
					printf("-");
			}
			printf("+\n");
		}
		for (int j = 0; j < SIZE; j++) {
			if (j % 3 == 0) {
				printf("| ");
			}

			printf("%c", (char) (s->board[i][j] + '0'));

			if (j != SIZE - 1) {
				printf(" ");
			}
		}
		printf(" |\n");
	}
	printf("+");
	for (int j = 0; j < 2*SIZE + 5; j++) {
		if ((j+1) % 8 == 0)
			printf("+");
		else
			printf("-");
	}
	printf("+\n");
}
