/*

You are given a 0-indexed integer array nums. You are allowed to permute nums into a new array perm of your choosing.

We define the greatness of nums be the number of indices 0 <= i < nums.length for which perm[i] > nums[i].

Return the maximum possible greatness you can achieve after permuting nums.

Example 1:

Input: nums = [1,3,5,2,1,3,1]
Output: 4
Explanation: One of the optimal rearrangements is perm = [2,5,1,3,3,1,1].
At indices = 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.

Example 2:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We can prove the optimal perm is [2,3,4,1].
At indices = 0, 1, and 2, perm[i] > nums[i]. Hence, we return 3.


Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9

Hint 1
Can we use sorting and two pointers here?

Hint 2
Assign every element the next bigger unused element as many times as possible.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

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

size_t
greatness(int *a, size_t n)
{
	size_t i, r;

	qsort(a, n, sizeof(*a), cmp);

	for (i = r = 0; i < n; i++) {
		if (a[i] > a[r])
			r++;
	}
	return r;
}

int
main()
{
	int a1[] = { 1, 3, 5, 2, 1, 3, 1 };
	int a2[] = { 1, 2, 3, 4 };

	assert(greatness(a1, nelem(a1)) == 4);
	assert(greatness(a2, nelem(a2)) == 3);

	return 0;
}
