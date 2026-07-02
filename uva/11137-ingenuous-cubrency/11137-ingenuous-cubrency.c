#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
cube(vlong x)
{
	return x * x * x;
}

// https://oeis.org/A003108
vlong
solve(vlong n)
{
	vlong i, j, r, *p;

	if (n < 0)
		return 0;

	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return -1;

	p[0] = 1;
	for (i = 1; cube(i) <= n; i++) {
		for (j = cube(i); j <= n; j++)
			p[j] += p[j - cube(i)];
	}
	r = p[n];

	free(p);
	return r;
}

int
main()
{
	static const vlong tab[] = {
		1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3,
		3, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9,
		9, 9, 10, 10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 14, 15, 15,
		17, 17, 17, 18, 18, 18, 19, 19, 21, 21, 21, 22, 22, 22, 23, 23, 25,
		26, 26, 27, 27, 27, 28
	};

	size_t i;

	assert(solve(10) == 2);
	assert(solve(21) == 3);
	assert(solve(77) == 22);
	assert(solve(9999) == 440022018293);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
