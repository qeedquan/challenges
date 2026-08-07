/*

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:

1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
solve(int target, int *array, size_t size)
{
	size_t start, end;
	size_t smallest;
	size_t index;
	int sum;
	bool found;

	found = false;
	smallest = size;
	start = 0;
	end = 0;
	sum = 0;
	for (index = 0; index < size; index++) {
		sum += array[index];
		while (sum >= target && start <= end) {
			if (start == end)
				return 1;

			if (end - start + 1 < smallest) {
				smallest = end - start + 1;
				found = true;
			}
			sum -= array[start++];
		}
		end++;
	}
	return (found) ? smallest : 0;
}

int
main()
{
	int array1[] = { 2, 3, 1, 2, 4, 3 };
	int array2[] = { 1, 4, 4 };
	int array3[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

	assert(solve(7, array1, nelem(array1)) == 2);
	assert(solve(4, array2, nelem(array2)) == 1);
	assert(solve(11, array3, nelem(array3)) == 0);

	return 0;
}
