#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define sqr(x) ((x) * (x))

double
solve(int n)
{
	if (n < 2)
		return 0;
	return ((4 * n) - 4) + (M_SQRT2 * sqr(n - 2));
}

int
main()
{
	printf("%f\n", solve(1));
	printf("%f\n", solve(2));
	printf("%f\n", solve(3));

	return 0;
}
