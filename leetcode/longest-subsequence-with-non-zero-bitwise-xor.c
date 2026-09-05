/*

You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

Example 1:

Input: nums = [1,2,3]

Output: 2

Explanation:

One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.

Example 2:

Input: nums = [2,3,4]

Output: 3

Explanation:

The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
longest(int *a, size_t n)
{
	size_t c, i;
	int x;

	x = 0;
	for (c = i = 0; i < n; i++) {
		x ^= a[i];
		if (!a[i])
			c += 1;
	}
	if (x)
		return n;
	if (c == n)
		return 0;
	return n - 1;
}

int
main()
{
	int a1[] = { 1, 2, 3 };
	int a2[] = { 2, 3, 4 };

	assert(longest(a1, nelem(a1)) == 2);
	assert(longest(a2, nelem(a2)) == 3);

	return 0;
}
