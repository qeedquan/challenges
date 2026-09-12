/*

https://static.e-olymp.com/content/0e/0ef7fe45fa90d7451b3038b57741862c513618f2.jpg

There are n matches on the table. Two players take turns.
A player may take no more than m matches, but not less than one.
The player who takes the last match wins.

Who will win in the regular game: the first or the second player?

Input
The first line contains the number of test cases t (1≤t≤100).
Each of the next t lines contains the number of matches n in the pile and the maximum number of matches m that can be taken in one move.
It is known that 1≤n,m≤2×10^9.

Output
Print a sequence of t ones and twos: 1 if the first player wins and 2 if the second player wins.

Examples

Input #1
2
7 3
8 3

Answer #1
12

*/

#include <assert.h>

int
solve(int n, int m)
{
	if (!(n % (m + 1)))
		return 2;
	return 1;
}

int
main()
{
	assert(solve(7, 3) == 1);
	assert(solve(8, 3) == 2);

	return 0;
}
