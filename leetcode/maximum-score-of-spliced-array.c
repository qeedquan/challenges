/*

You are given two 0-indexed integer arrays nums1 and nums2, both of length n.

You can choose two integers left and right where 0 <= left <= right < n and swap the subarray nums1[left...right] with the subarray nums2[left...right].

For example, if nums1 = [1,2,3,4,5] and nums2 = [11,12,13,14,15] and you choose left = 1 and right = 2, nums1 becomes [1,12,13,4,5] and nums2 becomes [11,2,3,14,15].
You may choose to apply the mentioned operation once or not do anything.

The score of the arrays is the maximum of sum(nums1) and sum(nums2), where sum(arr) is the sum of all the elements in the array arr.

Return the maximum possible score.

A subarray is a contiguous sequence of elements within an array. arr[left...right] denotes the subarray that contains the elements of nums between indices left and right (inclusive).

Example 1:

Input: nums1 = [60,60,60], nums2 = [10,90,10]
Output: 210
Explanation: Choosing left = 1 and right = 1, we have nums1 = [60,90,60] and nums2 = [10,60,10].
The score is max(sum(nums1), sum(nums2)) = max(210, 80) = 210.

Example 2:

Input: nums1 = [20,40,20,70,30], nums2 = [50,20,50,40,20]
Output: 220
Explanation: Choosing left = 3, right = 4, we have nums1 = [20,40,20,40,20] and nums2 = [50,20,50,70,30].
The score is max(sum(nums1), sum(nums2)) = max(140, 220) = 220.

Example 3:

Input: nums1 = [7,11,13], nums2 = [1,1,1]
Output: 31
Explanation: We choose not to swap any subarray.
The score is max(sum(nums1), sum(nums2)) = max(31, 3) = 31.

Constraints:

n == nums1.length == nums2.length
1 <= n <= 10^5
1 <= nums1[i], nums2[i] <= 10^4

Hint 1
Think on Dynamic Programming.

Hint 2
First assume you will be taking the array a and choose some subarray from b

Hint 3
Suppose the DP is DP(pos, state). pos is the current position you are in. state is one of {0,1,2}, where 0 means taking the array a,
1 means we are taking the subarray b, and 2 means we are again taking the array a. We need to handle the transitions carefully.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
kadaneremix(int *a, int *b, size_t n)
{
	int c, r, s;
	size_t i;

	c = r = s = 0;
	for (i = 0; i < n; i++) {
		c = max(c + (b[i] - a[i]), 0);
		r = max(r, c);
		s += a[i];
	}
	return r + s;
}

int
maxsplice(int *a, int *b, size_t n)
{
	int x, y;

	x = kadaneremix(a, b, n);
	y = kadaneremix(b, a, n);
	return max(x, y);
}

int
main()
{
	int a1[] = { 60, 60, 60 };
	int a2[] = { 20, 40, 20, 70, 30 };
	int a3[] = { 7, 11, 13 };

	int b1[] = { 10, 90, 10 };
	int b2[] = { 50, 20, 50, 40, 20 };
	int b3[] = { 1, 1, 1 };

	assert(maxsplice(a1, b1, nelem(a1)) == 210);
	assert(maxsplice(a2, b2, nelem(a2)) == 220);
	assert(maxsplice(a3, b3, nelem(a3)) == 31);

	return 0;
}
