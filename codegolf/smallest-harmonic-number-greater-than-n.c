/*

The sequence of Harmonic numbers are the sums of the reciprocals of the first k natural numbers (not including zero):

H[k] = 1 + 1/2 + 1/3 + 1/4 ... = Sum[i=1, k] 1/i

Your task is to implement the sequence of numbers a(n) = the smallest k that the k'th Harmonic number is greater than n. You must output k, not the Harmonic number itself.

The first few terms zero-indexed are:

1, 2, 4, 11, 31, 83, 227, 616, 1674, 4550, 12367, 33617, ...
Your submission may fail to work for larger numbers due to language limitations as long as the algorithm works theoretically on arbitrary indices. Keep in mind that Abusing native number types to trivialize a problem is banned.

This is OEIS A002387.

This is a code-golf challenge; the shortest code wins. Standard [sequence] rules apply.

Meaningless brownie points for beating or matching my 15 bytes of Uiua :)

*/

#include <assert.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A002387
uvlong
harmonic(uvlong n)
{
	uvlong i;
	double v;

	v = 0;
	for (i = 1; i < ULLONG_MAX; i++) {
		v += 1.0 / i;
		if (v > n)
			return i;
	}
	return 0;
}

int
main()
{
	static const uvlong tab[] = {1, 2, 4, 11, 31, 83, 227, 616, 1674, 4550, 12367, 33617, 91380, 248397, 675214, 1835421, 4989191, 13562027, 36865412, 100210581};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(harmonic(i) == tab[i]);

	return 0;
}
