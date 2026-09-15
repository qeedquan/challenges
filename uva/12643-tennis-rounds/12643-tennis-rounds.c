#include <assert.h>

int
solve(int n, int x, int y)
{
	int i, r;

	r = 0;
	for (i = 1; i <= n; i++) {
		x = (x + 1) / 2;
		y = (y + 1) / 2;
		r = i;
		if (x == y)
			break;
	}
	return r;
}

int
main()
{
	assert(solve(3, 2, 5) == 3);
	assert(solve(3, 5, 7) == 2);
	assert(solve(2, 1, 2) == 1);
	assert(solve(2, 2, 1) == 1);

	return 0;
}
