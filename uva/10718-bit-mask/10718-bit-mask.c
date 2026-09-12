#include <assert.h>

typedef long long vlong;

#define bit(x) (1LL << (x))

vlong
solve(vlong N, vlong L, vlong R)
{
	vlong i, l, r, v;

	v = 0;
	for (i = 31; i >= 0; i--) {
		if (N & bit(i)) {
			r = v + bit(i);
			if (r <= L)
				v += bit(i);
		} else {
			l = v + bit(i);
			if (l <= R)
				v += bit(i);
		}
	}
	return v;
}

int
main()
{
	assert(solve(100, 50, 60) == 59);
	assert(solve(100, 50, 50) == 50);
	assert(solve(100, 0, 100) == 27);
	assert(solve(1, 0, 100) == 100);
	assert(solve(15, 1, 15) == 1);

	return 0;
}
