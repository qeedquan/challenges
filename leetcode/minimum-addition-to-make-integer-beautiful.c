/*

You are given two positive integers n and target.

An integer is considered beautiful if the sum of its digits is less than or equal to target.

Return the minimum non-negative integer x such that n + x is beautiful. The input will be generated such that it is always possible to make n beautiful.

Example 1:

Input: n = 16, target = 6
Output: 4
Explanation: Initially n is 16 and its digit sum is 1 + 6 = 7. After adding 4, n becomes 20 and digit sum becomes 2 + 0 = 2. It can be shown that we can not make n beautiful with adding non-negative integer less than 4.

Example 2:

Input: n = 467, target = 6
Output: 33
Explanation: Initially n is 467 and its digit sum is 4 + 6 + 7 = 17. After adding 33, n becomes 500 and digit sum becomes 5 + 0 + 0 = 5. It can be shown that we can not make n beautiful with adding non-negative integer less than 33.

Example 3:

Input: n = 1, target = 1
Output: 0
Explanation: Initially n is 1 and its digit sum is 1, which is already smaller than or equal to target.

Constraints:

    1 <= n <= 10^12
    1 <= target <= 150
    The input will be generated such that it is always possible to make n beautiful.

Hint 1
Think about each digit independently.

Hint 2
Turn the rightmost non-zero digit to zero until the digit sum is greater than target.

*/

#include <assert.h>
#include <math.h>

typedef long long vlong;

vlong
digsum(vlong n)
{
	vlong r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

vlong
beautify(vlong n, vlong t)
{
	vlong l, m, s;

	l = 0;
	m = n;
	s = digsum(n);
	while (s > t) {
		do {
			s -= (m % 10);
			m /= 10;
			l += 1;
		} while ((m % 10) == 9);
		s += 1;
		m += 1;
	}
	return (m * pow(10, l)) - n;
}

int
main()
{
	assert(beautify(16, 6) == 4);
	assert(beautify(467, 6) == 33);
	assert(beautify(1, 1) == 0);

	return 0;
}
