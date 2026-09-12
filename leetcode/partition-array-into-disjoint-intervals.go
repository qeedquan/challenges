/*

Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.

Test cases are generated such that partitioning exists.

Example 1:

Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]

Example 2:

Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]

Constraints:

2 <= nums.length <= 10^5
0 <= nums[i] <= 10^6
There is at least one valid answer for the given input.

*/

package main

func main() {
	assert(disjoints([]int{5, 0, 3, 8, 6}) == 3)
	assert(disjoints([]int{1, 1, 1, 0, 6, 12}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func disjoints(a []int) int {
	n := len(a)
	b := append([]int{}, a...)
	for i := n - 2; i > 0; i-- {
		b[i] = min(b[i], b[i+1])
	}

	m := 0
	for i := 1; i < n; i++ {
		m = max(m, a[i-1])
		if m <= b[i] {
			return i
		}
	}
	return -1
}
