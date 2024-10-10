/*

This:

[ ] [*] [ ]
[ ] [ ] [*]
[*] [*] [*]

is a Glider.

In Conway's Game of Life, the glider is a famous pattern that rapidly traverses across the board. For today's challenge, we are going to draw an ASCII art Game of Life Board, and place a glider on it.

The board we are starting with is this:

|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
This board is made up entirely of pipes | and underscores _, and is 10x10. You must write a program or function that takes in two integers, 'x' and 'y', and outputs this same board with a glider at those coordinates. For example, if you had a glider at position (1, 1) (0-indexed), you must output the following:

|_|_|_|_|_|_|_|_|_|_|
|_|_|*|_|_|_|_|_|_|_|
|_|_|_|*|_|_|_|_|_|_|
|_|*|*|*|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
You can assume that the glider will never be placed out of bounds, so both x and y will always be in the [0-7] range. You may also choose to take the coordinates 1-indexed, but you must specify this in your answer. In this, case the inputs will always be in the [1-8] range. Here are some examples (all 0-indexed):

0, 0:
|_|*|_|_|_|_|_|_|_|_|
|_|_|*|_|_|_|_|_|_|_|
|*|*|*|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|

7, 7:
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|*|_|
|_|_|_|_|_|_|_|_|_|*|
|_|_|_|_|_|_|_|*|*|*|

7, 4:
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|*|_|
|_|_|_|_|_|_|_|_|_|*|
|_|_|_|_|_|_|_|*|*|*|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|

5, 2:
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|*|_|_|_|
|_|_|_|_|_|_|_|*|_|_|
|_|_|_|_|_|*|*|*|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|
As usual, you may take your IO in any reasonable format. This includes, but is not limited to a string with newlines, an array of strings, a 2d array of strings, or writing to a file/STDOUT. You may also choose what order to take x and y in.

Since this is code-golf, standard loopholes are banned, and make the shortest code that you can!

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
glider(int gx, int gy)
{
	static const int dir[][2] = {
	    {1, 0},
	    {2, 1},
	    {0, 2},
	    {1, 2},
	    {2, 2},
	};

	char b[10][10];
	size_t i;
	int x, y, s;

	s = 10;
	memset(b, '_', sizeof(b));
	for (i = 0; i < nelem(dir); i++) {
		x = gx + dir[i][0];
		y = gy + dir[i][1];
		if (x < s && y < s)
			b[y][x] = '*';
	}

	printf("%d, %d\n", gx, gy);
	for (y = 0; y < s; y++) {
		printf("|");
		for (x = 0; x < s; x++)
			printf("%c|", b[y][x]);
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	glider(0, 0);
	glider(7, 7);
	glider(7, 4);
	glider(5, 2);

	return 0;
}
