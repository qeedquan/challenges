/*

You are given an integer array nums and two integers limit and goal. The array nums has an interesting property that abs(nums[i]) <= limit.

Return the minimum number of elements you need to add to make the sum of the array equal to goal. The array must maintain its property that abs(nums[i]) <= limit.

Note that abs(x) equals x if x >= 0, and -x otherwise.

Example 1:

Input: nums = [1,-1,1], limit = 3, goal = -4
Output: 2
Explanation: You can add -2 and -3, then the sum of the array will be 1 - 1 + 1 - 2 - 3 = -4.
Example 2:

Input: nums = [1,-10,9,1], limit = 100, goal = 0
Output: 1


Constraints:

1 <= nums.length <= 10^5
1 <= limit <= 10^6
-limit <= nums[i] <= limit
-10^9 <= goal <= 10^9

Hint 1
Try thinking about the problem as if the array is empty. Then you only need to form goal using elements whose absolute value is <= limit.

Hint 2
You can greedily set all of the elements except one to limit or -limit, so the number of elements you need is ceil(abs(goal)/ limit).

Hint 3
You can "normalize" goal by offsetting it by the sum of the array.
For example, if the goal is 5 and the sum is -3, then it's exactly the same as if the goal is 8 and the array is empty.

Hint 4
The answer is ceil(abs(goal-sum)/limit) = (abs(goal-sum)+limit-1) / limit.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
elements(int *numbers, size_t length, int limit, int goal)
{
	size_t i;
	int sum;

	sum = 0;
	for (i = 0; i < length; i++)
		sum += numbers[i];
	return (abs(sum - goal) + (limit - 1)) / limit;
}

int
main()
{
	int numbers1[] = { 1, -1, 1 };
	int numbers2[] = { 1, -10, 9, 1 };

	assert(elements(numbers1, nelem(numbers1), 3, -4) == 2);
	assert(elements(numbers2, nelem(numbers2), 100, 0) == 1);

	return 0;
}
