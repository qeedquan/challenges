/*

Given an integer array nums of positive integers, return the average value of all even integers that are divisible by 3.

Note that the average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.

Example 1:

Input: nums = [1,3,6,10,12,15]
Output: 9
Explanation: 6 and 12 are even numbers that are divisible by 3. (6 + 12) / 2 = 9.

Example 2:

Input: nums = [1,2,4,7,10]
Output: 0
Explanation: There is no single number that satisfies the requirement, so return 0.
 

Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= 1000

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
average(int *a, size_t n)
{
	size_t i;
	int r, l;

	r = l = 0;
	for (i = 0; i < n; i++) {
		if ((a[i] % 6) == 0) {
			r += a[i];
			l += 1;
		}
	}

	return (l) ? r / l : 0;
}

int
main(void)
{
	int a1[] = {1, 3, 6, 10, 12, 15};
	int a2[] = {1, 2, 4, 7, 10};

	assert(average(a1, nelem(a1)) == 9);
	assert(average(a2, nelem(a2)) == 0);

	return 0;
}
