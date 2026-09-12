/*

2 circles can divide the plane into a maximum of 4 regions. What is the maximum number of regions that N circles can divide the plane into?

https://static.e-olymp.com/content/7b/7bc23c0890377fd6cc799a463e6c0859d7233a14.jpg

Input
A single integer N (N≤10^8), representing the number of circles.

Output
A single integer: the maximum number of regions the plane can be divided into.

Examples
Input #1
2

Answer #1
4

*/

#include <assert.h>

int
solve(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (n == 1)
		return 2;
	return n * (n - 1) + 2;
}

int
main()
{
	assert(solve(2) == 4);

	return 0;
}
