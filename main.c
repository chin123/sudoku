#include <stdio.h>
#include <time.h>
#include "sudoku.h"

#define MAXBUF 100

int main(int argc, char *argv[]) {
  char buf[MAXBUF];
  sudoku s;
  double totaltime = 0;
  int count = 0;
  while (scanf("%s", buf) != EOF) {
	  setup(&s, buf);
	  clock_t start = clock();
	  solvesudoku(&s);
	  clock_t end = clock();
	  double elapsed = 1000 * ((double) end - start) / CLOCKS_PER_SEC;
	  printf("Time taken: %f ms\n", elapsed);
	  totaltime += elapsed;
	  count++;
	  printsudoku(&s);
  }
  printf("Total time taken: %f ms\n", totaltime);
  printf("Average time for one sudoku: %f ms\n", (double) totaltime/count);
  return 0;
}
