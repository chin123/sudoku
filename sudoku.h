#define SIZE 9
#define EMPTY -16

struct sudoku {
	int board[SIZE][SIZE];
};

typedef struct sudoku sudoku;

void setup(sudoku *s, char *board);

void solvesudoku(sudoku *s);

int solve(sudoku *s, int row, int col);

void nextvalid(sudoku *s, int *row, int *col);

int isvalid(sudoku *s, int row, int col, int number);

int isvalidrow(sudoku *s, int row, int col, int number);

int isvalidcolumn(sudoku *s, int row, int col, int number);

int isvalidbox(sudoku *s, int row, int col, int number);

void solvesudoku(sudoku *s);

void printsudoku(sudoku *s);
