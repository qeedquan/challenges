/*

Misha loved drawing triangles, but he did it in an unusual way.
First, he drew an arbitrary triangle.
Then, he divided each of its sides into n equal parts and drew lines through the division points, parallel to the sides of the triangle.
As a result, a grid of identical triangles was formed.

https://static.eolymp.com/content/e5/e5976b95bb58c51c9e5a2dfeeabbc5d4bba83473.gif

Input
One integer n (0<n<2⋅10^9).

Output
Print the maximum number of equal triangles.

Examples
Input #1
2

Answer #1
4

*/

#include <assert.h>

long
solve(long n)
{
	return n * n;
}

int
main()
{
	assert(solve(2) == 4);

	return 0;
}
