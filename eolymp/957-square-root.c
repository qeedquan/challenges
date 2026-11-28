/*

Find the square root of the sum of the digits of a three-digit number.

Input
One positive three-digit integer is given.

Output
Print the square root of the sum of the digits, rounded to 3 digits after the decimal point.

Examples

Input #1
178

Answer #1
4.000

*/

#include <stdio.h>
#include <math.h>

int
digsum(int n)
{
	int r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

double
solve(int n)
{
	return sqrt(digsum(n));
}

int
main()
{
	printf("%.3f\n", solve(178));

	return 0;
}
