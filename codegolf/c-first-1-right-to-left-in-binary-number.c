/*

I am trying to use C# to find the index of the first 1 (right to left) in the binary representation of a number. For example, since 100 in binary is:

0b1100100
The first 1 is in the third position from the right, so it should yield 3.

234 should yield 2, 0 should yield 0, etc.

Here is my current solution:

k < 1 ? 0 :(int)Math.Log(k & -k, 2) + 1;
Any ways I can make this shorter?

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdbit.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long ulong;

// https://oeis.org/A001511
ulong
ruler(long n)
{
	if (n < 1)
		return 0;
	return log2(n & -n) + 1;
}

int
main()
{
	static const ulong tab[] = {1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1, 5, 1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1, 6, 1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1, 5, 1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1, 7, 1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1, 5, 1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1, 6, 1, 2, 1, 3, 1, 2, 1, 4, 1};

	ulong i;

	for (i = 0; i < nelem(tab); i++)
		assert(ruler(i + 1) == tab[i]);
	for (i = 0; i <= 100000000; i++)
		assert(ruler(i) == stdc_first_trailing_one(i));

	return 0;
}
