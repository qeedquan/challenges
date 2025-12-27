/*

Your task is to find the maximum number of queens that can be put on the board so that there would be one single unbeaten square (ie. threatened by no queen on the board).

The Queen can move any distance vertically, horizontally and diagonally.

Input
The queens(n) function takes the size of the chessboard.

n∈Z, so it can be negative, and values can go up to 141^1000.

Output
The maximum number of queens to leave one single unbeaten square
Return 0 if n is negative.

Examples

n=4→6 queens

n=5→12 queens

Good luck )

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A002378
int
queens(int n)
{
	if (n < 2)
		return 0;
	return (n - 2) * (n - 1);
}

int
main()
{
	static const int tab[] = {
		0, 2, 6, 12, 20, 30, 42, 56, 72, 90, 110, 132, 156, 182, 210, 240, 272,
		306, 342, 380, 420, 462, 506, 552, 600, 650, 702, 756, 812, 870, 930,
		992, 1056, 1122, 1190, 1260, 1332, 1406, 1482, 1560, 1640, 1722, 1806,
		1892, 1980, 2070, 2162, 2256, 2352, 2450, 2550
	};

	size_t i;

	assert(queens(4) == 6);
	assert(queens(5) == 12);

	for (i = 0; i < nelem(tab); i++)
		assert(queens(i + 2) == tab[i]);

	return 0;
}
