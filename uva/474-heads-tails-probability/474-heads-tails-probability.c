#include <stdio.h>
#include <math.h>

void
solve(int n)
{
	int b;

	b = floor(log10(2) * (-n));
	printf("2^-%d = %.3lfe%d\n", n, pow(10, -(log10(2) * n) - b), b);
}

int
main()
{
	solve(1);
	solve(100);
	solve(10000);
	solve(1000000);

	return 0;
}
