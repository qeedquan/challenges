#include <assert.h>

typedef long long vlong;

#define bit(x) (1LL << (x))

vlong
solve(vlong P, vlong Q)
{
	vlong d, r;

	r = d = 0;
	while (P >= 2 && Q >= 1) {
		r |= bit(d) | bit(d + 2);
		d += 3;
		P -= 2;
		Q -= 1;
	}

	if (P == 1 && Q >= 1) {
		r |= bit(d);
		P -= 1;
		Q -= 1;
		d += 2;
	}

	while (P) {
		r = (r << 1) | 1;
		d += 1;
		P -= 1;
	}

	return r;
}

int
main()
{
	assert(solve(4, 3) == 45);
	assert(solve(1, 1) == 1);
	assert(solve(3, 2) == 13);

	return 0;
}
