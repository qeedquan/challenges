/*

You are given a binary array nums.

We call a subarray alternating if no two adjacent elements in the subarray have the same value.

Return the number of alternating subarrays in nums.

Example 1:

Input: nums = [0,1,1,1]

Output: 5

Explanation:

The following subarrays are alternating: [0], [1], [1], [1], and [0,1].

Example 2:

Input: nums = [1,0,1,0]

Output: 10

Explanation:

Every subarray of the array is alternating. There are 10 possible subarrays that we can choose.

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.

Hint 1
Try using dynamic programming.

Hint 2
Let dp[i] be the number of alternating subarrays ending at index i.

Hint 3
The final answer is the sum of dp[i] over all indices i from 0 to n - 1.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
altsub(vlong *a, size_t n)
{
	vlong c, r;
	size_t i;

	c = r = 0;
	for (i = 0; i < n; i++) {
		if (i >= 1 && a[i - 1] == a[i])
			c = 0;
		c += 1;
		r += c;
	}
	return r;
}

int
main()
{
	vlong a1[] = { 0, 1, 1, 1 };
	vlong a2[] = { 1, 0, 1, 0 };

	assert(altsub(a1, nelem(a1)) == 5);
	assert(altsub(a2, nelem(a2)) == 10);

	return 0;
}
