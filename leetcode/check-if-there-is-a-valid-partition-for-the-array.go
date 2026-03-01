/*

You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

The subarray consists of exactly 2, equal elements. For example, the subarray [2,2] is good.
The subarray consists of exactly 3, equal elements. For example, the subarray [4,4,4] is good.
The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false.

Example 1:

Input: nums = [4,4,4,5,6]
Output: true
Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.

Example 2:

Input: nums = [1,1,1,2]
Output: false
Explanation: There is no valid partition for this array.

Constraints:

2 <= nums.length <= 10^5
1 <= nums[i] <= 10^6

Hint 1
How can you reduce the problem to checking if there is a valid partition for a smaller array?

Hint 2
Use dynamic programming to reduce the problem until you have an empty array.

*/

package main

func main() {
	assert(valid([]int{4, 4, 4, 5, 6}) == true)
	assert(valid([]int{1, 1, 1, 2}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func valid(a []int) bool {
	p := [4]int{0: 1}
	for i := range a {
		i1 := (i + 1) % 4
		i2 := (i - 1) % 4
		i3 := (i - 2) % 4

		p[i1] = 0
		if i-1 >= 0 && a[i] == a[i-1] {
			p[i1] |= p[i2]
		}
		if i-2 >= 0 && ((a[i] == a[i-1] && a[i-1] == a[i-2]) || (a[i] == a[i-1]+1 && a[i] == a[i-2]+2)) {
			p[i1] |= p[i3]
		}
	}
	return p[len(a)%4] != 0
}
