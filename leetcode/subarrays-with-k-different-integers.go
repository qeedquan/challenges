/*

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

Constraints:

1 <= nums.length <= 2 * 10^4
1 <= nums[i], k <= nums.length

Hint 1
Try generating all possible subarrays and check for the number of unique integers. Increment the count accordingly.

Hint 2
How about using a map to store the count of integers?

Hint 3
Think about the Sliding Window and 2-pointer approach.

*/

package main

func main() {
	assert(solve([]int{1, 2, 1, 2, 3}, 2) == 7)
	assert(solve([]int{1, 2, 1, 3, 4}, 3) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int, k int) int {
	return atmostk(a, k) - atmostk(a, k-1)
}

func atmostk(a []int, k int) int {
	c := make(map[int]int)
	r := 0
	j := 0
	for i := range a {
		c[a[i]] += 1
		for ; len(c) > k; j++ {
			if c[a[j]]--; c[a[j]] == 0 {
				delete(c, a[j])
			}
		}
		r += i - j + 1
	}
	return r
}
