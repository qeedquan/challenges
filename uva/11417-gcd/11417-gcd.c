#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
gcd(vlong a, vlong b)
{
	vlong t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

// https://oeis.org/A178881
vlong
solve(vlong n)
{
	vlong i, j, r;

	r = 0;
	for (i = 1; i < n; i++) {
		for (j = i + 1; j <= n; j++)
			r += gcd(i, j);
	}
	return r;
}

int
main()
{
	static const vlong tab[] = {
		0, 1, 3, 7, 11, 20, 26, 38, 50, 67, 77, 105, 117, 142, 172, 204, 220,
		265, 283, 335, 379, 420, 442, 518, 558, 607, 661, 737, 765, 870, 900,
		980, 1052, 1117, 1199, 1331, 1367, 1440, 1526, 1666, 1706, 1859, 1901,
		2025, 2169, 2258, 2304, 2496, 2580, 2725
	};

	size_t i;

	assert(solve(10) == 67);
	assert(solve(100) == 13015);
	assert(solve(500) == 442011);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
