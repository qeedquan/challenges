/*

Given an integer array nums of size n, return the number with the value closest to 0 in nums. If there are multiple answers, return the number with the largest value.

Example 1:

Input: nums = [-4,-2,1,4,8]
Output: 1
Explanation:
The distance from -4 to 0 is |-4| = 4.
The distance from -2 to 0 is |-2| = 2.
The distance from 1 to 0 is |1| = 1.
The distance from 4 to 0 is |4| = 4.
The distance from 8 to 0 is |8| = 8.
Thus, the closest number to 0 in the array is 1.

Example 2:

Input: nums = [2,-1,1]
Output: 1
Explanation: 1 and -1 are both the closest numbers to 0, so 1 being larger is returned.


Constraints:

1 <= n <= 1000
-10^5 <= nums[i] <= 10^5

Hint:
Keep track of the number closest to 0 as you iterate through the array.
Ensure that if multiple numbers are closest to 0, you store the one with the largest value.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
closest(int *a, size_t n)
{
	int r, u, v;
	size_t i;

	if (n == 0)
		return 0;

	r = a[0];
	u = abs(r);
	for (i = 1; i < n; i++) {
		v = abs(a[i]);
		if (v < u || (v == u && a[i] > r)) {
			r = a[i];
			u = abs(r);
		}
	}
	return r;
}

int
main(void)
{
	int a1[] = {-4, -2, 1, 4, 8};
	int a2[] = {2, -1, 1};

	assert(closest(a1, nelem(a1)) == 1);
	assert(closest(a2, nelem(a2)) == 1);

	return 0;
}
