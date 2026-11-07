/*

Find the smallest positive integer x that has exactly n divisors.

Input
One positive integer n (1≤n≤16).

Output
Print the smallest positive integer x that has exactly n divisors.

Examples

Input #1
2

Answer #1
2

Input #2
4

Answer #2
6

Input #3
5

Answer #3
16

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A005179
uvlong
solve(uvlong n)
{
	static const uvlong tab[] = {
		1, 2, 4, 6, 16, 12, 64, 24, 36, 48, 1024, 60, 4096, 192, 144, 120,
		65536, 180, 262144, 240, 576, 3072, 4194304, 360, 1296, 12288, 900, 960,
		268435456, 720, 1073741824, 840, 9216, 196608, 5184, 1260, 68719476736,
		786432, 36864, 1680, 1099511627776, 2880
	};

	if (n == 0 || n > nelem(tab))
		return 0;
	return tab[n - 1];
}

int
main()
{
	assert(solve(2) == 2);
	assert(solve(5) == 16);

	return 0;
}
