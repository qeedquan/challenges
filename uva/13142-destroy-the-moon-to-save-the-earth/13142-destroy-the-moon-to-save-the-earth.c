#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void
solve(double T, double, double D)
{
	double v;

	T = T * 86400;
	D = D * 1000000;
	v = D / T;
	if (floor(v) > 0)
		printf("Remove %.0f tons\n", floor(v));
	else
		printf("Add %.0f tons\n", floor(fabs(v)));
}

int
main()
{
	solve(10950, 1022083, 2500);
	solve(7300, 1022083, 2500);
	solve(356, 1027123, -525);
	solve(12540, 1082726, -2100);
	solve(1000, 1010023, 0);

	return 0;
}
