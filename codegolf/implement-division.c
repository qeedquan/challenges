/*

Implement a division algorithm in your favourite language which handles integer division. It need only handle positive numbers - but bonus points if it handles negative and mixed-sign division, too. Results are rounded down for fractional results.

The program may not contain the /, \, div or similar operators. It must be a routine which does not use native division capabilities of the language.

You only need to handle up to 32-bit division. Using repeated subtraction is not allowed.

Input

Take two inputs on stdin separated by new lines or spaces (your choice)

740
2

Output

In this case, the output would be 370.

The solution which is the shortest wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

unsigned
udiv(unsigned x, unsigned y)
{
	unsigned z;

	z = exp(log(x) - log(y));
	if ((z * y) + y <= x)
		z++;
	return z;
}

int
main(void)
{
	unsigned x, y, N;

	N = 10000;
	for (x = 0; x <= N; x++) {
		for (y = 1; y <= N; y++) {
			assert(udiv(x, y) == (x / y));
		}
	}
	return 0;
}
