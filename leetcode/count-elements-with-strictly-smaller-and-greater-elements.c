/*

Given an integer array nums, return the number of elements that have both a strictly smaller and a strictly greater element appear in nums.

Example 1:

Input: nums = [11,7,2,15]
Output: 2
Explanation: The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
In total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.

Example 2:

Input: nums = [-3,3,3,90]
Output: 2
Explanation: The element 3 has the element -3 strictly smaller than it and the element 90 strictly greater than it.
Since there are two elements with the value 3, in total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.

Constraints:

1 <= nums.length <= 100
-10^5 <= nums[i] <= 10^5

Hint 1
All the elements in the array should be counted except for the minimum and maximum elements.

Hint 2
If the array has n elements, the answer will be n - count(min(nums)) - count(max(nums))

Hint 3
This formula will not work in case the array has all the elements equal, why?

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
count(int *a, size_t n)
{
	int a0, a1, c;
	size_t i;

	a0 = INT_MAX;
	a1 = INT_MIN;
	for (i = 0; i < n; i++) {
		a0 = min(a0, a[i]);
		a1 = max(a1, a[i]);
	}

	c = 0;
	for (i = 0; i < n; i++) {
		if (a0 < a[i] && a[i] < a1)
			c += 1;
	}
	return c;
}

int
main()
{
	int a1[] = { 11, 7, 2, 15 };
	int a2[] = { -3, 3, 3, 90 };

	assert(count(a1, nelem(a1)) == 2);
	assert(count(a2, nelem(a2)) == 2);

	return 0;
}
