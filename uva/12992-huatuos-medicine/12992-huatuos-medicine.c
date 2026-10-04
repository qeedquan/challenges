#include <assert.h>

int
solve(int n)
{
	return (n * 2) - 1;
}

int
main()
{
	assert(solve(2) == 3);

	return 0;
}
