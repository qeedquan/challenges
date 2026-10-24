/*

Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.

Return an integer denoting the sum of all numbers in the given range satisfying the constraint.

Example 1:

Input: n = 7
Output: 21
Explanation: Numbers in the range [1, 7] that are divisible by 3, 5, or 7 are 3, 5, 6, 7. The sum of these numbers is 21.
Example 2:

Input: n = 10
Output: 40
Explanation: Numbers in the range [1, 10] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9, 10. The sum of these numbers is 40.
Example 3:

Input: n = 9
Output: 30
Explanation: Numbers in the range [1, 9] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9. The sum of these numbers is 30.


Constraints:

1 <= n <= 10^3

Hint:
Iterate through the range 1 to n and count numbers divisible by either 3, 5, or 7.

*/

#include <assert.h>

int
sums(int m, int n)
{
	int c, l, h;

	l = m;
	h = (n / m) * m;
	c = (h - l) / m + 1;
	return (l + h) * c / 2;
}

int
som(int n)
{
	int r;

	r = sums(3, n) + sums(5, n) + sums(7, n) + sums(105, n);
	r -= (sums(15, n) + sums(21, n) + sums(35, n));
	return r;
}

int
sombf(int n)
{
	int i, r;

	r = 0;
	for (i = 1; i <= n; i++) {
		if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
			r += i;
	}
	return r;
}

int
main(void)
{
	int i;

	assert(som(7) == 21);
	assert(som(10) == 40);
	assert(som(9) == 30);

	for (i = 0; i <= 10000; i++)
		assert(som(i) == sombf(i));

	return 0;
}
