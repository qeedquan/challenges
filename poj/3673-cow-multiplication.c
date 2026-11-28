/*

Description

Bessie is tired of multiplying pairs of numbers the usual way, so she invented her own style of multiplication. In her style, A*B is equal to the sum of all possible pairwise products between the digits of A and B. For example, the product 123*45 is equal to 1*4 + 1*5 + 2*4 + 2*5 + 3*4 + 3*5 = 54. Given two integers A and B (1 ≤ A, B ≤ 1,000,000,000), determine A*B in Bessie's style of multiplication.

Input

* Line 1: Two space-separated integers: A and B.

Output

* Line 1: A single line that is the A*B in Bessie's style of multiplication.

Sample Input

123 45

Sample Output

54
Source

USACO 2008 February Bronze

*/

#include <assert.h>
#include <limits.h>

typedef unsigned long long uvlong;

uvlong
digits(uvlong n, uvlong *d)
{
	uvlong i;

	i = 0;
	do {
		d[i++] = n % 10;
		n /= 10;
	} while (n);

	return i;
}

uvlong
bessiemul(uvlong a, uvlong b)
{
	uvlong d1[sizeof(a) * CHAR_BIT];
	uvlong d2[sizeof(b) * CHAR_BIT];
	uvlong n1, n2;
	uvlong i, j, r;

	n1 = digits(a, d1);
	n2 = digits(b, d2);

	r = 0;
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n2; j++)
			r += d1[i] * d2[j];
	}
	return r;
}

int
main(void)
{
	assert(bessiemul(123, 45) == 54);

	return 0;
}
