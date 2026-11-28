#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
invtri(vlong n)
{
	if (n < 0)
		return 0;
	return (sqrt((8 * n) + 1) - 1) / 2;
}

vlong
tri(vlong n)
{
	return n * (n + 1) / 2;
}

/*

https://oeis.org/A061336
https://en.wikipedia.org/wiki/Fermat_polygonal_number_theorem
Every positive integer can be written as the sum of three or fewer triangular numbers

*/

vlong
solve(vlong n)
{
	vlong i, x, y;

	if (n < 1)
		return 0;

	for (i = 0; i < n; i++) {
		x = tri(i);
		y = tri(invtri(n - x));
		if (x == n || y == n)
			return 1;
		if (x + y == n)
			return 2;
		if (x > n)
			break;
	}
	return 3;
}

int
main()
{
	static const vlong tab[] = {
		0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3, 1, 2, 3, 2, 3, 2, 1, 2, 3,
		2, 2, 3, 2, 1, 2, 2, 2, 3, 3, 2, 3, 1, 2, 2, 2, 3, 3, 2, 2, 3, 1, 2, 3,
		2, 2, 3, 2, 3, 3, 3, 1, 2, 2, 2, 3, 2, 2, 3, 3, 2, 2, 1, 2, 3, 2, 2, 3,
		2, 2, 3, 3, 2, 3, 1, 2, 3, 2, 3, 2, 2, 3, 3, 2, 2, 3, 2, 1, 2, 2, 2, 3,
		3, 2, 3, 2, 2, 2, 2, 3, 3
	};

	size_t i;

	assert(solve(1) == 1);
	assert(solve(2) == 2);
	assert(solve(6) == 1);
	assert(solve(10) == 1);
	assert(solve(20) == 2);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
