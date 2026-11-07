/*

You are given an array nums, where each number in the array appears either once or twice.

Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.

Example 1:

Input: nums = [1,2,1,3]

Output: 1

Explanation:

The only number that appears twice in nums is 1.

Example 2:

Input: nums = [1,2,3]

Output: 0

Explanation:

No number appears twice in nums.

Example 3:

Input: nums = [1,2,2,1]

Output: 3

Explanation:

Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
Each number in nums appears either once or twice.

Hint 1
The constraints are small. Brute force checking each value in the array.

*/

package main

func main() {
	assert(xor2([]int{1, 2, 1, 3}) == 1)
	assert(xor2([]int{1, 2, 3}) == 0)
	assert(xor2([]int{1, 2, 2, 1}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func xor2(a []int) int {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
	}

	r := 0
	for k, v := range m {
		if v == 2 {
			r ^= k
		}
	}
	return r
}
