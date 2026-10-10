#include <stdio.h>
#include <math.h>

double
solve(int n, int m)
{
	double p, r;
	int i;

	r = 0;
	for (i = 1; i < n; i++) {
		p = (i * 1.0 / n) * (n + m);
		r += fabs(p - floor(p + 0.5)) / (n + m);
	}
	return r * 10000;
}

int
main()
{
	printf("%.4f\n", solve(2, 1));
	printf("%.4f\n", solve(2, 3));
	printf("%.4f\n", solve(3, 1));
	printf("%.4f\n", solve(10, 10));

	return 0;
}
