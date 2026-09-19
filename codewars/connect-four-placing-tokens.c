/*

Simulate placing tokens on a Connect Four board.

http://tinyurl.com/js6vz2v

INPUT
A list of integers representing the columns (from 0 to 6) where tokens are dropped, in order. The first player is yellow (Y), followed by red (R), alternating turns.

OUTPUT
The final state of the board after all tokens have been placed. Empty cells are marked with -.

ASSUMPTIONS
The board has 7 columns and 6 rows (standard Connect Four size).
Tokens fall to the lowest available position in the chosen column.
All input values are valid and within the allowed range.
The input list must not be modified.
Output format: rows are listed from top to bottom, with the top row first and the bottom row last.

EXAMPLES
Example 1:

Moves = [0,1,2,5,6]

Result:
['-', '-', '-', '-', '-', '-', '-']
['-', '-', '-', '-', '-', '-', '-']
['-', '-', '-', '-', '-', '-', '-']
['-', '-', '-', '-', '-', '-', '-']
['-', '-', '-', '-', '-', '-', '-']
['Y', 'R', 'Y', '-', '-', 'R', 'Y']
Example 2:

Moves = [0,1,2,5,6,2,0,0]

Result:
['-', '-', '-', '-', '-', '-', '-']
['-', '-', '-', '-', '-', '-', '-']
['-', '-', '-', '-', '-', '-', '-']
['R', '-', '-', '-', '-', '-', '-']
['Y', '-', 'R', '-', '-', '-', '-']
['Y', 'R', 'Y', '-', '-', 'R', 'Y']

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
c4(char b[6][7], int *m, size_t n)
{
	int x, y;
	char p;
	size_t i;

	memset(b, '-', 6 * 7);
	for (i = 0; i < n; i++) {
		p = (i & 1) ? 'R' : 'Y';
		x = m[i];
		for (y = 5; y >= 0; y--) {
			if (b[y][x] == '-') {
				b[y][x] = p;
				break;
			}
		}
	}
}

void
print(char b[6][7])
{
	int x, y;

	for (y = 0; y < 6; y++) {
		for (x = 0; x < 7; x++)
			printf("%c", b[y][x]);
		printf("\n");
	}
	printf("\n");
}

void
test(int *m, size_t n)
{
	char b[6][7];

	c4(b, m, n);
	print(b);
}

int
main()
{
	int m1[] = { 0, 1, 2, 5, 6 };
	int m2[] = { 0, 1, 2, 5, 6, 2, 0, 0 };

	test(m1, nelem(m1));
	test(m2, nelem(m2));

	return 0;
}
