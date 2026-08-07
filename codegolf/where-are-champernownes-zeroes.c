/*

Consider the infinite string of all nonnegative decimal integers concatenated together in order (akin to Champernowne's constant):

0123456789101112131415161718192021222324252627282930...979899100101102103...
Write a program or function that takes in a nonnegative integer that indexes (0-based) into this infinite string. Output a truthy value if the digit indexed is 0, otherwise output a falsy value if the digit is 1-9.

The shortest code in bytes wins.

The first 25 truthy-producing inputs are:

0
11
31
51
71
91
111
131
151
171
191
192
194
197
200
203
206
209
212
215
218
222
252
282
312

Kudos if your program is memory effecient, but this is not a requirement.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A031287
bool
dotz(uvlong n)
{
	char b[sizeof(n) * CHAR_BIT];
	uvlong i, m;

	for (i = 0; i < ULLONG_MAX; i++) {
		m = snprintf(b, sizeof(b), "%llu", i);
		if (n < m)
			return b[n] == '0';
		n -= m;
	}
	return false;
}

uvlong
gen(uvlong n, uvlong *r)
{
	uvlong i, l;

	for (i = l = 0; l < n && i < ULLONG_MAX; i++) {
		if (dotz(i))
			r[l++] = i;
	}
	return l;
}

int
main(void)
{
	static const uvlong tab[] = {0, 11, 31, 51, 71, 91, 111, 131, 151, 171, 191, 192, 194, 197, 200, 203, 206, 209, 212, 215, 218, 222, 252, 282, 312, 342, 372, 402, 432, 462, 491, 492, 494, 497, 500, 503, 506, 509, 512, 515, 518, 522, 552, 582, 612, 642, 672, 702};

	uvlong p[128];
	uvlong n;

	n = gen(nelem(tab), p);
	assert(n == nelem(tab));
	assert(!memcmp(p, tab, sizeof(tab)));

	return 0;
}
