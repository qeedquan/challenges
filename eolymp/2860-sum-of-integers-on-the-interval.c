/*

Find the sum of all integers on the segment from a to b, inclusive.

Input
Two integers a and b, each with absolute value not exceeding 2*10^9.

Output
Print the sum of all integers on the segment from a to b, inclusive.

Examples
Input #1
2 5

Answer #1
14

*/

#include <assert.h>

int
solve(int a, int b)
{
	return (a + b) * (b - a + 1) / 2;
}

int
main()
{
	assert(solve(2, 5) == 14);

	return 0;
}
