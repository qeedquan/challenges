/*

Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.

Example 1:

Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
Example 2:

Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].
Example 3:

Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.


Constraints:

n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 10^9

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxdiff(int *a, size_t n)
{
	int m, r;
	size_t i;

	r = -1;
	m = INT_MAX;
	for (i = 0; i < n; i++) {
		if (a[i] >= m)
			r = max(r, a[i] - m);
		m = min(m, a[i]);
	}
	return r;
}

int
main(void)
{
	int a1[] = {7, 1, 5, 4};
	int a2[] = {9, 4, 3, 2};
	int a3[] = {1, 5, 2, 10};

	assert(maxdiff(a1, nelem(a1)) == 4);
	assert(maxdiff(a2, nelem(a2)) == -1);
	assert(maxdiff(a3, nelem(a3)) == 9);

	return 0;
}
