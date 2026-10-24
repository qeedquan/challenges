/*

Given an array of integers nums, you are allowed to perform the following operation any number of times:

Remove a strictly increasing subsequence from the array.
Your task is to find the minimum number of operations required to make the array empty.

Example 1:

Input: nums = [5,3,1,4,2]

Output: 3

Explanation:

We remove subsequences [1, 2], [3, 4], [5].

Example 2:

Input: nums = [1,2,3,4,5]

Output: 1

Example 3:

Input: nums = [5,4,3,2,1]

Output: 5

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5

*/

#include <cassert>
#include <vector>

using namespace std;

size_t operations(const vector<int> &numbers)
{
	vector<int> result;
	for (auto value : numbers)
	{
		size_t left = 0;
		size_t right = result.size();
		while (left < right)
		{
			auto middle = left + (right - left) / 2;
			if (result[middle] < value)
				right = middle;
			else
				left = middle + 1;
		}
		if (left == result.size())
			result.push_back(value);
		else
			result[left] = value;
	}
	return result.size();
}

int main()
{
	assert(operations({ 5, 3, 1, 4, 2 }) == 3);
	assert(operations({ 1, 2, 3, 4, 5 }) == 1);
	assert(operations({ 5, 4, 3, 2, 1 }) == 5);

	return 0;
}
