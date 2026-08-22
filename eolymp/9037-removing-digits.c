/*

You are given an integer n. On each step, you may subtract from it any one-digit number that appears in it.

How many steps are required to make the number equal to 0?

Input
One integer n (1 ≤ n ≤ 10^6).

Output
Print the minimum number of steps to get the number 0.

Examples
Input #1
27
Answer #1
5

Note
For n = 27

An optimal solution is 27 → 20 → 18 → 10 → 9 → 0.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxdigit(int n)
{
	int r;

	for (r = 0; n > 0; n /= 10)
		r = max(r, n % 10);
	return r;
}

// https://oeis.org/A354760
int
solve(int n)
{
	int r;

	for (r = 0; n > 0; r++)
		n -= maxdigit(n);
	return r;
}

int
main()
{
	static const int tab[] = {
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5,
		5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9,
		9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12,
		12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13
	};

	size_t i;

	assert(solve(27) == 5);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
