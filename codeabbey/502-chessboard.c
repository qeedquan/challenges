/*

Not 100% sure, but probably this simple exercise was proposed by my first school programming teacher Sergey Stolyar for kids of age about 12-13. Later I encountered it in similar form at some junior grade interview at the company long ceased to exist :)

The task is to print a chessboard, given the following parameters: cell_width, cell_height, board_size, border_h, border_v.

The first two give the cell (square) size in characters, next comes board size (in squares) and at last width and height of border, surrounding the board. Regard the example below.

"Black" squares are to be filled with "X" characters, "White" with " " (space). And border should be filled with - (simple dash). Note that lower left corner is always black.

First time here? Write some code to solve the problem - particularly, to produce the desired output. Put both your code and your output to the areas below. For problems marked with any-lang only the answer is actually checked, while code is stored for your convenience. On pressing Submit the site will verify your output and tell if anything is wrong or all is OK. Good luck!

Input:

5 3 4 3 2
Output:

--------------------------
--------------------------
---     XXXXX     XXXXX---
---     XXXXX     XXXXX---
---     XXXXX     XXXXX---
---XXXXX     XXXXX     ---
---XXXXX     XXXXX     ---
---XXXXX     XXXXX     ---
---     XXXXX     XXXXX---
---     XXXXX     XXXXX---
---     XXXXX     XXXXX---
---XXXXX     XXXXX     ---
---XXXXX     XXXXX     ---
---XXXXX     XXXXX     ---
--------------------------
--------------------------

*/

#include <stdio.h>

void
print_border_outer(int cell_width, int board_size, int border_h, int border_v)
{
	int cell_x;
	int cell_y;

	for (cell_y = 0; cell_y < border_v; cell_y++) {
		for (cell_x = 0; cell_x < (board_size * cell_width) + (2 * border_h); cell_x++)
			printf("-");
		printf("\n");
	}
}

void
print_cell(int cell_width, int cell_height, int board_size, int border_h, int board_row)
{
	int cell_x;
	int cell_y;
	int color;

	for (cell_y = 0; cell_y < cell_height; cell_y++) {
		for (cell_x = 0; cell_x < border_h; cell_x++)
			printf("-");
		for (cell_x = 0; cell_x < cell_width * board_size; cell_x++) {
			color = ((cell_x / cell_width) ^ board_row) & 1;
			if (color)
				printf("X");
			else
				printf(" ");
		}
		for (cell_x = 0; cell_x < border_h; cell_x++)
			printf("-");
		printf("\n");
	}
}

void
print_board(int cell_width, int cell_height, int board_size, int border_h, int border_v)
{
	int board_row;

	print_border_outer(cell_width, board_size, border_h, border_v);
	for (board_row = 0; board_row < board_size; board_row++)
		print_cell(cell_width, cell_height, board_size, border_h, board_row);
	print_border_outer(cell_width, board_size, border_h, border_v);
	printf("\n");
}

int
main()
{
	print_board(5, 3, 4, 3, 2);
	return 0;
}
