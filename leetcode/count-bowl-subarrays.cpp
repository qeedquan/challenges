/*

You are given an integer array nums with distinct elements.

A subarray nums[l...r] of nums is called a bowl if:

The subarray has length at least 3. That is, r - l + 1 >= 3.
The minimum of its two ends is strictly greater than the maximum of all elements in between. That is, min(nums[l], nums[r]) > max(nums[l + 1], ..., nums[r - 1]).
Return the number of bowl subarrays in nums.

Example 1:

Input: nums = [2,5,3,1,4]

Output: 2

Explanation:

The bowl subarrays are [3, 1, 4] and [5, 3, 1, 4].

[3, 1, 4] is a bowl because min(3, 4) = 3 > max(1) = 1.
[5, 3, 1, 4] is a bowl because min(5, 4) = 4 > max(3, 1) = 3.

Example 2:

Input: nums = [5,1,2,3,4]

Output: 3

Explanation:

The bowl subarrays are [5, 1, 2], [5, 1, 2, 3] and [5, 1, 2, 3, 4].

Example 3:

Input: nums = [1000000000,999999999,999999998]

Output: 0

Explanation:

No subarray is a bowl.

Constraints:

3 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
nums consists of distinct elements.

Hint 1
Use monotonic stacks to find nearest greater elements on both sides.

Hint 2
The bowl condition depends on comparing both ends with the maximum of the middle - avoid recomputing max by preprocessing.

Hint 3
Think in terms of "valid endpoints" rather than enumerating all subarrays.

Hint 4
There's symmetry: you can check both (left endpoint is smaller) and (right endpoint is smaller) cases separately.

*/

#include <cassert>
#include <vector>

typedef long long vlong;

using namespace std;

vlong bowls(const vector<vlong> &numbers)
{
	vector<vlong> stack;
	vlong result = 0;
	for (size_t i = 0; i < size(numbers); i++)
	{
		while (!empty(stack) && numbers[stack.back()] < numbers[i])
		{
			stack.pop_back();
			if (!empty(stack))
				result++;
		}
		stack.emplace_back(i);
	}
	return result;
}

int main()
{
	assert(bowls({ 2, 5, 3, 1, 4 }) == 2);
	assert(bowls({ 5, 1, 2, 3, 4 }) == 3);
	assert(bowls({ 1000000000, 999999999, 999999998 }) == 0);

	return 0;
}
