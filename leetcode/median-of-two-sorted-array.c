/*

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 10^6

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long vlong;

vlong
kth(vlong *a, vlong m, vlong i, vlong *b, vlong n, vlong j, vlong k)
{
	vlong p, x, y;

	if (i >= m)
		return b[j + k - 1];
	if (j >= n)
		return a[i + k - 1];
	if (k == 1)
		return min(a[i], b[j]);

	p = k / 2;
	x = LLONG_MAX;
	y = LLONG_MAX;
	if (i + p - 1 < m)
		x = a[i + p - 1];
	if (j + p - 1 < n)
		y = b[j + p - 1];

	if (x < y)
		return kth(a, m, i + p, b, n, j, k - p);
	return kth(a, m, i, b, n, j + p, k - p);
}

double
medians(vlong *a, vlong m, vlong *b, vlong n)
{
	vlong t, x, y;

	t = m + n;
	x = kth(a, m, 0, b, n, 0, (t + 1) / 2);
	y = kth(a, m, 0, b, n, 0, (t + 2) / 2);
	return (x + y) / 2.0;
}

int
main()
{
	vlong a1[] = { 1, 3 };
	vlong a2[] = { 1, 2 };

	vlong b1[] = { 2 };
	vlong b2[] = { 3, 4 };

	assert(medians(a1, nelem(a1), b1, nelem(b1)) == 2);
	assert(medians(a2, nelem(a2), b2, nelem(b2)) == 2.5);

	return 0;
}
