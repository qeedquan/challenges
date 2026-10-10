#include <assert.h>

typedef long long vlong;

vlong
solve(vlong L, vlong R)
{
	return (R / 5) - (L / 5) + 1;
}

int
main()
{
	assert(solve(1, 10) == 3);
	assert(solve(1, 3) == 1);

	return 0;
}
