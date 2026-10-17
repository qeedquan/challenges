/*

An 8×8 chessboard has rows and columns numbered from 1 to 8.
Vasily Pupkin has a chess piece, which he places on a cell each time.
What is the maximum number of times his piece can be on the same cell?

Input
The first line contains the number of moves n (2≤n≤10^6).
Each of the next n lines contains two integers — the row and the column of the cell where the piece was placed on that move.

Output
Print the required single number.

Examples

Input #1
8 4 7 5 1 8 5 1 6 4 7 1 6 3 3 6 7

Answer #1
2

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
solve(int m[][2], size_t n)
{
	size_t i, r, x, y;
	size_t b[8][8];

	memset(b, 0, sizeof(b));

	r = 0;
	for (i = 0; i < n; i++) {
		y = m[i][0] - 1;
		x = m[i][1] - 1;
		b[y][x] += 1;
		r = max(r, b[y][x]);
	}
	return r;
}

int
main()
{
	int m1[][2] = {
		{ 4, 7 },
		{ 5, 1 },
		{ 8, 5 },
		{ 1, 6 },
		{ 4, 7 },
		{ 1, 6 },
		{ 3, 3 },
		{ 6, 7 },
	};

	assert(solve(m1, nelem(m1)) == 2);

	return 0;
}
