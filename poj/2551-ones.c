/*

Description

Given any integer 0 <= n <= 10000 not divisible by 2 or 5, some multiple of n is a number which in decimal notation is a sequence of 1's. How many digits are in the smallest such a multiple of n?

Input

Each line contains a number n.

Output

Output the number of digits.

Sample Input

3
7
9901

Sample Output

3
6
12

Source

Waterloo local 2001.06.02

*/

#include <assert.h>

// https://oeis.org/A099679
int
ones(int n)
{
	int i, v;

	if (n < 1 || !(n % 2) || !(n % 5))
		return 0;

	if (n == 1)
		return 1;

	for (i = v = 1; v; i++)
		v = ((v * 10) + 1) % n;

	return i;
}

int
main(void)
{
	assert(ones(3) == 3);
	assert(ones(7) == 6);
	assert(ones(9901) == 12);

	return 0;
}
