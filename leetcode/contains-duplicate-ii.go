/*

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
0 <= k <= 10^5

*/

package main

func main() {
	assert(contains([]int{1, 2, 3, 1}, 3) == true)
	assert(contains([]int{1, 0, 1, 1}, 1) == true)
	assert(contains([]int{1, 2, 3, 1, 2, 3}, 2) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func contains(a []int, k int) bool {
	d := map[int]int{}
	for i, x := range a {
		if j, ok := d[x]; ok && i-j <= k {
			return true
		}
		d[x] = i
	}
	return false
}
