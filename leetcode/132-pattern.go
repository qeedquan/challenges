/*

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


Constraints:

n == nums.length
1 <= n <= 2 * 10^5
-10^9 <= nums[i] <= 10^9

*/

package main

func main() {
	assert(find132([]int{1, 2, 3, 4}) == false)
	assert(find132([]int{3, 1, 4, 2}) == true)
	assert(find132([]int{-1, 3, 2, 0}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func find132(a []int) bool {
	var (
		p []int
		x int
	)
	for i := len(a) - 1; i >= 0; i-- {
		if a[i] < x {
			return true
		}

		for {
			n := len(p)
			if n == 0 || p[n-1] >= a[i] {
				break
			}
			x, p = p[n-1], p[:n-1]
		}
		p = append(p, a[i])
	}

	return false
}
