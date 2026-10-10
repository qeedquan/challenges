/*

A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

Example 1:

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

Example 2:

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.

Constraints:

2 <= nums.length <= 5 * 10^4
0 <= nums[i] <= 5 * 10^4

*/

package main

func main() {
	assert(maxwidthramp([]int{6, 0, 8, 2, 1, 5}) == 4)
	assert(maxwidthramp([]int{9, 8, 1, 0, 1, 9, 4, 0, 4, 1}) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxwidthramp(a []int) int {
	s := []int{}
	for i := range a {
		if len(s) == 0 || back(a, s) > a[i] {
			s = append(s, i)
		}
	}

	r := 0
	for i := len(a) - 1; i > r; i-- {
		for len(s) > 0 && back(a, s) <= a[i] {
			n := len(s) - 1
			r = max(r, i-s[n])
			s = s[:n]
		}
	}
	return r
}

func back(a, s []int) int {
	return a[s[len(s)-1]]
}
