/*

Given a positive integer, find its smallest positive integer multiple which is a run of 9 followed by an optional run of 0. In other words, find its smallest positive integer multiple which is matched by the regex /^9+0*$/.

For example, if the given positive integer is 2, then return 90, since 90 is a positive integer multiple of 2 and is the smallest which is matched by the regex /^9+0*$/.

Test cases:

n  f(n)
1  9
2  90
3  9
4  900
5  90
6  90
7  999999
8  9000
9  9
10 90
11 99
12 900
13 999999
14 9999990
15 90
16 90000
This is code-golf. Shortest answer in bytes wins. Standard loopholes apply.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

uvlong
nines(uvlong n)
{
	uvlong b, p, r;

	if (n < 1)
		return 0;

	r = 9;
	for (p = 10; r % n; p *= 10) {
		b = p;
		while ((b - 1) * (r % n) != 0) {
			b /= 10;
			r = p - b;
		}
	}
	return r;
}

int
main()
{
	static const uvlong tab[] = {9, 90, 9, 900, 90, 90, 999999, 9000, 9, 90, 99, 900, 999999, 9999990, 90, 90000};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(nines(i + 1) == tab[i]);

	return 0;
}
