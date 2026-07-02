#include <assert.h>

typedef long long vlong;

vlong
solve(vlong n)
{
	if (n < 3)
		return 0;
	return (n - 2) * (n - 1) / 2;
}

int
main()
{
	assert(solve(1) == 0);
	assert(solve(2) == 0);
	assert(solve(3) == 1);

	return 0;
}
