/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3


Constraints:

1 <= n <= 10^5
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://en.wikipedia.org/wiki/Cycle_detection
int
duplicate(int *a, size_t n)
{
	int x, y;

	if (n == 0)
		return 0;

	x = y = n;
	do {
		x = a[x - 1];
		y = a[a[y - 1] - 1];
	} while (x != y);

	for (x = n; x != y;) {
		x = a[x - 1];
		y = a[y - 1];
	}
	return x;
}

int
main()
{
	int a1[] = { 1, 3, 4, 2, 2 };
	int a2[] = { 3, 1, 3, 4, 2 };
	int a3[] = { 3, 3, 3, 3, 3 };
	int a4[] = { 1, 1 };

	assert(duplicate(a1, nelem(a1)) == 2);
	assert(duplicate(a2, nelem(a2)) == 3);
	assert(duplicate(a3, nelem(a3)) == 3);
	assert(duplicate(a4, nelem(a4)) == 1);

	return 0;
}
