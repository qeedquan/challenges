/*

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000

Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
combinations(int *a, size_t n, int t)
{
	int i, *p, r;
	size_t j;

	p = calloc(t + 1, sizeof(*p));
	if (!p)
		return -errno;

	p[0] = 1;
	for (i = 0; i <= t; i++) {
		for (j = 0; j < n; j++) {
			if (i >= a[j])
				p[i] += p[i - a[j]];
		}
	}

	r = p[t];
	free(p);
	return r;
}

void
test(int *a, size_t n, int t, int r)
{
	int v;

	v = combinations(a, n, t);
	printf("%d\n", v);
	assert(v == r);
}

int
main(void)
{
	int a1[] = {1, 2, 3};
	int a2[] = {9};

	test(a1, nelem(a1), 4, 7);
	test(a2, nelem(a2), 3, 0);

	return 0;
}
