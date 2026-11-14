#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong fibs[301];

void
init()
{
	vlong i, f, g, s;

	fibs[1] = 1;
	fibs[2] = 2;

	f = 1;
	s = 1;
	for (i = 3; i <= 300; i++) {
		g = (f + s) % 100;
		f = s;
		s = g;
		fibs[i] = fibs[i - 1] + g;
	}
}

vlong
calc(vlong x)
{
	vlong n, r;

	if (x < 0)
		return 0;

	if (x <= 300)
		return fibs[x];

	n = x / 300;
	r = fibs[300] * n;
	r += fibs[x % 300];
	return r;
}

vlong
solve(vlong a, vlong b)
{
	return calc(b) - calc(a - 1);
}

int
main()
{
	init();

	assert(solve(1, 3) == 4);
	assert(solve(4, 4) == 3);
	assert(solve(5, 100) == 5068);
	assert(solve(1, 99999) == 4933400);

	return 0;
}
