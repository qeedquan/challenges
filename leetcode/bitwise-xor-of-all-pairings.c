/*

You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. Let there be another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3.

Example 1:

Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation:
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.

Constraints:

    1 <= nums1.length, nums2.length <= 10^5
    0 <= nums1[i], nums2[j] <= 10^9

Hint 1
Think how the count of each individual integer affects the final answer.

Hint 2
If the length of nums1 is m and the length of nums2 is n, then each number in nums1 is repeated n times and each number in nums2 is repeated m times.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
xorarr(int *a, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++)
		r ^= a[i];
	return r;
}

int
xorall(int *a1, int *a2, size_t n1, size_t n2)
{
	int r;

	r = 0;
	if (n2 & 1)
		r ^= xorarr(a1, n1);
	if (n1 & 1)
		r ^= xorarr(a2, n2);
	return r;
}

int
main()
{
	int a1[] = { 2, 1, 3 };
	int a2[] = { 10, 2, 5, 0 };

	int a3[] = { 1, 2 };
	int a4[] = { 3, 4 };

	assert(xorall(a1, a2, nelem(a1), nelem(a2)) == 13);
	assert(xorall(a3, a4, nelem(a3), nelem(a4)) == 0);

	return 0;
}
