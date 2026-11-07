/*

Suppose a new fairy chess piece named the Wazir is introduced to chess. Wazirs can move from a position (x, y) to:
 (x+1, y)
 (x, y+1)
 (x-1, y)
 (x, y-1)

That is, they move orthogonally like the rook, but only one step at a time like the king. How many such wazirs can be placed on an N×N chessboard so that no two wazirs can attack each other?

 On a 1×1 board, there can be only 1 such piece.
 On a 2×2 board, there can be 2 such pieces.
 On a 3×3 board, there can be 5 such pieces.

Given N, return the number of wazirs that can be placed on an N×N chessboard.

This is OEIS sequence A000982.

More test cases
7 → 25

8 → 32

100 → 5000

*/

#include <assert.h>
#include <math.h>

// https://oeis.org/A000982
int
wazirs(int n)
{
	return ceil((n * n) / 2.0);
}

int
main(void)
{
	assert(wazirs(7) == 25);
	assert(wazirs(8) == 32);
	assert(wazirs(100) == 5000);

	return 0;
}
