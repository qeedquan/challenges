/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
trap(int *a, size_t n)
{
	size_t i, h;
	int m, r;

	if (n == 0)
		return 0;

	m = 0;
	for (i = h = 0; i < n; i++) {
		if (a[i] > m) {
			m = a[i];
			h = i;
		}
	}

	r = m = 0;
	for (i = 0; i < h; i++) {
		m = max(m, a[i]);
		r += m - a[i];
	}

	m = 0;
	for (i = n - 1; i > h; i--) {
		m = max(m, a[i]);
		r += m - a[i];
	}

	return r;
}

int
main()
{
	int a1[] = { 2, 0, 2 };
	int a2[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int a3[] = { 4, 2, 0, 3, 2, 5 };

	assert(trap(a1, nelem(a1)) == 2);
	assert(trap(a2, nelem(a2)) == 6);
	assert(trap(a3, nelem(a3)) == 9);

	return 0;
}
