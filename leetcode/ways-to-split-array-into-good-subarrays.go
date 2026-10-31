/*

A subarray of an array is good if it contains exactly one element with the value 1.

Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [0,1,0,0,1]
Output: 3
Explanation: There are 3 ways to split nums into good subarrays:
- [0,1] [0,0,1]
- [0,1,0] [0,1]
- [0,1,0,0] [1]

Example 2:

Input: nums = [0,1,0]
Output: 1
Explanation: There is 1 way to split nums into good subarrays:
- [0,1,0]

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 1

Hint 1
If the array consists of only 0s answer is 0.

Hint 2
In the final split, exactly one separation point exists between two consecutive 1s.

Hint 3
In how many ways can separation points be put?

*/

package main

func main() {
	assert(splits([]int{0, 1, 0, 0, 1}) == 3)
	assert(splits([]int{0, 1, 0}) == 1)
	assert(splits([]int{0, 0, 0}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func splits(a []int) int {
	const mod = 1_000_000_007

	r, p := 1, -1
	for i := range a {
		if a[i] != 1 {
			continue
		}
		if p != -1 {
			r = (r * (i - p)) % mod
		}
		p = i
	}
	if p != -1 {
		return r
	}
	return 0
}
