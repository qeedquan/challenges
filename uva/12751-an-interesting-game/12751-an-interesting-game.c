#include <assert.h>

typedef long long vlong;

vlong
triangular(vlong n)
{
	return n * (n + 1) / 2;
}

vlong
solve(vlong N, vlong K, vlong X)
{
	return triangular(N) - triangular(X + K - 1) + triangular(X - 1);
}

int
main()
{
	assert(solve(5, 2, 2) == 10);
	assert(solve(6, 3, 1) == 15);

	return 0;
}
