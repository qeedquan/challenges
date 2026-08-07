/*

Your task
Given a integer input, n (such that n>1), decide whether it can be written as the sum of (at least 2) consecutive square numbers.

Test cases

Truthy:

Input  Explanation
5      1 + 4
13     4 + 9
14     1 + 4 + 9
25     9 + 16
29     4 + 9 + 16
30     1 + 4 + 9 + 16
41     16 + 25
50     9 + 16 + 25

Falsy:

(Any number from 2 to 50 that's not in the truthy test cases)

Clarifications and notes
For reference, here is an ungolfed Python program which will get all the truthy values up to 100.

This is OEIS A174069

Default [decision-problem] rules apply

This is code-golf, so shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// Sum[i=n, n+m] i^2 = 1/6 * (m + 1) * (2m^2 + 6mn + m + 6n^2)
uvlong
sumto(uvlong n, uvlong m)
{
	uvlong a, b, c, d;

	a = 2 * m * m;
	b = 6 * m * n;
	c = m;
	d = 6 * n * n;
	return (m + 1) * (a + b + c + d) / 6;
}

// https://oeis.org/A174069
bool
consq(uvlong x)
{
	uvlong n, m, v;

	for (n = 1; n * n < x; n++) {
		for (m = 1; m < x; m++) {
			v = sumto(n, m);
			if (v > x)
				break;
			if (v == x)
				return true;
		}
	}
	return false;
}

int
main(void)
{
	static const uvlong tab[] = {5, 13, 14, 25, 29, 30, 41, 50, 54, 55, 61, 77, 85, 86, 90, 91, 110, 113, 126, 135, 139, 140, 145, 149, 174, 181, 190, 194, 199, 203, 204, 221, 230, 245, 255, 265, 271, 280, 284, 285, 294, 302, 313, 330, 355, 365, 366, 371, 380, 384, 385, 415, 421, 434, 446, 451};

	uvlong i, n;

	for (i = n = 0; i <= tab[nelem(tab) - 1]; i++) {
		if (consq(i))
			assert(i == tab[n++]);
	}
	assert(n == nelem(tab));

	return 0;
}
