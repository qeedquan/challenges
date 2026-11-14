#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
solve(double m)
{
	static const size_t coins[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

	size_t i, j, n;
	vlong *p, r;

	if (m < 0)
		return -EINVAL;

	n = round(m * 100);
	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return -errno;

	p[0] = 1;
	for (i = 0; i < nelem(coins); i++) {
		for (j = coins[i]; j <= n; j++)
			p[j] += p[j - coins[i]];
	}
	r = p[n];

	free(p);
	return r;
}

int
main()
{
	assert(solve(0.20) == 4);
	assert(solve(2.00) == 293);

	return 0;
}
