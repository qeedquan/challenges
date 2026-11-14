/*

Given usual Fibonacci Sequence, starting with 0 and 1:

0 1 1 2 3 5 8 13 21 34 ...
and some value M you will be asked to find the index of the first non-zero member of this list, which is evenly divisible by this M, e.g. if you are given M = 17 the answer is 9 (the index of the element 34).

Input data in the first line will contain the number of test-cases.
Next line will contain exactly this of divisors M (not exceeding 10000) for which you should give answers.
Answer should contain indices of members of Fibonacci Sequence, separated by spaces.

Example:

input data:
3
17 12 61

answer:
9 12 15

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A001177
uvlong
solve(uvlong n)
{
	uvlong a, b, c, i;

	if (n < 1)
		return 0;
	if (n == 1)
		return 1;

	a = 0;
	b = 1;
	i = 0;
	for (;;) {
		if (i > 0 && a == 0)
			break;

		c = (a + b) % n;
		a = b;
		b = c;
		i += 1;
	}
	return i;
}

int
main()
{
	static const uvlong tab[] = {
		1, 3, 4, 6, 5, 12, 8, 6, 12, 15, 10, 12, 7, 24, 20, 12, 9, 12, 18, 30,
		8, 30, 24, 12, 25, 21, 36, 24, 14, 60, 30, 24, 20, 9, 40, 12, 19, 18,
		28, 30, 20, 24, 44, 30, 60, 24, 16, 12, 56, 75, 36, 42, 27, 36, 10,
		24, 36, 42, 58, 60, 15, 30, 24, 48, 35, 60, 68, 18, 24, 120
	};

	uvlong i;

	assert(solve(17) == 9);
	assert(solve(12) == 12);
	assert(solve(61) == 15);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
