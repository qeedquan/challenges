/*

You are given an integer array nums.

A subsequence is stable if it does not contain three consecutive elements with the same parity when the subsequence is read in order (i.e., consecutive inside the subsequence).

Return the number of stable subsequences.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: nums = [1,3,5]

Output: 6

Explanation:

    Stable subsequences are [1], [3], [5], [1, 3], [1, 5], and [3, 5].
    Subsequence [1, 3, 5] is not stable because it contains three consecutive odd numbers. Thus, the answer is 6.

Example 2:

Input: nums = [2,3,4,2]

Output: 14

Explanation:

    The only subsequence that is not stable is [2, 4, 2], which contains three consecutive even numbers.
    All other subsequences are stable. Thus, the answer is 14.



Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^5

Hint 1
Any subsequence of length 1 or 2 is always stable.

Hint 2
A subsequence becomes invalid only if you add a third consecutive element of the same parity.

Hint 3
Use DP tracking the last element’s parity and how many consecutive of that parity you have (1 or 2).

Hint 4
For each new number, either start a new subsequence, extend with same parity (if count < 2), or extend with different parity (reset count = 1).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
stable(long *a, size_t n)
{
	static const long mod = 1000000007;

	size_t i, j;
	long p[2][2];

	memset(p, 0, sizeof(p));
	for (i = 0; i < n; i++) {
		j = a[i] & 1;
		p[j][1] = (p[j][1] + p[j][0]) % mod;
		p[j][0] = (p[j][0] + 1 + p[1 ^ j][0] + p[1 ^ j][1]) % mod;
	}
	return (p[0][0] + p[0][1] + p[1][0] + p[1][1]) % mod;
}

int
main()
{
	long a1[] = { 1, 3, 5 };
	long a2[] = { 2, 3, 4, 2 };

	assert(stable(a1, nelem(a1)) == 6);
	assert(stable(a2, nelem(a2)) == 14);

	return 0;
}
