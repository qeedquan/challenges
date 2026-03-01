/*

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
snd(int *a, ssize_t n)
{
	ssize_t l, m, r;
	bool c0, c1;

	if (n == 0)
		return 0;

	l = 0;
	r = n - 1;
	while (l <= r) {
		m = l + (r - l) / 2;
		c0 = (m % 2 == 0 && m + 1 < n && a[m] == a[m + 1]);
		c1 = (m % 2 == 1 && a[m] == a[m - 1]);
		if (!c0 && !c1)
			r = m - 1;
		else
			l = m + 1;
	}
	return a[l];
}

int
main()
{
	int a1[] = { 1, 1, 2, 3, 3, 4, 4, 8, 8 };
	int a2[] = { 3, 3, 7, 7, 10, 11, 11 };
	int a3[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5 };
	int a4[] = { 100, 140, 140, 145, 145, 150, 150 };

	assert(snd(a1, nelem(a1)) == 2);
	assert(snd(a2, nelem(a2)) == 10);
	assert(snd(a3, nelem(a3)) == 5);
	assert(snd(a4, nelem(a4)) == 100);

	return 0;
}
