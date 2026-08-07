/*

Given a grid of points with integer coordinates, determine the maximum number of such points that can be covered by a square with side length N.

Input
A single integer N (1≤N≤10000) — the side length of the square.

Output
Output the maximum number K of points with integer coordinates that can be covered by the square.

Examples
Input #1
1

Answer #1
4

*/

#include <assert.h>

int
solve(int n)
{
	if (n < 1)
		return 0;
	return (n + 1) * (n + 1);
}

int
main()
{
	assert(solve(1) == 4);

	return 0;
}
