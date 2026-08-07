#include <assert.h>
#include <stdlib.h>
#include <limits.h>

typedef long long vlong;

vlong
triangular(vlong n)
{
	return n * (n + 1) / 2;
}

vlong
solve(vlong n)
{
	vlong k, x, y;

	n = llabs(n);
	for (k = 1; k <= 1000000000; k++) {
		x = triangular(k);
		y = x - n;
		if (x >= n && !(y % 2))
			return k;
	}
	return -1;
}

int
main()
{
	assert(solve(12) == 7);
	assert(solve(-3646397) == 2701);
	return 0;
}
