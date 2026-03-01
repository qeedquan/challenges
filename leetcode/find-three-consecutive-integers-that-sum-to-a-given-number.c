/*

Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.

Example 1:

Input: num = 33
Output: [10,11,12]
Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].

Example 2:

Input: num = 4
Output: []
Explanation: There is no way to express 4 as the sum of 3 consecutive integers.


Constraints:

0 <= num <= 10^15

*/

#include <assert.h>
#include <string.h>

typedef long long uvlong;

int
sumofthree(uvlong n, uvlong x[3])
{
	if (n % 3)
		return 0;

	x[0] = (n / 3) - 1;
	x[1] = x[0] + 1;
	x[2] = x[0] + 2;
	return 1;
}

void
test(uvlong n, uvlong r[3])
{
	uvlong x[3];
	int s;

	s = sumofthree(n, x);
	if (r == NULL)
		assert(!s);
	else {
		assert(s);
		assert(!memcmp(r, x, sizeof(x)));
	}
}

int
main(void)
{
	test(33, (uvlong[]){10, 11, 12});
	test(4, NULL);
	test(6, (uvlong[]){1, 2, 3});
	test(7, NULL);

	return 0;
}
