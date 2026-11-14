/*

A and B are playing a very interesting variant of the ancient Indian game 'shatranj' (also known as chess) on a 'maidaan' (chessboard) n × n in size.

They take turns to put game pieces called 'ghoda'(knight) so that no two 'ghodas' (knights) could threaten each other.

A 'ghoda' located in square (a, b) can threaten squares (a + 1, b + 2), (a - 1, b + 2), (a + 1, b - 2), (a - 1, b - 2), (a + 2, b - 1), (a + 2, b + 1), (a - 2, b - 1), (a - 2, b + 1).

The player who can't put a new 'ghoda' during his move loses. Find out which player wins considering that both players play optimally well and A starts.

Input
The first line contains integer T (1 ≤ T ≤ 104) — the number of 'maidaans' (boards), for which you should determine the winning player. Next T lines contain T integers ni (1 ≤ ni ≤ 105) — the sizes of the 'maidaans' (chessboards).

Output
For each ni × ni board print on a single line "0" if A wins considering both players play optimally well. Otherwise, print "1".

Example
Input:
2
2
1

Output:
1
0

*/

#include <assert.h>

int
solve(int n)
{
	return (n & 1) ^ 1;
}

int
main()
{
	assert(solve(2) == 1);
	assert(solve(1) == 0);

	return 0;
}
