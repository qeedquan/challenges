/*

For the given positive integer n and real number x find the sum

sin(x) + sin(x)^2 + ... + sin(x)^n

Input
Two numbers: one integer n (n≤1000) and one real number x (∣x∣≤1000).

Output
Print the value of the sum with 6 decimal digits.

Examples

Input #1
3 1

Answer #1
2.145368

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
solvebf(int n, double x)
{
	double s, r;
	int i;

	r = 0;
	s = sin(x);
	for (i = 1; i <= n; i++)
		r += pow(s, i);
	return r;
}

double
solve(int n, double x)
{
	double s;

	s = sin(x);
	return (s * (pow(s, n) - 1)) / (s - 1);
}

int
main()
{
	int i;
	double x;

	printf("%f\n", solve(3, 1));

	for (i = 0; i <= 100; i++) {
		for (x = 0; x <= 2 * M_PI; x += 1e-3) {
			assert(fabs(solve(i, x) - solvebf(i, x)) < 1e-8);
		}
	}

	return 0;
}
