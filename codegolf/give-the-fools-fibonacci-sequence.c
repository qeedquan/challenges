/*

Recently I asked for tips on improving some code-golf of mine. The code was supposed to output every third value of the Fibonacci sequence starting with 2:

2,8,34,144,610,2584,10946,46368,196418,832040
However, I made a mistake in deriving my formula, and my code output a different sequence which is accurate for the first couple terms and then begins to diverge:

2,8,34,140,578,2384,9834,40564,167322,690184
My sequence is defined by:

f(0) = 0
f(1) = 2
f(n) = 2 + 3*f(n-1) + 4*f(n-2) + 2*Sum[i=0, n-3]f[i]

or in terms of my original Haskell code:

z=zipWith(+)
g=z((*2)<$>0:0:g)$z(0:g)$(*2)<$>scanl(+)1g
Your task is to implement a sequence of integers, which has my incorrect sequence as every third value. The other values can be whatever you want them to be, it simply must have the above sequence as every third value. The sequence can begin at the 0th, 1st, or 2nd index, whichever you please.

This is code-golf so the goal is to minimize the size of your program as measured in bytes.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
foolsfib(uvlong n)
{
	uvlong a, b, c, i, p;

	a = 0;
	b = 2;
	p = 0;
	for (i = 0; i < n; i++) {
		c = 2 + (3 * b) + (4 * a) + (2 * p);
		p += a;
		a = b;
		b = c;
	}
	return a;
}

int
main(void)
{
	static const uvlong tab[] = {0, 2, 8, 34, 140, 578, 2384, 9834, 40564ULL, 167322ULL, 690184ULL};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(foolsfib(i) == tab[i]);

	return 0;
}
