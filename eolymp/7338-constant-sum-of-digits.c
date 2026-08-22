/*

Find the amount of two-digit numbers that do not change their sum of digits when multiplying a number by a single-digit integer n (n = 0 .. 9).

Input
One integer n (0 ≤ n ≤ 9).

Output
Print the required amount of two-digit numbers.

Examples

Input #1
2

Answer #1
10

*/

#include <assert.h>

int
digsum(int n)
{
	int r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

int
solve(int n)
{
	int c, i;

	c = 0;
	for (i = 10; i < 100; i++) {
		if (digsum(i) == digsum(i * n))
			c += 1;
	}
	return c;
}

int
main()
{
	assert(solve(2) == 10);

	return 0;
}
