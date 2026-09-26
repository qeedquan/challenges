/*

You are given an array nums consisting of integers between 1 and 3, and a binary array locked of the same size.

We consider nums sortable if it can be sorted using adjacent swaps, where a swap between two indices i and i + 1 is allowed if nums[i] - nums[i + 1] == 1 and locked[i] == 0.

In one operation, you can unlock any index i by setting locked[i] to 0.

Return the minimum number of operations needed to make nums sortable. If it is not possible to make nums sortable, return -1.

Example 1:

Input: nums = [1,2,1,2,3,2], locked = [1,0,1,1,0,1]

Output: 0

Explanation:

We can sort nums using the following swaps:

swap indices 1 with 2
swap indices 4 with 5
So, there is no need to unlock any index.

Example 2:

Input: nums = [1,2,1,1,3,2,2], locked = [1,0,1,1,0,1,0]

Output: 2

Explanation:

If we unlock indices 2 and 5, we can sort nums using the following swaps:

swap indices 1 with 2
swap indices 2 with 3
swap indices 4 with 5
swap indices 5 with 6

Example 3:

Input: nums = [1,2,1,2,3,2,1], locked = [0,0,0,0,0,0,0]

Output: -1

Explanation:

Even if all indices are unlocked, it can be shown that nums is not sortable.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 3
locked.length == nums.length
0 <= locked[i] <= 1

*/

package main

func main() {
	assert(unlocked([]int{1, 2, 1, 2, 3, 2}, []int{1, 0, 1, 1, 0, 1}) == 0)
	assert(unlocked([]int{1, 2, 1, 1, 3, 2, 2}, []int{1, 0, 1, 1, 0, 1, 0}) == 2)
	assert(unlocked([]int{1, 2, 1, 2, 3, 2, 1}, []int{0, 0, 0, 0, 0, 0, 0}) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func unlocked(numbers, locked []int) int {
	result := 0
	count := 0
	maximum := 0
	for i := range numbers {
		if maximum < numbers[i] {
			maximum = numbers[i]
			count = 0
		} else if maximum > numbers[i] {
			if maximum != numbers[i]+1 {
				return -1
			}
			result += count
			count = 0
		}
		count += locked[i]
	}
	return result
}
