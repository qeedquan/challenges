/*

You are given a 0-indexed integer array nums and an integer k. Your task is to perform the following operation exactly k times in order to maximize your score:

Select an element m from nums.
Remove the selected element m from the array.
Add a new element with a value of m + 1 to the array.
Increase your score by m.
Return the maximum score you can achieve after performing the operation exactly k times.

Example 1:

Input: nums = [1,2,3,4,5], k = 3
Output: 18
Explanation: We need to choose exactly 3 elements from nums to maximize the sum.
For the first iteration, we choose 5. Then sum is 5 and nums = [1,2,3,4,6]
For the second iteration, we choose 6. Then sum is 5 + 6 and nums = [1,2,3,4,7]
For the third iteration, we choose 7. Then sum is 5 + 6 + 7 = 18 and nums = [1,2,3,4,8]
So, we will return 18.
It can be proven, that 18 is the maximum answer that we can achieve.

Example 2:

Input: nums = [5,5,5], k = 2
Output: 11
Explanation: We need to choose exactly 2 elements from nums to maximize the sum.
For the first iteration, we choose 5. Then sum is 5 and nums = [5,5,6]
For the second iteration, we choose 6. Then sum is 5 + 6 = 11 and nums = [5,5,7]
So, we will return 11.
It can be proven, that 11 is the maximum answer that we can achieve.

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maximize(int *a, size_t n, int k)
{
	size_t i;
	int m;

	if (n == 0)
		return 0;

	m = a[0];
	for (i = 1; i < n; i++)
		m = max(m, a[i]);
	return m * k + k * (k - 1) / 2;
}

int
main()
{
	int a1[] = { 1, 2, 3, 4, 5 };
	int a2[] = { 5, 5, 5 };

	assert(maximize(a1, nelem(a1), 3) == 18);
	assert(maximize(a2, nelem(a2), 2) == 11);

	return 0;
}
