/*

You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.

Example 1:
Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

Example 2:
Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
max_sum_array(int *nums, size_t size)
{
	int max, sum;
	size_t i;

	max = nums[0];
	sum = nums[0];
	for (i = 1; i < size; i++) {
		if (sum < 0)
			sum = nums[i];
		else
			sum += nums[i];
		if (max < sum)
			max = sum;
	}
	return max;
}

int
min_sum_array(int *nums, size_t size)
{
	int min, sum;
	size_t i;

	min = nums[0];
	sum = nums[0];
	for (i = 1; i < size; i++) {
		if (sum > 0)
			sum = nums[i];
		else
			sum += nums[i];
		if (min > sum)
			min = sum;
	}
	return min;
}

int
max_absolute_sum(int *nums, size_t size)
{
	return max(max_sum_array(nums, size), abs(min_sum_array(nums, size)));
}

int
main()
{
	int nums1[] = { 1, -3, 2, 3, -4 };
	int nums2[] = { 2, -5, 1, -4, 3, -2 };

	assert(max_absolute_sum(nums1, nelem(nums1)) == 5);
	assert(max_absolute_sum(nums2, nelem(nums2)) == 8);

	return 0;
}
