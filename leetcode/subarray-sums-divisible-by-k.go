/*

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:

Input: nums = [5], k = 9
Output: 0

Constraints:

    1 <= nums.length <= 3 * 10^4
    -10^4 <= nums[i] <= 10^4
    2 <= k <= 10^4

*/

package main

func main() {
	assert(subdivk([]int{4, 5, 0, -2, -3, 1}, 5) == 7)
	assert(subdivk([]int{5}, 9) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func subdivk(a []int, k int) int {
	c := map[int]int{0: 1}
	p := 0
	r := 0
	for _, v := range a {
		p = (p + (v%k + k)) % k
		r += c[p]
		c[p] += 1
	}
	return r
}
