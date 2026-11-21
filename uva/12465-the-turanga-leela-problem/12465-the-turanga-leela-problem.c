#include <assert.h>
#include <stdlib.h>
#include <math.h>

typedef long long vlong;

vlong
solve(vlong n, vlong m)
{
	vlong c, i, l, r, v;

	r = 1;
	c = llabs(n - m);
	l = sqrt(c);
	for (i = 2; i <= l; i++) {
		v = 0;
		while (!(c % i)) {
			c /= i;
			v += 1;
		}
		r *= v + 1;
	}
	if (c != 1)
		r *= 2;
	return r;
}

int
main()
{
	assert(solve(2, 3) == 1);
	assert(solve(2, 4) == 2);
	assert(solve(5, 7) == 2);
	assert(solve(4, 8) == 3);
	assert(solve(100, 205) == 8);
	assert(solve(33043387, 255936619) == 40);

	return 0;
}
