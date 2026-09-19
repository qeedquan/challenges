/*

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A014080
unsigned
solve(void)
{
	static const unsigned tab[] = {1, 2, 145, 40585};

	unsigned r;
	size_t i;

	r = 0;
	for (i = 2; i < nelem(tab); i++)
		r += tab[i];
	return r;
}

int
main(void)
{
	printf("%u\n", solve());
	return 0;
}
