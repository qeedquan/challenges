/*

Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays.
If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.

Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.

Constraints:

1 <= nums1.length, nums2.length <= 10^5
1 <= nums1[i], nums2[j] <= 10^9
Both nums1 and nums2 are sorted in non-decreasing order.

Hint 1
Try to use a set.

Hint 2
Otherwise, try to use a two-pointer approach.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
common(int *a1, int *a2, size_t n1, size_t n2)
{
	size_t i, j;

	for (i = j = 0; i < n1 && j < n2;) {
		if (a1[i] < a2[j])
			i++;
		else if (a1[i] > a2[j])
			j++;
		else
			return a1[i];
	}
	return -1;
}

int
main()
{
	int a1[] = { 1, 2, 3 };
	int a2[] = { 2, 4 };

	int a3[] = { 1, 2, 3, 6 };
	int a4[] = { 2, 3, 4, 5 };

	assert(common(a1, a2, nelem(a1), nelem(a2)) == 2);
	assert(common(a3, a4, nelem(a3), nelem(a4)) == 2);

	return 0;
}
