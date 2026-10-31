/*

After planting the trees, the gardener needs to paint them.
He has three colors of paint: white, blue, and orange.
He must paint the N trees so that no two adjacent trees have the same color.
In how many different ways can the gardener paint the trees?

Input
The number of trees N (1≤N≤50).

Output
Output the number of possible ways to paint the trees.

Examples

Input #1
3

Answer #1
12

*/

#include <assert.h>

typedef long long vlong;

// https://oeis.org/A007283
vlong
solve(vlong n)
{
	if (n < 1)
		return 0;
	return 3 << (n - 1);
}

int
main()
{
	assert(solve(3) == 12);

	return 0;
}
