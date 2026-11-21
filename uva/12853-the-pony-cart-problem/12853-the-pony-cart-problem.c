#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
solve(double D, double N)
{
	double A, R;

	A = D / (N - 1);
	R = 2 * M_PI * (A + D);
	return R;
}

void
test(double D, double N, double R)
{
	double V;

	V = solve(D, N);
	printf("%.3f\n", V);
	assert(fabs(V - R) < 1e-3);
}

int
main()
{
	test(5, 2, 62.832);
	test(4.2, 1.44, 86.365);
	test(8.03, 2.01, 100.408);

	return 0;
}
