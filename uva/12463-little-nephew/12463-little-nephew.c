#include <assert.h>

long
solve(long a, long b, long c, long d, long e)
{
	return a * b * c * (d * d) * (e * e);
}

int
main()
{
	assert(solve(1, 2, 1, 2, 2) == 32);
	assert(solve(1, 1, 1, 1, 1) == 1);
	assert(solve(12, 3, 18, 2, 19) == 935712);
	assert(solve(3, 4, 16, 1, 4) == 3072);

	return 0;
}
