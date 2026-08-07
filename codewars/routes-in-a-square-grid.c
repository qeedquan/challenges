/*

Given a side length n, traveling only right and down how many ways are there to get from the top left corner to the bottom right corner of an n by n grid?

Your mission is to write a program to do just that!

Add code to route(n) that returns the number of routes for a grid n by n (if n is less than 1 return 0).

Examples:

-100 -> 0

1 -> 2

2 -> 6

20 -> 137846528820

Note: you're traveling on the edges of the squares in the grid not the squares themselves.

PS.If anyone has any suggestions of how to improve this kata please let me know.

*/

#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A000984
vlong
routes(vlong n)
{
	vlong i, r;

	if (n < 0)
		return 0;

	r = 1;
	for (i = 0; i < n; i++)
		r = (r * (2 * n - i)) / (i + 1);
	return r;
}

int
main()
{
	static const vlong tab[] = {
		1, 2, 6, 20, 70, 252, 924, 3432, 12870, 48620, 184756, 705432, 2704156,
		10400600, 40116600, 155117520, 601080390, 2333606220, 9075135300,
		35345263800, 137846528820, 538257874440, 2104098963720, 8233430727600,
		32247603683100, 126410606437752, 495918532948104, 1946939425648112
	};

	unsigned i;

	assert(routes(-100) == 0);
	assert(routes(1) == 2);
	assert(routes(2) == 6);
	assert(routes(20) == 137846528820);

	for (i = 0; i < nelem(tab); i++)
		assert(routes(i) == tab[i]);

	return 0;
}
