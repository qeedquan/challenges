/*

Given a positive integer k, find the number of triples of positive integers (a,b,c) such that a⋅b⋅c≤k.
Two triples that only differ in the order of numbers are also distinguished.

Input
One integer k (1≤k≤2⋅10^5).

Output
Print the number of triples of positive integers (a,b,c) such that a⋅b⋅c≤k.

Examples

Input #1
2

Answer #1
4

Input #2
10

Answer #2
53

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
solvebf(int n)
{
	int a, b, c, r;

	r = 0;
	for (a = 1; a <= n; a++) {
		for (b = 1; b <= n; b++) {
			for (c = 1; c <= n; c++) {
				if (a * b * c > n)
					break;
				r += 1;
			}
		}
	}
	return r;
}

// https://oeis.org/A061201
int
solve(int n)
{
	int i, k, r;

	r = 0;
	for (i = 1; i <= n; i++) {
		for (k = 1; k <= n; k++)
			r += n / (i * k);
	}
	return r;
}

int
main()
{
	static const int tab[] = {
		1, 4, 7, 13, 16, 25, 28, 38, 44, 53, 56, 74, 77, 86, 95, 110, 113, 131,
		134, 152, 161, 170, 173, 203, 209, 218, 228, 246, 249, 276, 279, 300,
		309, 318, 327, 363, 366, 375, 384, 414, 417, 444, 447, 465, 483, 492,
		495, 540, 546, 564, 573, 591, 594, 624, 633, 663
	};

	size_t i;

	assert(solve(2) == 4);
	assert(solve(10) == 53);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	for (i = 0; i <= 1000; i++)
		assert(solve(i) == solvebf(i));

	return 0;
}
