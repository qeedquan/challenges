/*

https://static.e-olymp.com/content/76/76e29348eff0e9f222e721b993b5342d4368cba4.gif

Kleptyk, known from the Match Model problem, decided to demonstrate his skills again. He began constructing triangles using matches.

What is the minimal number of matches needed to form n triangles, if each side of a triangle is formed by a single match?

Input
The input contains a single integer n (n<2⋅10^9).

Output
Print the minimal number of matches required to form n triangles.

Examples

Input #1
2

Answer #1
5

*/

#include <assert.h>

int
solve(int n)
{
	return (2 * n) + 1;
}

int
main()
{
	assert(solve(1) == 3);
	assert(solve(2) == 5);
	assert(solve(3) == 7);

	return 0;
}
