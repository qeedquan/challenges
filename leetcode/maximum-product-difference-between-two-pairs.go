/*

The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).

For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.

Return the maximum such product difference.

Example 1:

Input: nums = [5,6,2,7,4]
Output: 34
Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.

Example 2:

Input: nums = [4,2,5,9,7,4,8]
Output: 64
Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.

Constraints:

4 <= nums.length <= 10^4
1 <= nums[i] <= 10^4

Hint 1
If you only had to find the maximum product of 2 numbers in an array, which 2 numbers should you choose?

Hint 2
We only need to worry about 4 numbers in the array.

*/

package main

import "math"

func main() {
	assert(solve([]int{5, 6, 2, 7, 4}) == 34)
	assert(solve([]int{4, 2, 5, 9, 7, 4, 8}) == 64)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(numbers []int) int {
	if len(numbers) == 0 {
		return 0
	}

	largest := [2]int{math.MinInt, math.MinInt}
	smallest := [2]int{math.MaxInt, math.MaxInt}
	for _, number := range numbers {
		if number >= largest[0] {
			largest[1] = largest[0]
			largest[0] = number
		} else if number > largest[1] {
			largest[1] = number
		}

		if number <= smallest[0] {
			smallest[1] = smallest[0]
			smallest[0] = number
		} else if number < smallest[1] {
			smallest[1] = number
		}
	}
	return largest[0]*largest[1] - smallest[0]*smallest[1]
}
