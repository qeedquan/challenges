/*

Let's consider a sequence
1,12,123,1234,12345,123456,1234567,12345678,123456789,12345678910,1234567891011,… .

Write a program that determines how many elements of this sequence among first n are divisible by three.

Input
One positive integer n (1≤n≤2^31−1).

Output
Print one number — the answer to the problem.

Examples

Input #1
4

Answer #1
2

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A004523
int
solve(int n)
{
	if (n < 2)
		return 0;
	return ((n / 3) * 2) + ((n % 3) == 2);
}

int
main()
{
	static const int tab[] = {
		0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9, 10, 10, 11, 12, 12, 13,
		14, 14, 15, 16, 16, 17, 18, 18, 19, 20, 20, 21, 22, 22, 23, 24, 24,
		25, 26, 26, 27, 28, 28, 29, 30, 30, 31, 32, 32, 33, 34, 34, 35, 36,
		36, 37, 38, 38, 39, 40, 40, 41, 42, 42, 43, 44, 44, 45, 46
	};

	size_t i;

	assert(solve(4) == 2);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
