#include <assert.h>

int
solve(int h1, int m1, int h2, int m2)
{
	int t1, t2;

	t1 = (h1 * 60) + m1;
	t2 = (h2 * 60) + m2;

	if (t2 >= t1)
		return t2 - t1;
	return 1440 - (t1 - t2);
}

int
main()
{
	assert(solve(1, 5, 3, 5) == 120);
	assert(solve(23, 59, 0, 34) == 35);
	assert(solve(21, 33, 21, 10) == 1417);

	return 0;
}
