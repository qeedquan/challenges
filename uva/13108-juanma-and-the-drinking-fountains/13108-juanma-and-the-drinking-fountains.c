#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A000127
vlong
solve(vlong n)
{
	vlong r;

	r = (n * n * n * n) - (6 * n * n * n) + (23 * n * n) - (18 * n) + 24;
	r /= 24;
	return r;
}

int
main()
{
	static const vlong tab[] = {
		1, 2, 4, 8, 16, 31, 57, 99, 163, 256, 386, 562, 794, 1093, 1471, 1941,
		2517, 3214, 4048, 5036, 6196, 7547, 9109, 10903, 12951, 15276, 17902,
		20854, 24158, 27841, 31931, 36457, 41449, 46938, 52956, 59536, 66712,
		74519, 82993, 92171, 102091, 112792, 124314, 136698
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
