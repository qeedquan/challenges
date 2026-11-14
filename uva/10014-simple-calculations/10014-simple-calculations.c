#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
solve(size_t n, double a, double b, double *c)
{
	size_t i;

	for (i = 0; i < n; i++)
		b -= 2 * (n - i) * c[i];
	b += n * a;
	b /= (n + 1);
	return b;
}

int
main()
{
	double c[] = { 10.15 };

	printf("%f\n", solve(nelem(c), 50.50, 25.50, c));

	return 0;
}
