/*

You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.

Example 1:

Input: rods = [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
Example 2:

Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
Example 3:

Input: rods = [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.
 

Constraints:

1 <= rods.length <= 20
1 <= rods[i] <= 1000
sum(rods[i]) <= 5000

*/

#include <cassert>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// https://walkccc.me/LeetCode/problems/0956/
int tallest_billboard(const vector<int> &rods)
{
	auto sum = accumulate(begin(rods), end(rods), 0);

	vector<int> dp(sum + 1, -1);
	dp[0] = 0;
	for (auto h : rods)
	{
		vector<int> prev(dp);
		for (auto i = 0; i <= sum - h; i++)
		{
			if (prev[i] < 0)
				continue;

			dp[i] = max(dp[i], prev[i]);
			dp[i + h] = max(dp[i + h], prev[i]);
			dp[abs(i - h)] = max(dp[abs(i - h)], prev[i] + min(i, h));
		}
	}

	return dp[0];
}

int main()
{
	assert(tallest_billboard({ 1, 2, 3, 6 }) == 6);
	assert(tallest_billboard({ 1, 2, 3, 4, 5, 6 }) == 10);
	assert(tallest_billboard({ 1, 2 }) == 0);

	return 0;
}
