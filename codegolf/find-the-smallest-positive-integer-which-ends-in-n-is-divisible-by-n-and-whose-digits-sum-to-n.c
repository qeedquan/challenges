/*

It's all in the title...
Take as input a positive integer n>=12 and... do what the title says.

Yes, this is on OEIS A187924.

Some test cases

12 -> 912
13 -> 11713
14 -> 6314
15 -> 915
16 -> 3616
17 -> 15317
18 -> 918
19 -> 17119
20 -> 9920
40 -> 1999840
100-> 99999999999100

This is code-golf. Shortest code in bytes wins!

*/

#include <assert.h>
#include <math.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef unsigned long long uvlong;

uvlong
diglen(uvlong n)
{
	uvlong r;

	for (r = 1; n >= 10; n /= 10)
		r++;
	return r;
}

uvlong
digsum(uvlong n)
{
	uvlong r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

// https://oeis.org/A187924
uvlong
digsat(uvlong n)
{
	uvlong i, l, m;

	if (n < 1 || n == 11)
		return 0;

	l = ULLONG_MAX;
	m = pow(10, diglen(n));
	for (i = n; i < l; i += min(n, l - n)) {
		if ((i % m) == n && !(i % n) && digsum(i) == n)
			return i;
	}
	return 0;
}

int
main(void)
{
	static const uvlong tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 910, 0, 912, 11713, 6314, 915, 3616, 15317, 918, 17119, 9920, 18921, 9922, 82823, 19824, 9925, 46826, 18927, 18928, 78329, 99930, 585931, 388832, 1098933, 198934, 289835, 99936, 99937, 478838, 198939, 1999840, 2988941, 2979942, 2979943, 999944, 999945, 4698946, 4779947, 2998848, 2998849, 9999950, 37989951, 29799952, 27999953, 18999954, 109899955};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(digsat(i + 1) == tab[i]);

	return 0;
}
