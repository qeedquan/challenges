/*

Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.

Example 1:
https://assets.leetcode.com/uploads/2020/04/15/sample_1_1791.png
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.

Example 2:
https://assets.leetcode.com/uploads/2020/04/15/sample_2_1791.png
Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.

Constraints:

1 <= nums.length <= 10^5
0 <= k <= nums.length
nums[i] is 0 or 1

Hint 1
Each time you find a number 1, check whether or not it is K or more places away from the next one. If it's not, return false.

*/

package main

func main() {
	assert(kapart([]int{1, 0, 0, 0, 1, 0, 0, 1}, 2) == true)
	assert(kapart([]int{1, 0, 0, 1, 0, 1}, 2) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func kapart(a []int, k int) bool {
	p := -k - 1
	for i := range a {
		if a[i] == 0 {
			continue
		}
		if i-p <= k {
			return false
		}
		p = i
	}
	return true
}
