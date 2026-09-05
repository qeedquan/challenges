/*

Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.
Example 3:

Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).

Constraints:

1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4

Hint 1
Represent the state as DP[pos][mod]: maximum possible sum starting in the position "pos" in the array where the current sum modulo 3 is equal to mod.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxsumdiv3(int *a, size_t n)
{
	int p[3], q[3];
	size_t i, j;

	memset(p, 0, sizeof(p));
	for (i = 0; i < n; i++) {
		memcpy(q, p, sizeof(p));

		for (j = 0; j < 3; j++)
			p[j] += a[i];

		for (j = 0; j < 3; j++)
			q[p[j] % 3] = max(q[p[j] % 3], p[j]);

		memcpy(p, q, sizeof(p));
	}
	return p[0];
}

int
main()
{
	int a1[] = { 3, 6, 5, 1, 8 };
	int a2[] = { 4 };
	int a3[] = { 1, 2, 3, 4, 4 };

	assert(maxsumdiv3(a1, nelem(a1)) == 18);
	assert(maxsumdiv3(a2, nelem(a2)) == 0);
	assert(maxsumdiv3(a3, nelem(a3)) == 12);

	return 0;
}
