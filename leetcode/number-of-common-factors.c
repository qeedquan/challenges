/*

Given two positive integers a and b, return the number of common factors of a and b.

An integer x is a common factor of a and b if x divides both a and b.

Example 1:

Input: a = 12, b = 6
Output: 4
Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.

Example 2:

Input: a = 25, b = 30
Output: 2
Explanation: The common factors of 25 and 30 are 1, 5.

Constraints:

    1 <= a, b <= 1000

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
commonfactors(int a, int b)
{
	int c, i, n;

	c = 0;
	n = min(a, b);
	for (i = 1; i <= n; i++) {
		if ((a % i == 0) && (b % i == 0))
			c++;
	}
	return c;
}

int
main(void)
{
	assert(commonfactors(12, 6) == 4);
	assert(commonfactors(25, 30) == 2);

	return 0;
}
