/*

You are given a 0-indexed array nums of size n consisting of non-negative integers.

You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply the following on the ith element of nums:

    If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.

After performing all the operations, shift all the 0's to the end of the array.

    For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].

Return the resulting array.

Note that the operations are applied sequentially, not all at once.

 

Example 1:

Input: nums = [1,2,2,1,1,0]
Output: [1,4,2,0,0,0]
Explanation: We do the following operations:
- i = 0: nums[0] and nums[1] are not equal, so we skip this operation.
- i = 1: nums[1] and nums[2] are equal, we multiply nums[1] by 2 and change nums[2] to 0. The array becomes [1,4,0,1,1,0].
- i = 2: nums[2] and nums[3] are not equal, so we skip this operation.
- i = 3: nums[3] and nums[4] are equal, we multiply nums[3] by 2 and change nums[4] to 0. The array becomes [1,4,0,2,0,0].
- i = 4: nums[4] and nums[5] are equal, we multiply nums[4] by 2 and change nums[5] to 0. The array becomes [1,4,0,2,0,0].
After that, we shift the 0's to the end, which gives the array [1,4,2,0,0,0].

Example 2:

Input: nums = [0,1]
Output: [1,0]
Explanation: No operation can be applied, we just shift the 0 to the end. 

Constraints:

    2 <= nums.length <= 2000
    0 <= nums[i] <= 1000

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
apply(int *a, size_t n)
{
	size_t i, j, z;

	for (i = 1; i < n; i++) {
		if (a[i - 1] == a[i]) {
			a[i - 1] *= 2;
			a[i] = 0;
		}
	}

	for (i = j = z = 0; i < n; i++) {
		if (a[i] != 0)
			a[j++] = a[i];
		else
			z++;
	}

	for (i = 0; i < z; i++)
		a[n - i - 1] = 0;
}

void
test(int *a, size_t n, int *r)
{
	apply(a, n);
	dump(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {1, 2, 2, 1, 1, 0};
	int r1[] = {1, 4, 2, 0, 0, 0};

	int a2[] = {0, 1};
	int r2[] = {1, 0};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);

	return 0;
}