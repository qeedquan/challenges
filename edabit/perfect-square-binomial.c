/*

A perfect square binomial is a trinomial that when factored gives you the square of a binomial. For example, the trinomial x²+2x+1 is a perfect square binomial because it factors to (x+1)².

Three integers (a, b, and c) are randomly (and independently) chosen between 1 and n (inclusive) where n is an integer greater than one. Create a function that takes a number n as an argument and returns the number of triplets (a, b, c) such that ax²+bx+c is a perfect square binomial.

Examples
perfectSquare(6) ➞ 3

perfectSquare(30) ➞ 21

perfectSquare(100) ➞ 81

Notes
Trinomials like 2x²+4x+2=2(x+1)² are not considered to be perfect square binomials but trinomials like 4x²+8x+4=(2x+2)² are (in this challenge).

*/

#include <assert.h>
#include <math.h>

int
perfectsquares(int n)
{
	int a, b, c;
	int s, x, y;
	int r;

	r = 0;
	s = sqrt(n);
	for (x = 1; x <= s; x++) {
		for (y = 1; y <= s; y++) {
			a = x * x;
			b = 2 * x * y;
			c = y * y;
			if (a <= n && b <= n && c <= n)
				r++;
		}
	}
	return r;
}

int
main(void)
{
	assert(perfectsquares(6) == 3);
	assert(perfectsquares(30) == 21);
	assert(perfectsquares(100) == 81);
	return 0;
}
