/*

You are given an integer array nums of even length n and an integer limit.
In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.

The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number.
For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.

Return the minimum number of moves required to make nums complementary.

Example 1:

Input: nums = [1,2,4,3], limit = 4
Output: 1
Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements are changed).
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.

Example 2:

Input: nums = [1,2,2,1], limit = 2
Output: 2
Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot change any number to 3 since 3 > limit.

Example 3:

Input: nums = [1,2,1,2], limit = 2
Output: 0
Explanation: nums is already complementary.

Constraints:

n == nums.length
2 <= n <= 10^5
1 <= nums[i] <= limit <= 10^5
n is even.

Hint 1
Given a target sum x, each pair of nums[i] and nums[n-1-i] would either need 0, 1, or 2 modifications.

Hint 2
Can you find the optimal target sum x value such that the sum of modifications is minimized?

Hint 3
Create a difference array to efficiently sum all the modifications.

*/

package main

func main() {
	assert(moves([]int{1, 2, 4, 3}, 4) == 1)
	assert(moves([]int{1, 2, 2, 1}, 2) == 2)
	assert(moves([]int{1, 2, 1, 2}, 2) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func moves(nums []int, limit int) int {
	diff := make([]int, 2*(limit+1))
	for i := range len(nums) / 2 {
		left := nums[i]
		right := nums[len(nums)-i-1]
		diff[min(left, right)+1] -= 1
		diff[left+right] -= 1
		diff[left+right+1] += 1
		diff[max(left, right)+limit+1] += 1
	}

	result := len(nums)
	count := len(nums)
	for i := 2; i <= 2*limit; i++ {
		count += diff[i]
		result = min(result, count)
	}
	return result
}
