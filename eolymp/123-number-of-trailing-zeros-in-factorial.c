/*

Find the number of trailing zeros in n!.

Input
The input contains a single integer n (1≤n≤2⋅10^9).

Output
Print the number of trailing zeros in n!.

Examples

Input #1
7

Answer #1
1

Input #2
12

Answer #2
2

*/

#include <stdio.h>
#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A027868
int
solve(int n)
{
	int r;

	for (r = 0; n >= 5; r += n)
		n /= 5;
	return r;
}

int
main()
{
	static const int tab[] = {
		0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4,
		4, 4, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10,
		10, 10, 10, 10, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 14, 14, 14,
		14, 14, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 18, 18, 18, 18, 18, 19
	};

	size_t i;

	assert(solve(7) == 1);
	assert(solve(12) == 2);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
