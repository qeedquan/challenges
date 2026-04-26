#include <assert.h>
#include <stdlib.h>

int
solve(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2)
		return 0;
	if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2))
		return 1;
	return 2;
}

int
main()
{
	assert(solve(4, 4, 6, 2) == 1);
	assert(solve(3, 5, 3, 5) == 0);
	assert(solve(5, 5, 4, 3) == 2);

	return 0;
}
