/*

Challenge

Create the shortest program that meets the requirements
Requirements

    The code must generate a 5x5 grid of 0s, like so:

    00000
    00000
    00000
    00000
    00000

    The code must accept an input (column, row, character). The grid must change accordingly:

    Start:

    00000
    00000
    00000
    00000
    00000

    Input:

    (2,5,*)

    Output:

    0*000
    00000
    00000
    00000
    00000

    (Note: the bottom-left corner is position 1,1.)

    The program must return an error message other than the grid if the row/column input is not 1,2,3,4, or 5. This can be any message of your choice (as long as it's not the grid), so 0 is an acceptable error-output.

    The program must work with all printable ASCII characters (of a US keyboard).

THE WINNER

The winner will be the person who has the shortest code and fulfills all requirements. If more than one answer works and has the same (shortest) length, the person who answered first will be the winner.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
fill(char m[5][5], size_t c, size_t r, int v)
{
	if (r < 1 || r > 5 || c < 1 || c > 5)
		return -1;

	memset(m, '0', 5 * 5);
	m[5 - r][c - 1] = v;
	return 0;
}

void
dump(char m[5][5])
{
	size_t i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
			printf("%c", m[i][j]);
		printf("\n");
	}
}

int
main(void)
{
	char m[5][5];

	assert(fill(m, 2, 5, '*') >= 0);
	dump(m);

	return 0;
}
