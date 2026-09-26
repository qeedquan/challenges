#include <stdio.h>
#include <math.h>

void
solve(int n)
{
	double l;
	double p;
	int e;

	l = log10(2);
	e = floor(-n * l);
	p = pow(10, (-n * l) - e);
	printf("2^%d = %.3lfE%d\n", -n, p, e);
}

int
main()
{
	solve(8271);
	solve(6000);
	solve(1);

	return 0;
}
