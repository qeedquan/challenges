/*

The task is simply to see how much faster you can calculate n choose n/2 (for even n) than the builtin function in python. Of course for large n this is a rather large number so rather than output the whole number you should output the sum of the digits. For example, for n = 100000, the answer is 135702. For n=1000000 it is 1354815.

Here is the python code:

from scipy.misc import comb
def sum_digits(n):
   r = 0
   while n:
       r, n = r + n % 10, n / 10
   return r
sum_digits(comb(n,n/2,exact=True))
Your score is (highest n on your machine using your code)/(highest n on your machine using my code). Your code must terminate in 60 seconds or less.

Your program must give the correct output for all even n: 2 <= n <= (your highest n)

You can't use any builtin code or libraries which calculate binomial coefficients or values which can quickly be transformed into binomial coefficients.

You can use any language of your choice.

Leading answer The current leading answer with an amazing 680.09 is by justhalf.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

typedef unsigned long long uvlong;

uvlong
dscbc(uvlong n)
{
	mpz_t x;
	char *s;
	size_t i;
	uvlong r;

	mpz_bin_uiui(x, n, n / 2);
	s = mpz_get_str(NULL, 10, x);

	r = 0;
	for (i = 0; s[i]; i++)
		r += s[i] - '0';

	mpz_clear(x);
	free(s);

	return r;
}

int
main(void)
{
	assert(dscbc(100000ULL) == 135702ULL);
	assert(dscbc(1000000ULL) == 1354815ULL);

	return 0;
}
