/*

Integer n is given. Print the next even integer for n.

Input
One integer n.

Output
Print the next even integer after n.

Examples

Input #1
7

Answer #1
8

Input #2
4

Answer #2
6

*/

#include <assert.h>

int
solve(int n)
{
	return n + 1 + !(n & 1);
}

int
main()
{
	assert(solve(0) == 2);
	assert(solve(1) == 2);
	assert(solve(2) == 4);
	assert(solve(3) == 4);
	assert(solve(4) == 6);
	assert(solve(5) == 6);
	assert(solve(6) == 8);
	assert(solve(7) == 8);
	assert(solve(8) == 10);

	return 0;
}
