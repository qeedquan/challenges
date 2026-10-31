#include <assert.h>

typedef long long vlong;

vlong
solve(vlong L, vlong M, vlong N)
{
	static const vlong mod = 10000000000007LL;

	vlong L2, i, r, w;

	r = 0;
	w = 1;
	L2 = L * L;
	for (i = 1; i < M; i++) {
		w *= (L2 - i + 1);
		w %= mod;
	}
	for (i = M; i <= N; i++) {
		w *= (L2 - i + 1);
		w %= mod;
		r += w;
		r %= mod;
	}
	return r;
}

int
main()
{
	assert(solve(3, 4, 9) == 985824);
	assert(solve(3, 1, 9) == 986409);

	return 0;
}
