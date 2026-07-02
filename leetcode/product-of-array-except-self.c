/*

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:

2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.


Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
pes(long *a, size_t n, long *r)
{
	size_t i;
	long f;

	if (n == 0)
		return;

	r[0] = 1;
	for (i = 1; i < n; i++)
		r[i] = r[i - 1] * a[i - 1];

	f = 1;
	for (i = n - 1; i > 0; i--) {
		f *= a[i];
		r[i - 1] *= f;
	}
}

void
test(long *a, size_t n, long *r)
{
	long p[16];

	pes(a, n, p);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main()
{
	long a1[] = { 1, 2, 3, 4 };
	long a2[] = { -1, 1, 0, -3, 3 };

	long r1[] = { 24, 12, 8, 6 };
	long r2[] = { 0, 0, 9, 0, 0 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);

	return 0;
}
