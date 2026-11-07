/*

Description

There is a board with 100 * 100 grids as shown below. The left-top gird is denoted as (1, 1) and the right-bottom grid is (100, 100).

http://poj.org/images/1656_1.jpg

We may apply three commands to the board:

1.	WHITE  x, y, L     // Paint a white square on the board,

                           // the square is defined by left-top grid (x, y)

                           // and right-bottom grid (x+L-1, y+L-1)



2.	BLACK  x, y, L     // Paint a black square on the board,

                           // the square is defined by left-top grid (x, y)

                           // and right-bottom grid (x+L-1, y+L-1)



3.	TEST     x, y, L    // Ask for the number of black grids

                            // in the square (x, y)- (x+L-1, y+L-1)

In the beginning, all the grids on the board are white. We apply a series of commands to the board. Your task is to write a program to give the numbers of black grids within a required region when a TEST command is applied.
Input

The first line of the input is an integer t (1 <= t <= 100), representing the number of commands. In each of the following lines, there is a command. Assume all the commands are legal which means that they won't try to paint/test the grids outside the board.

Output

For each TEST command, print a line with the number of black grids in the required region.

Sample Input

5
BLACK 1 1 2
BLACK 2 2 2
TEST 1 1 3
WHITE 2 1 1
TEST 1 1 3

Sample Output

7
6
Source

POJ Monthly--2004.05.15 Liu Rujia@POJ

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
process(const char **inst, size_t len, unsigned char grid[len][len])
{
	char op[8];
	unsigned X, Y, L;
	unsigned c, v, x, y;
	size_t i;

	memset(grid, 0, sizeof(*grid) * len);
	for (i = 0; inst[i]; i++) {
		if (sscanf(inst[i], "%7s %u %u %u", op, &X, &Y, &L) != 4)
			continue;

		v = 2;
		if (!strcmp(op, "BLACK"))
			v = 1;
		else if (!strcmp(op, "WHITE"))
			v = 0;

		c = 0;
		for (y = Y; y < Y + L; y++) {
			for (x = X; x < X + L; x++) {
				if (x >= len || y >= len)
					continue;
				if (v < 2)
					grid[y][x] = v;
				c += grid[y][x];
			}
		}

		if (!strcmp(op, "TEST"))
			printf("%u\n", c);
	}
}

int
main(void)
{
	const char *inst[] = {
	    "BLACK 1 1 2",
	    "BLACK 2 2 2",
	    "TEST 1 1 3",
	    "WHITE 2 1 1",
	    "TEST 1 1 3",
	    NULL,
	};
	unsigned char grid[100][100];

	process(inst, nelem(grid), grid);

	return 0;
}
