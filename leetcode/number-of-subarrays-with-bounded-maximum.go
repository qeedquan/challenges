/*

Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:

Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].

Example 2:

Input: nums = [2,9,2,5,6], left = 2, right = 8

Output: 7

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
0 <= left <= right <= 10^9

*/

package main

func main() {
	assert(bounds([]int{2, 1, 4, 3}, 2, 3) == 3)
	assert(bounds([]int{2, 9, 2, 5, 6}, 2, 8) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bounds(a []int, l, r int) int {
	return count(a, r) - count(a, l-1)
}

func count(a []int, b int) int {
	r, c := 0, 0
	for i := range a {
		if a[i] <= b {
			c += 1
		} else {
			c = 0
		}
		r += c
	}
	return r
}
