/*

Integer n is given. Print the previous odd integer for n.

Input
One integer n.

Output
Print the odd integer before n.

Examples
Input #1
7

Answer #1
5

Input #2
8

Answer #2
7

*/

#include <assert.h>

int
solve(int n)
{
	return n - 1 - (n & 1);
}

int
main()
{
	assert(solve(7) == 5);
	assert(solve(8) == 7);

	return 0;
}
