/*

Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:

    nums[a] + nums[b] + nums[c] == nums[d], and
    a < b < c < d

Example 1:

Input: nums = [1,2,3,6]
Output: 1
Explanation: The only quadruplet that satisfies the requirement is (0, 1, 2, 3) because 1 + 2 + 3 == 6.

Example 2:

Input: nums = [3,3,6,4,5]
Output: 0
Explanation: There are no such quadruplets in [3,3,6,4,5].

Example 3:

Input: nums = [1,1,1,3,5]
Output: 4
Explanation: The 4 quadruplets that satisfy the requirement are:
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5

Constraints:

    4 <= nums.length <= 50
    1 <= nums[i] <= 100

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
quadruplets(int *a, size_t n)
{
	size_t i, j, k, l, r;

	r = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j + 1; k < n; k++) {
				for (l = k + 1; l < n; l++) {
					if (a[i] + a[j] + a[k] == a[l])
						r++;
				}
			}
		}
	}
	return r;
}

int
main(void)
{
	int a1[] = {1, 2, 3, 6};
	int a2[] = {3, 3, 6, 4, 5};
	int a3[] = {1, 1, 1, 3, 5};

	assert(quadruplets(a1, nelem(a1)) == 1);
	assert(quadruplets(a2, nelem(a2)) == 0);
	assert(quadruplets(a3, nelem(a3)) == 4);

	return 0;
}
