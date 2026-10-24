#include <assert.h>

typedef long long vlong;

vlong
solve(vlong n)
{
	return n - 1;
}

int
main()
{
	assert(solve(3) == 2);
	assert(solve(2) == 1);

	return 0;
}
