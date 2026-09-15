#include <assert.h>

typedef long long vlong;

vlong
solve(vlong N, vlong K)
{
	vlong k, r;

	N += 1;
	r = N;
	for (k = 2; N - k > 0 && k <= K; k++)
		r += (N - k) * (k - 1) * 6;
	for (k = 1; N - k > 0 && k <= K; k++)
		r += (N - k) * 6;
	return r;
}

int
main()
{
	assert(solve(0, 0) == 1);
	assert(solve(1, 0) == 2);
	assert(solve(1, 1) == 8);
	assert(solve(2, 1) == 15);
	assert(solve(2000000000, 0) == 2000000001);

	return 0;
}
