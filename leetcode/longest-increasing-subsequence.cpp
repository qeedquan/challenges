/*

Given an integer array nums, return the length of the longest strictly increasing subsequence.


Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

*/

#include <cassert>
#include <functional>
#include <vector>

using namespace std;

// https://zhenchaogan.gitbook.io/leetcode-solution/leetcode-300.-longest-increasing-subsequence
// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
int lislen(const vector<int> &nums)
{
	vector<int> dp;
	for (auto n : nums)
	{
		auto it = lower_bound(dp.begin(), dp.end(), n);
		if (it != dp.end())
			*it = n;
		else
			dp.push_back(n);
	}
	return dp.size();
}

int main()
{
	assert(lislen({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
	assert(lislen({0, 1, 0, 3, 2, 3}) == 4);
	assert(lislen({7, 7, 7, 7, 7, 7, 7}) == 1);
	assert(lislen({10, 22, 9, 33, 21, 50, 41, 60, 80}) == 6);
	assert(lislen({3, 10, 2, 1, 20}) == 3);
	assert(lislen({3, 2}) == 1);
	assert(lislen({50, 3, 10, 7, 40, 80}) == 4);
	
	return 0;
}
