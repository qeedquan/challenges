/*

Given an array of integers nums, sort the array in increasing order based on the frequency of the values.
If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100

*/

#include <cassert>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> frequency_sort(vector<int> &numbers)
{
	unordered_map<int, int> count;
	for (const auto &value : numbers)
		count[value] += 1;

	sort(begin(numbers), end(numbers),
		 [&count](const auto &a, const auto &b) {
			 return (count[a] == count[b]) ? a > b : count[a] < count[b];
		 });

	return numbers;
}

int main()
{
	vector<int> numbers_1 = { 1, 1, 2, 2, 2, 3 };
	vector<int> numbers_2 = { 2, 3, 1, 3, 2 };
	vector<int> numbers_3 = { -1, 1, -6, 4, 5, -6, 1, 4, 1 };

	vector<int> expected_1 = { 3, 1, 1, 2, 2, 2 };
	vector<int> expected_2 = { 1, 3, 3, 2, 2 };
	vector<int> expected_3 = { 5, -1, 4, 4, -6, -6, 1, 1, 1 };

	assert(frequency_sort(numbers_1) == expected_1);
	assert(frequency_sort(numbers_2) == expected_2);
	assert(frequency_sort(numbers_3) == expected_3);

	return 0;
}
