/*

Calculate the ratio of the product of the digits of a natural number to the sum of its digits.

Input
A single natural number n, not exceeding 2⋅10^9.

Output
Output the ratio, calculated to 3 decimal places.

Examples
Input #1
36

Answer #1
2.000

*/

#include <stdio.h>

double
solve(unsigned n)
{
	unsigned d, p, s;

	s = 0;
	p = 1;
	do {
		d = n % 10;
		s += d;
		p *= d;
		n /= 10;
	} while (n);

	return (p * 1.0) / s;
}

int
main()
{
	printf("%f\n", solve(36));

	return 0;
}
