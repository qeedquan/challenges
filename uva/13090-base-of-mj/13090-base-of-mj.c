#include <assert.h>

typedef long long vlong;

vlong
solve(vlong B, vlong D)
{
	if (D == 0)
		return 0;
	return (B - 1) / D;
}

int
main()
{
	assert(solve(10, 3) == 3);
	assert(solve(20, 3) == 6);

	return 0;
}
