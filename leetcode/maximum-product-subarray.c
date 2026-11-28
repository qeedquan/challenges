/*

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


Constraints:

1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

// https://www.geeksforgeeks.org/maximum-product-subarray/
int
maxprod(int *a, size_t n)
{
	int r, x, y;
	size_t i;

	if (n == 0)
		return 0;

	r = x = y = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] < 0)
			swap(&x, &y);

		x = max(a[i], x * a[i]);
		y = min(a[i], y * a[i]);
		r = max(r, x);
	}
	return r;
}

int
main(void)
{
	int a1[] = { 2, 3, -2, 4 };
	int a2[] = { -2, 0, -1 };
	int a3[] = { 6, -3, -10, 0, 2 };
	int a4[] = { -1, -3, -10, 0, 60 };
	int a5[] = { 1, -2, -3, 0, 7, -8, -2 };
	int a6[] = { 1, 2, 3, 4, 5, 0 };
	int a7[] = { 1, 2, -3, 0, -4, -5 };
	int a8[] = { 3, 0, 2, 5 };

	assert(maxprod(a1, nelem(a1)) == 6);
	assert(maxprod(a2, nelem(a2)) == 0);
	assert(maxprod(a3, nelem(a3)) == 180);
	assert(maxprod(a4, nelem(a4)) == 60);
	assert(maxprod(a5, nelem(a5)) == 112);
	assert(maxprod(a6, nelem(a6)) == 120);
	assert(maxprod(a7, nelem(a7)) == 20);
	assert(maxprod(a8, nelem(a8)) == 10);

	return 0;
}
