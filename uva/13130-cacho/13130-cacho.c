#include <assert.h>

int
solve(int x1, int x2, int x3, int x4, int x5)
{
	if (x1 + 1 != x2 || x2 + 1 != x3 || x3 + 1 != x4 || x4 + 1 != x5)
		return 'N';
	return 'Y';
}

int
main()
{
	assert(solve(1, 2, 3, 4, 5) == 'Y');
	assert(solve(2, 3, 4, 5, 6) == 'Y');
	assert(solve(1, 4, 4, 4, 5) == 'N');
	assert(solve(1, 3, 4, 5, 6) == 'N');
	assert(solve(1, 2, 2, 3, 6) == 'N');

	return 0;
}
