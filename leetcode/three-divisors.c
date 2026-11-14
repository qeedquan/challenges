/*

Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.

Example 1:

Input: n = 2
Output: false
Explantion: 2 has only two divisors: 1 and 2.

Example 2:

Input: n = 4
Output: true
Explantion: 4 has three divisors: 1, 2, and 4.

Constraints:

    1 <= n <= 10^4

*/

#include <assert.h>
#include <stdbool.h>

bool
threedivisors(int n)
{
	int i, c;

	if (n < 2)
		return false;

	c = 0;
	for (i = 1; i <= n && c < 4; i++)
		c += ((n % i) == 0);
	return c == 3;
}

int
main(void)
{
	assert(threedivisors(1) == false);
	assert(threedivisors(2) == false);
	assert(threedivisors(4) == true);

	return 0;
}
