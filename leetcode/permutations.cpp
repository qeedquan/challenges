/*

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/

#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > permutations(const vector<int> &values)
{
	vector<vector<int> > result;
	auto permuted = values;
	do
	{
		result.push_back(permuted);
	} while (next_permutation(permuted.begin(), permuted.end()));

	return result;
}

int main()
{
	vector<vector<int> > result_1 = { { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 }, { 2, 3, 1 }, { 3, 1, 2 }, { 3, 2, 1 } };
	vector<vector<int> > result_2 = { { 0, 1 }, { 1, 0 } };
	vector<vector<int> > result_3 = { { 1 } };

	assert(permutations({ 1, 2, 3 }) == result_1);
	assert(permutations({ 0, 1 }) == result_2);
	assert(permutations({ 1 }) == result_3);

	return 0;
}
