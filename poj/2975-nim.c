/*

Nim is a 2-player game featuring several piles of stones. Players alternate turns, and on his/her turn, a player’s move consists of removing one or more stones from any single pile. Play ends when all the stones have been removed, at which point the last player to have moved is declared the winner. Given a position in Nim, your task is to determine how many winning moves there are in that position.

A position in Nim is called “losing” if the first player to move from that position would lose if both sides played perfectly. A “winning move,” then, is a move that leaves the game in a losing position. There is a famous theorem that classifies all losing positions. Suppose a Nim position contains n piles having k1, k2, …, kn stones respectively; in such a position, there are k1 + k2 + … + kn possible moves. We write each ki in binary (base 2). Then, the Nim position is losing if and only if, among all the ki’s, there are an even number of 1’s in each digit position. In other words, the Nim position is losing if and only if the xor of the ki’s is 0.

Consider the position with three piles given by k1 = 7, k2 = 11, and k3 = 13. In binary, these values are as follows:

 111
1011
1101

There are an odd number of 1’s among the rightmost digits, so this position is not losing. However, suppose k3 were changed to be 12. Then, there would be exactly two 1’s in each digit position, and thus, the Nim position would become losing. Since a winning move is any move that leaves the game in a losing position, it follows that removing one stone from the third pile is a winning move when k1 = 7, k2 = 11, and k3 = 13. In fact, there are exactly three winning moves from this position: namely removing one stone from any of the three piles.

Input

The input test file will contain multiple test cases, each of which begins with a line indicating the number of piles, 1 ≤ n ≤ 1000. On the next line, there are n positive integers, 1 ≤ ki ≤ 1, 000, 000, 000, indicating the number of stones in each pile. The end-of-file is marked by a test case with n = 0 and should not be processed.

Output

For each test case, write a single line with an integer indicating the number of winning moves from the given Nim position.

Sample Input

3
7 11 13
2
1000000000 1000000000
0

Sample Output

3
0

Source

Stanford Local 2005

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
wins(long *a, size_t n)
{
	size_t i;
	long x, r;

	r = x = 0;
	for (i = 0; i < n; i++)
		x ^= a[i];
	for (i = 0; i < n; i++)
		r += ((x ^ a[i]) < a[i]);
	return r;
}

int
main(void)
{
	long a1[] = {7, 11, 13};
	long a2[] = {1000000000L, 1000000000L};

	assert(wins(a1, nelem(a1)) == 3);
	assert(wins(a2, nelem(a2)) == 0);

	return 0;
}
