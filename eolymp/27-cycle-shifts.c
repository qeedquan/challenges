/*

Let us write the integer n in binary notation and generate all its left cyclic shifts, moving the first digit to the end each time.

For example, if n=11, in binary this is 1011. Its cyclic shifts are 0111, 1110, 1101, 1011.
The maximum value m among all obtained numbers is 1110 in base 2 = 14 in base 10.

Find the maximum value m that can be obtained from all left cyclic shifts of the binary representation of the given n.

Input
One integer n (1≤n≤2⋅10^9).

Output
One integer m.

Examples

Input #11
11

Answer #11
14

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

// https://oeis.org/A163380
uvlong
solve(uvlong n)
{
	uvlong p, r, t;

	p = 1;
	for (t = n; t; t >>= 1)
		p <<= 1;

	r = t = n;
	do {
		n <<= 1;
		n = (n % p) + (n >= p);
		r = max(r, n);
	} while (t != n);

	return r;
}

int
main()
{
	static const uvlong tab[] = {
		1, 2, 3, 4, 6, 6, 7, 8, 12, 10, 14, 12, 14, 14, 15, 16, 24, 20, 28,
		20, 26, 26, 30, 24, 28, 26, 30, 28, 30, 30, 31, 32, 48, 40, 56, 36,
		50, 52, 60, 40, 52, 42, 58, 50, 54, 58, 62, 48, 56, 50, 60, 52, 58,
		54, 62, 56, 60, 58, 62, 60, 62, 62, 63, 64, 96, 80, 112, 72, 98, 104, 120
	};

	uvlong i;

	assert(solve(11) == 14);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
