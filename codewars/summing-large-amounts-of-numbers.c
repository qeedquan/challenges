/*

For all x in the range of integers [0, 2 ** n), let y[x] be the binary exclusive-or of x and x // 2. Find the sum of all numbers in y.

Write a function sum_them that, given n, will return the value of the above sum.

This can be implemented a simple loop as shown in the initial code. But once n starts getting to higher numbers, such as 2000 (which will be tested), the loop is too slow.

There is a simple solution that can quickly find the sum. Find it!

Assume that n is a nonnegative integer.

Hint: The complete solution can be written in two lines.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
slanbf(uvlong n)
{
	uvlong i, r;

	r = 0;
	n = 1ULL << n;
	for (i = 0; i < n; i++)
		r += i ^ (i >> 1);
	return r;
}

// https://oeis.org/A006516
uvlong
slan(uvlong n)
{
	uvlong x, y;

	if (n == 0)
		return 0;

	x = 1ULL << (n - 1);
	y = (1ULL << n) - 1;
	return x * y;
}

int
main()
{
	static const uvlong tab[] = {
	    0,
	    1,
	    6,
	    28,
	    120,
	    496,
	    2016,
	    8128,
	    32640,
	    130816,
	    523776,
	    2096128,
	    8386560,
	    33550336,
	    134209536,
	    536854528,
	    2147450880,
	    8589869056,
	    34359607296,
	    137438691328,
	    549755289600,
	    2199022206976,
	    8796090925056,
	    35184367894528,
	    140737479966720,
	    562949936644096,
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++) {
		assert(slan(i) == tab[i]);
		assert(slanbf(i) == tab[i]);
	}
	return 0;
}
