/*

Given an array nums, you have to get the maximum score starting from index 0 and hopping until you reach the last element of the array.

In each hop, you can jump from index i to an index j > i, and you get a score of (j - i) * nums[j].

Return the maximum score you can get.

Example 1:

Input: nums = [1,5,8]

Output: 16

Explanation:

There are two possible ways to reach the last element:

0 -> 1 -> 2 with a score of (1 - 0) * 5 + (2 - 1) * 8 = 13.
0 -> 2 with a score of (2 - 0) * 8 = 16.
Example 2:

Input: nums = [4,5,2,8,9,1,3]

Output: 42

Explanation:

We can do the hopping 0 -> 4 -> 6 with a score of (4 - 0) * 9 + (6 - 4) * 3 = 42.

Constraints:

2 <= nums.length <= 10^5
1 <= nums[i] <= 10^5

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxscore(int *a, size_t n)
{
	int m, r;
	size_t i;

	if (n == 0)
		return 0;

	r = m = 0;
	for (i = n - 1; i >= 1; i--) {
		m = max(m, a[i]);
		r += m;
	}
	return r;
}

int
main()
{
	int a1[] = { 1, 5, 8 };
	int a2[] = { 4, 5, 2, 8, 9, 1, 3 };

	assert(maxscore(a1, nelem(a1)) == 16);
	assert(maxscore(a2, nelem(a2)) == 42);

	return 0;
}
