/*

Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

Constraints:

1 <= nums.length <= 50
-10^6 <= nums[i] <= 10^6
All the elements of nums are unique.
At most 104 calls in total will be made to reset and shuffle.

*/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Solution
{
private:
	vector<int> original;
	vector<int> shuffled;

public:
	Solution(const vector<int> &numbers)
	{
		original = numbers;
		shuffled = original;
	}

	vector<int> reset()
	{
		shuffled = original;
		return shuffled;
	}

	vector<int> shuffle()
	{
		auto seed = chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(shuffled.begin(), shuffled.end(), default_random_engine(seed));
		return shuffled;
	}
};

void output(const vector<int> &numbers)
{
	for (auto number : numbers)
		cout << number << " ";
	cout << endl;
}

int main()
{
	auto solution = Solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
	output(solution.shuffle());
	output(solution.reset());
	output(solution.shuffle());

	return 0;
}
