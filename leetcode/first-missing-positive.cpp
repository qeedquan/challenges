/*

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 
Constraints:

1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

// https://www.geeksforgeeks.org/dsa/find-the-smallest-positive-number-missing-from-an-unsorted-array/
int first_missing_positive(vector<int> &&array)
{
	int size = array.size();
	for (int i = 0; i < size; i++)
	{
		while (1 <= array[i] && array[i] <= size && array[i] != array[array[i] - 1])
			swap(array[i], array[array[i] - 1]);
	}

	for (int i = 1; i <= size; i++)
	{
		if (i != array[i - 1])
			return i;
	}
	return size + 1;
}

int main()
{
	assert(first_missing_positive({ 1 }) == 2);
	assert(first_missing_positive({ 1, 2, 0 }) == 3);
	assert(first_missing_positive({ 3, 4, -1, 1 }) == 2);
	assert(first_missing_positive({ 1000, -1 }) == 1);
	assert(first_missing_positive({ 1000, 200 }) == 1);
	assert(first_missing_positive({ 2, 5, 3, -1 }) == 1);
	assert(first_missing_positive({ 1, 100 }) == 2);
	assert(first_missing_positive({ 7, 8, 9, 11 }) == 1);
	assert(first_missing_positive({ 4, 3, 2, 1 }) == 5);
	assert(first_missing_positive({ 2, -3, 4, 1, 1, 7 }) == 3);

	return 0;
}
