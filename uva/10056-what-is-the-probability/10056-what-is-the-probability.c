#include <stdio.h>
#include <math.h>

double
solve(int n, double p, int i)
{
	if (p == 0)
		return p;
	return pow(1 - p, i - 1) * p / (1 - pow(1 - p, n));
}

int
main()
{
	printf("%.4f\n", solve(2, 1.0 / 6, 1));
	printf("%.4f\n", solve(2, 1.0 / 6, 2));

	return 0;
}
