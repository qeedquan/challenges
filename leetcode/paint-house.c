/*

There are a row of n houses, each house can be painted with one of the three colors: red, blue or green.
The cost of painting each house with a certain color is different.
You have to paint all the houses such that no two adjacent houses have the same color.Coatings & Adhesives

The cost of painting each house with a certain color is represented by a n x 3 cost matrix.
For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
             Minimum cost: 2 + 5 + 3 = 10.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
mincost(int c[][3], size_t n)
{
	int r, g, b;
	int R, G, B;
	size_t i;

	r = g = b = 0;
	for (i = 0; i < n; i++) {
		R = r;
		G = g;
		B = b;
		r = min(G, B) + c[i][0];
		g = min(R, B) + c[i][1];
		b = min(R, G) + c[i][2];
	}
	return min(r, min(g, b));
}

int
main()
{
	int c1[][3] = { { 17, 2, 17 }, { 16, 16, 5 }, { 14, 3, 19 } };

	assert(mincost(c1, nelem(c1)) == 10);

	return 0;
}
