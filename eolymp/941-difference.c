/*

Find the difference between the product and the sum of the digits of a three-digit number.

Input
One three-digit number (positive or negative).

Output
The difference between the product and the sum of the digits of the given number.

Examples
Input #1
198

Answer #1
54

*/

#include <assert.h>

int
digprod(int n)
{
	int r;

	r = 1;
	do {
		r *= n % 10;
		n /= 10;
	} while (n > 0);
	return r;
}

int
digsum(int n)
{
	int r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

// https://oeis.org/A062329 (related)
int
solve(int n)
{
	return digprod(n) - digsum(n);
}

int
main()
{
	assert(solve(198) == 54);
	return 0;
}
