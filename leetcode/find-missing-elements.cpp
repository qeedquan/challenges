/*

You are given an integer array nums consisting of unique integers.

Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.

The smallest and largest integers of the original range are still present in nums.

Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

Example 1:

Input: nums = [1,4,2,5]

Output: [3]

Explanation:

The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.

Example 2:

Input: nums = [7,8,6,9]

Output: []

Explanation:

The smallest integer is 6 and the largest is 9, so the full range is [6,7,8,9]. All integers are already present, so no integer is missing.

Example 3:

Input: nums = [5,1]

Output: [2,3,4]

Explanation:

The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. The missing integers are 2, 3, and 4.

Constraints:

2 <= nums.length <= 100
1 <= nums[i] <= 100

Hint 1
First, find the maximum and minimum elements in the array.

Hint 2
Then, iterate over all the integers in the range [min, max] and check if they are in the array.

Hint 3
If not, add them to the array, and return the sorted array at the end.

*/

#include <cassert>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> missing(const vector<int> &numbers)
{
	unordered_set<int> lookup(numbers.cbegin(), numbers.cend());
	auto minimum = ranges::min(numbers);
	auto maximum = ranges::max(numbers);

	vector<int> result;
	for (auto index = minimum + 1; index < maximum; index++)
	{
		if (!lookup.count(index))
			result.emplace_back(index);
	}
	return result;
}

int main()
{
	vector<int> numbers_1 = { 1, 4, 2, 5 };
	vector<int> numbers_2 = { 7, 8, 6, 9 };
	vector<int> numbers_3 = { 5, 1 };

	vector<int> expected_1 = { 3 };
	vector<int> expected_2 = {};
	vector<int> expected_3 = { 2, 3, 4 };

	assert(missing(numbers_1) == expected_1);
	assert(missing(numbers_2) == expected_2);
	assert(missing(numbers_3) == expected_3);

	return 0;
}
