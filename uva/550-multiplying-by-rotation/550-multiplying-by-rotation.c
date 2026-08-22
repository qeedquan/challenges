#include <assert.h>

int
solve(int base, int a, int b)
{
	int s, r;

	if (base == 0)
		return 0;

	r = 1;
	s = a * b;
	for (r = 1; s != a; r++)
		s = ((s % base) * b) + (s / base);
	return r;
}

int
main()
{
	assert(solve(10, 7, 4) == 6);
	assert(solve(9, 7, 4) == 2);
	assert(solve(17, 14, 12) == 4);

	return 0;
}
