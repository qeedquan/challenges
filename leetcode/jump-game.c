/*

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
canjump(unsigned *a, size_t n)
{
	size_t i, r;

	for (i = r = 0; i < n && i <= r; i++)
		r = max(r, i + a[i]);
	return i == n;
}

int
main(void)
{
	unsigned a1[] = {2, 3, 1, 1, 4};
	unsigned a2[] = {3, 2, 1, 0, 4};

	assert(canjump(a1, nelem(a1)) == true);
	assert(canjump(a2, nelem(a2)) == false);

	return 0;
}
