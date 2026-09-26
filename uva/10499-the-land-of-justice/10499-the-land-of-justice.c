#include <assert.h>

int
solve(int n)
{
	if (n < 2)
		return 0;
	return 25 * n;
}

int
main()
{
	assert(solve(2) == 50);
	return 0;
}
