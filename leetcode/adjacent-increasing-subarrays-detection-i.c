/*

Given an array nums of n integers and an integer k, determine whether there exist two adjacent subarrays of length k such that both subarrays are strictly increasing.
Specifically, check if there are two subarrays starting at indices a and b (a < b), where:

Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
The subarrays must be adjacent, meaning b = a + k.
Return true if it is possible to find two such subarrays, and false otherwise.

Example 1:

Input: nums = [2,5,7,8,9,2,3,4,3,1], k = 3

Output: true

Explanation:

The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
The subarray starting at index 5 is [2, 3, 4], which is also strictly increasing.
These two subarrays are adjacent, so the result is true.
Example 2:

Input: nums = [1,2,3,4,4,4,4,5,6,7], k = 5

Output: false

Constraints:

2 <= nums.length <= 100
1 < 2 * k <= nums.length
-1000 <= nums[i] <= 1000

Hint 1
Store the longest decreasing subarray starting and ending at an index.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
increasing(int *a, size_t n, int k)
{
	int c, p, r;
	size_t i;

	r = 0;
	c = 1;
	p = 0;
	for (i = 0; i + 1 < n; i++) {
		if (a[i] < a[i + 1])
			c += 1;
		else {
			p = c;
			c = 1;
		}
		r = max(r, max(c / 2, min(p, c)));
	}
	return r >= k;
}

int
main()
{
	int a1[] = { 2, 5, 7, 8, 9, 2, 3, 4, 3, 1 };
	int a2[] = { 1, 2, 3, 4, 4, 4, 4, 5, 6, 7 };

	assert(increasing(a1, nelem(a1), 3) == true);
	assert(increasing(a2, nelem(a2), 5) == false);

	return 0;
}
