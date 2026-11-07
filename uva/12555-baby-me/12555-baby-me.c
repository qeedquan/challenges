#include <assert.h>

double
solve(double a, double b)
{
	return (a * 0.5) + (b * 0.05);
}

int
main()
{
	assert(solve(5, 2) == 2.6);
	assert(solve(7, 3) == 3.65);
	assert(solve(6, 0) == 3);

	return 0;
}
