/*

Everybody loves pi, but what if pi were a square? Given a number of digits digits, find the smallest integer whose square is greater or equal to the sum of the squares of the first digits digits of pi, including the 3 before the decimal point.

Note: Test cases will not extend beyond 100 digits; the first 100 digits of pi are pasted here for your convenience:

31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

Examples

digits   = 1   #  [3]
expected = 3   #  sqrt(3^2) = 3


digits   = 3   #  [3, 1, 4]
expected = 6   #  sqrt(3^2 + 1^2 + 4^2) = 5.099 --> 6

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
squarepi(unsigned n)
{
	static const int tab[] = {
		3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4,
		3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7,
		5, 1, 0, 5, 8, 2, 0, 9, 7, 4, 9, 4, 4, 5, 9, 2, 3, 0, 7, 8, 1, 6, 4, 0,
		6, 2, 8, 6, 2, 0, 8, 9, 9, 8, 6, 2, 8, 0, 3, 4, 8, 2, 5, 3, 4, 2, 1, 1,
		7, 0, 6, 7, 9
	};

	unsigned i, r;

	if (n >= nelem(tab))
		return -1;

	r = 0;
	for (i = 0; i < n; i++)
		r += tab[i] * tab[i];
	return ceil(sqrt(r));
}

int
main()
{
	assert(squarepi(1) == 3);
	assert(squarepi(3) == 6);
	assert(squarepi(5) == 8);
	assert(squarepi(10) == 15);
	return 0;
}
