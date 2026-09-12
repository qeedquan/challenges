/*

Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.

Example 2:

Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.

Example 3:

Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

Hint 1
For each zero, you can calculate the number of zero-filled subarrays that end on that index, which is the number of consecutive zeros behind the current element + 1.

Hint 2
Maintain the number of consecutive zeros behind the current element, count the number of zero-filled subarrays that end on each index, sum it up to get the answer.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
zerofilled(vlong *a, size_t n)
{
	vlong r, p;
	size_t i;

	r = 0;
	p = -1;
	for (i = 0; i < n; i++) {
		if (a[i])
			p = i;
		else
			r += i - p;
	}
	return r;
}

int
main()
{
	vlong a1[] = { 1, 3, 0, 0, 2, 0, 0, 4 };
	vlong a2[] = { 0, 0, 0, 2, 0, 0 };
	vlong a3[] = { 2, 10, 2019 };

	assert(zerofilled(a1, nelem(a1)) == 6);
	assert(zerofilled(a2, nelem(a2)) == 9);
	assert(zerofilled(a3, nelem(a3)) == 0);

	return 0;
}
