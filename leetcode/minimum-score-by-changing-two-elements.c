/*

You are given an integer array nums.

    The low score of nums is the minimum absolute difference between any two integers.
    The high score of nums is the maximum absolute difference between any two integers.
    The score of nums is the sum of the high and low scores.

Return the minimum score after changing two elements of nums.

Example 1:

Input: nums = [1,4,7,8,5]

Output: 3

Explanation:

    Change nums[0] and nums[1] to be 6 so that nums becomes [6,6,7,8,5].
    The low score is the minimum absolute difference: |6 - 6| = 0.
    The high score is the maximum absolute difference: |8 - 5| = 3.
    The sum of high and low score is 3.

Example 2:

Input: nums = [1,4,3]

Output: 0

Explanation:

    Change nums[1] and nums[2] to 1 so that nums becomes [1,1,1].
    The sum of maximum absolute difference and minimum absolute difference is 0.



Constraints:

    3 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9

Hint 1
Changing the minimum or maximum values will only minimize the score.

Hint 2
Think about what all possible pairs of minimum and maximum values can be changed to form the minimum score.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
minimize(int *a, size_t n)
{
	size_t i, j;
	int r;

	if (n == 0)
		return 0;

	qsort(a, n, sizeof(*a), cmp);

	r = INT_MAX;
	j = min(n, 3);
	for (i = 0; i < j; i++)
		r = min(r, a[n + i - 3] - a[i]);
	return r;
}

int
main()
{
	int a1[] = { 1, 4, 7, 8, 5 };
	int a2[] = { 1, 4, 3 };

	assert(minimize(a1, nelem(a1)) == 3);
	assert(minimize(a2, nelem(a2)) == 0);

	return 0;
}
