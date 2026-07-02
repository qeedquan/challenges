/*

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

Example 1:

Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Example 2:

Input: nums = [4,14,4]
Output: 4


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^9
The answer for the given input will fit in a 32-bit integer.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
total_hamming_distance(uvlong *nums, size_t len)
{
	uvlong ones[sizeof(uvlong) * CHAR_BIT];
	uvlong val, dist;
	size_t i, j;

	memset(ones, 0, sizeof(ones));
	for (i = 0; i < len; i++) {
		j = 0;
		for (val = nums[i]; val; val >>= 1)
			ones[j++] += val & 1;
	}

	dist = 0;
	for (i = 0; i < nelem(ones); i++)
		dist += ones[i] * (len - ones[i]);
	return dist;
}

int
main(void)
{
	uvlong nums1[] = {4, 14, 2};
	uvlong nums2[] = {4, 14, 4};

	assert(total_hamming_distance(nums1, nelem(nums1)) == 6);
	assert(total_hamming_distance(nums2, nelem(nums2)) == 4);

	return 0;
}
