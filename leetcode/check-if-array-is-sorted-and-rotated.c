/*

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].

Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

Hint 1
Brute force and check if it is possible for a sorted array to start from each position.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
check(int *a, size_t n)
{
	size_t c, i, j;

	for (c = i = 0; i < n; i++) {
		j = (i + 1) % n;
		if (a[i] > a[j]) {
			c += 1;
			if (c > 1)
				return false;
		}
	}
	return true;
}

int
main()
{
	int a1[] = { 3, 4, 5, 1, 2 };
	int a2[] = { 2, 1, 3, 4 };
	int a3[] = { 1, 2, 3 };

	assert(check(a1, nelem(a1)) == true);
	assert(check(a2, nelem(a2)) == false);
	assert(check(a3, nelem(a3)) == true);

	return 0;
}
