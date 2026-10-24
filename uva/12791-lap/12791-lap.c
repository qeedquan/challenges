#include <assert.h>
#include <math.h>

int
solve(int x, int y)
{
	int d, r;

	d = y - x;
	if (d == 0)
		return 0;

	r = y / d;
	if (y % d)
		r++;
	return r;
}

int
main()
{
	assert(solve(1, 10) == 2);
	assert(solve(4, 8) == 2);
	assert(solve(5, 7) == 4);
	assert(solve(6875, 7109) == 31);

	return 0;
}
