/*

You want to create a square chessboard. Adjacent tiles must alternate black and white like a standard chessboard, and the bottom left corner can be either black or white.

Your program will take in two positive integers, the number of black and the number of white tiles. These will always be less than 1024. You don't have to use all the tiles.

Output the maximum side length of a chessboard pattern that can be constructed using the given amount of tiles.

Test Cases:

12, 15 -> 5
8, 8 -> 4
4, 0 -> 1

*/

#include <assert.h>
#include <math.h>

/*

@Arnauld

Given the number of black squares b and the number of white squares w, this computes:

s = floor(sqrt(2 * min(b, w) + k))

with

k = 0 if b = w
    1 if b != w

For even sizes s, we need s^2/2 squares of each kind (e.g. for s=8: 32 black squares and 32 white squares).

For odd sizes s, we need ⌊s2/2⌋ squares of one kind and ⌈s2/2⌉ squares of the other kind (e.g. for s=5: 12 black squares and 13 white squares, or the other way around).
The parameter k is set to 1 if max(b,w) ≥ min(b,w)+1, which represents this extra square on one side.

*/

int
sidelength(int b, int w)
{
	int k;

	if (b < 0 || w < 0)
		return 0;

	k = (b != w);
	return sqrt(2 * fmin(b, w) + k);
}

int
main()
{
	assert(sidelength(12, 15) == 5);
	assert(sidelength(8, 8) == 4);
	assert(sidelength(4, 0) == 1);

	return 0;
}
