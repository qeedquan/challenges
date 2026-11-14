/*

You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

https://assets.leetcode.com/uploads/2020/03/26/e1.png

Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

Example 1:


Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown.
Example 2:

Input: n = 5000
Output: 30228214


Constraints:

n == grid.length
1 <= n <= 5000

*/

#include <assert.h>

typedef unsigned long long uvlong;

// https://www.geeksforgeeks.org/count-number-of-unique-ways-to-paint-a-n-x-3-grid/
uvlong
ways(uvlong n)
{
	static const uvlong mod = 1000000007ULL;

	uvlong a, b, c, d;
	uvlong i;

	a = b = 6;
	for (i = 1; i < n; i++) {
		c = (a * 3) + (b * 2);
		d = (a * 2) + (b * 2);
		a = c % mod;
		b = d % mod;
	}
	return (a + b) % mod;
}

int
main(void)
{
	assert(ways(1) == 12);
	assert(ways(2) == 54);
	assert(ways(5000) == 30228214ULL);

	return 0;
}
