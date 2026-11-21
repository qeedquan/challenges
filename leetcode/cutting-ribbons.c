/*

Description
You are given an integer array ribbons, where ribbons[i] represents the length of the i-th ribbon, and an integer k. You may cut any of the ribbons into any number of segments of positive integer lengths, or perform no cuts at all.

For example, if you have a ribbon of length 4, you can:
Keep the ribbon of length 4,
Cut it into one ribbon of length 3 and one ribbon of length 1,
Cut it into two ribbons of length 2,
Cut it into one ribbon of length 2 and two ribbons of length 1, or
Cut it into four ribbons of length 1.
Your goal is to obtain k ribbons of all the same positive integer length. You are allowed to throw away any excess ribbon as a result of cutting.

Return the maximum possible positive integer length that you can obtain k ribbons of, or 0 if you cannot obtain k ribbons of the same length.

Example 1:

Input: ribbons = [9,7,5], k = 3

Output: 5

Explanation:

Cut the first ribbon to two ribbons, one of length 5 and one of length 4.
Cut the second ribbon to two ribbons, one of length 5 and one of length 2.
Keep the third ribbon as it is.
Now you have 3 ribbons of length 5.

Example 2:

Input: ribbons = [7,5,9], k = 4

Output: 4

Explanation:

Cut the first ribbon to two ribbons, one of length 4 and one of length 3.
Cut the second ribbon to two ribbons, one of length 4 and one of length 1.
Cut the third ribbon to three ribbons, two of length 4 and one of length 1.
Now you have 4 ribbons of length 4.

Example 3:

Input: ribbons = [5,7,9], k = 22

Output: 0

Explanation: You cannot obtain k ribbons of the same positive integer length.

Constraints:

1 <= ribbons.length <= 10^5
1 <= ribbons[i] <= 10^5
1 <= k <= 10^9

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
sum(int *a, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++)
		r += a[i];
	return r;
}

bool
cuttable(int *a, size_t n, int k, int l)
{
	size_t i;
	int c;

	c = 0;
	for (i = 0; i < n; i++)
		c += a[i] / l;
	return c >= k;
}

int
maxlength(int *a, size_t n, int k)
{
	int l, r, m;

	if (k < 1)
		return 0;

	l = 1;
	r = (sum(a, n) / k) + 1;
	while (l < r) {
		m = (l + r) / 2;
		if (!cuttable(a, n, k, m))
			r = m;
		else
			l = m + 1;
	}
	return l - 1;
}

int
main(void)
{
	int a1[] = {9, 7, 5};
	int a2[] = {7, 5, 9};
	int a3[] = {5, 7, 9};

	assert(maxlength(a1, nelem(a1), 3) == 5);
	assert(maxlength(a2, nelem(a2), 4) == 4);
	assert(maxlength(a3, nelem(a3), 22) == 0);

	return 0;
}
