#include <assert.h>

typedef long long vlong;

vlong
triangular(vlong n)
{
	return n * (n + 1) / 2;
}

vlong
solve(vlong a, vlong b)
{
	if (a < 1 || b < 1)
		return 0;
	return triangular(a - 1) * triangular(b - 1);
}

int
main()
{
	assert(solve(2, 2) == 1);
	assert(solve(2, 3) == 3);
	assert(solve(3, 3) == 9);

	return 0;
}
