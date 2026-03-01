/*

Task
Given an array of 2k integers (for some integer k), perform the following operations until the array contains only one element:

On the 1st, 3rd, 5th, etc. 
iterations (1-based) replace each pair of consecutive elements with their sum;
On the 2nd, 4th, 6th, etc. 
iterations replace each pair of consecutive elements with their product.
After the algorithm has finished, there will be a single element left in the array. Return that element.

Example
For inputArray = [1, 2, 3, 4, 5, 6, 7, 8], the output should be 186.

We have [1, 2, 3, 4, 5, 6, 7, 8] -> [3, 7, 11, 15] -> [21, 165] -> [186], so the answer is 186.

Input/Output
[input] integer array arr

Constraints: 2^1 ≤ arr.length ≤ 2^5, -9 ≤ arr[i] ≤ 99.

[output] an integer

*/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int array_conversion(vector<int> &&array)
{
	auto length = array.size();
	if (length == 0)
		return 0;

	for (auto state = 0; length > 1; length /= 2)
	{
		for (size_t index = 0; index < length / 2; index++)
		{
			if (state == 0)
				array[index] = array[2 * index] + array[(2 * index) + 1];
			else
				array[index] = array[2 * index] * array[(2 * index) + 1];
		}
		state ^= 1;
	}
	return array[0];
}

int main()
{
	assert(array_conversion({ 1, 2, 3, 4, 5, 6, 7, 8 }) == 186);
	assert(array_conversion({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }) == 64);
	assert(array_conversion({ 3, 3, 5, 5 }) == 60);

	return 0;
}
