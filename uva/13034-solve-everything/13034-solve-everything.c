#include <assert.h>

bool
solve(int x[13])
{
	int i, r;

	r = 1;
	for (i = 0; i < 13; i++)
		r &= (x[i] > 0);
	return r;
}

int
main()
{
	int x1[] = { 128, 64, 48, 32, 24, 16, 12, 8, 6, 4, 3, 2, 1 };
	int x2[] = { 128, 64, 48, 32, 24, 16, 12, 8, 6, 4, 2, 1, 0 };

	assert(solve(x1) == true);
	assert(solve(x2) == false);

	return 0;
}
