/*

You are given an integer array nums.

A subarray of nums is called centered if the sum of its elements is equal to at least one element within that same subarray.

Return the number of centered subarrays of nums.

Example 1:

Input: nums = [-1,1,0]

Output: 5

Explanation:

All single-element subarrays ([-1], [1], [0]) are centered.
The subarray [1, 0] has a sum of 1, which is present in the subarray.
The subarray [-1, 1, 0] has a sum of 0, which is present in the subarray.
Thus, the answer is 5.

Example 2:

Input: nums = [2,-3]

Output: 2

Explanation:

Only single-element subarrays ([2], [-3]) are centered.

Constraints:

1 <= nums.length <= 500
-10^5 <= nums[i] <= 10^5

Hint 1
Generate all subarrays and use a hashmap to check whether the sum exists in the generated subarrays.

*/

package main

func main() {
	assert(centered([]int{-1, 1, 0}) == 5)
	assert(centered([]int{2, -3}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func centered(array []int) int {
	result := 0
	for i := range array {
		seen := make(map[int]bool)
		total := 0
		for _, value := range array[i:] {
			seen[value] = true
			if total += value; seen[total] {
				result += 1
			}
		}
	}
	return result
}
