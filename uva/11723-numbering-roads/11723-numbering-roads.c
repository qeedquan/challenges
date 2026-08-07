#include <assert.h>
#include <math.h>

typedef long long vlong;

vlong
solve(vlong r, vlong n)
{
	vlong x;

	x = ceil(r * 1.0 / n) - 1;
	if (x <= 26)
		return x;
	return -1;
}

int
main()
{
	assert(solve(8, 5) == 1);
	assert(solve(100, 2) == -1);

	return 0;
}
