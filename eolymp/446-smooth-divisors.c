/*

A positive integer m is called a smooth divisor of a number n if, when dividing n by m, the quotient and the remainder are equal.
Given a positive integer n, find the number of its smooth divisors.

Input
One positive integer n (1≤n≤10^6).

Output
Print a single number — the number of smooth divisors of n.

Examples
Input #1
20

Answer #1
2

*/

#include <stdio.h>
#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A033831
int
solve(int n)
{
	int i, r;

	r = 0;
	for (i = 1; i <= n; i++) {
		if (n / i == n % i)
			r++;
	}
	return r;
}

int
main()
{
	static const int tab[] = {
		0, 0, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 2, 2, 1, 3, 1, 2, 2, 2, 1,
		4, 1, 2, 2, 3, 1, 3, 1, 3, 2, 2, 2, 4, 1, 2, 2, 4, 1, 3, 1, 3, 3, 2,
		1, 5, 1, 3, 2, 3, 1, 4, 2, 3, 2, 2, 1, 6, 1, 2, 3, 3, 2, 4, 1, 3, 2,
		4, 1, 5, 1, 2, 3, 3, 2, 4, 1, 5, 2, 2, 1, 6, 2, 2, 2, 4, 1, 5, 2, 3,
		2, 2, 2, 6, 1, 3, 3, 4, 1, 4, 1, 4, 4
	};

	size_t i;

	assert(solve(20) == 2);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
