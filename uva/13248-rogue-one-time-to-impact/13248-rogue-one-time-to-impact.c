#include <assert.h>

int
solve(double A, double B)
{
	return ((A * 10) / (B - A)) + 10;
}

int
main()
{
	assert(solve(10, 20) == 20);
	assert(solve(10, 21) == 19);
	assert(solve(10, 19) == 21);

	return 0;
}
