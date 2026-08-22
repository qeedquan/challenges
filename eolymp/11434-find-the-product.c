/*

For the given positive integer n find the product

(1 + 1/1) * (1 + 1/2) * ... * (1 + 1/n)

Input
One positive integer n(n≤1000).

Output
Print the value of the product with 6 decimal digits.

Examples

Input #1
3

Answer #1
4.000000

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
solvebf(int n)
{
	double r;
	int i;

	if (n < 0)
		return 0;

	r = 1;
	for (i = 1; i <= n; i++)
		r *= (1 + (1.0 / i));
	return r;
}

double
solve(int n)
{
	if (n < 0)
		return 0;
	return n + 1;
}

int
main()
{
	int i;

	printf("%f\n", solve(3));

	for (i = 0; i <= 1000; i++)
		assert(fabs(solve(i) - solvebf(i)) < 1e-10);

	return 0;
}
