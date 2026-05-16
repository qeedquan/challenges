#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef long long vlong;

vlong
solve(vlong n)
{
	return ceil((3 + sqrt((8 * n) + 9)) / 2);
}

int
main()
{
	assert(solve(10) == 7);
	assert(solve(100) == 16);
	assert(solve(1000) == 47);

	return 0;
}
