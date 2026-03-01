/*

You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

Example 1:

Input: n = 10, t = 2

Output: 10

Explanation:

The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

Example 2:

Input: n = 15, t = 3

Output: 16

Explanation:

The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

Constraints:

1 <= n <= 100
1 <= t <= 10

Hint 1
You have to check at most 10 numbers.

Hint 2
Apply a brute-force approach by checking each possible number.

*/

#include <assert.h>
#include <limits.h>

bool
check(int x, int t)
{
	int r;

	for (r = 1; x > 0; x /= 10)
		r = (r * (x % 10)) % t;
	return r == 0;
}

int
smallest(int n, int t)
{
	for (;;) {
		if (check(n, t))
			break;

		if (n == INT_MAX)
			return -1;
		n += 1;
	}
	return n;
}

int
main()
{
	assert(smallest(10, 2) == 10);
	assert(smallest(15, 3) == 16);

	return 0;
}
