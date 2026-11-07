/*

Task
Let's define digit degree of some positive integer as the number of times we need to replace this number with the sum of its digits until we get to a one digit number.

Given an integer n, find its digit degree.

Example
For n = 5, the output should be 0;

For n = 100, the output should be 1;

For n = 91, the output should be 2.

Input/Output

[input] integer n

Constraints: 5 ≤ n ≤ 10^9.

[output] an integer

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
digsum(int n)
{
	int r;

	for (r = 0; n; n /= 10)
		r += n % 10;
	return r;
}

// https://oeis.org/A031286
int
adpdigroot(int n)
{
	int r;

	for (r = 0; n > 9; r++)
		n = digsum(n);
	return r;
}

int
main()
{
	static const int tab[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1,
		1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2,
		2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2,
		2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2
	};

	unsigned i;

	for (i = 0; i < nelem(tab); i++)
		assert(adpdigroot(i) == tab[i]);

	assert(adpdigroot(91) == 2);
	assert(adpdigroot(100) == 1);

	return 0;
}
