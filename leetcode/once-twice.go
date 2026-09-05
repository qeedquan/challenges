/*

You are given an integer array nums. In this array:

Exactly one element appears once.

Exactly one element appears twice.

All other elements appear exactly three times.

Return an integer array of length 2, where the first element is the one that appears once, and the second is the one that appears twice.

Your solution must run in O(n) time and O(1) space.

Example 1:

Input: nums = [2,2,3,2,5,5,5,7,7]

Output: [3,7]

Explanation:

The element 3 appears once, and the element 7 appears twice. The remaining elements each appear three times.

Example 2:

Input: nums = [4,4,6,4,9,9,9,6,8]

Output: [8,6]

Explanation:

The element 8 appears once, and the element 6 appears twice. The remaining elements each appear three times.

Constraints:

3 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
nums.length is a multiple of 3.
Exactly one element appears once, one element appears twice, and all other elements appear three times.

*/

package main

func main() {
	assert(oncetwice([]int{2, 2, 3, 2, 5, 5, 5, 7, 7}) == [2]int{3, 7})
	assert(oncetwice([]int{4, 4, 6, 4, 9, 9, 9, 6, 8}) == [2]int{8, 6})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func oncetwice(a []int) [2]int {
	var y1, y2, z1, z2 [3]int

	y1[0] = ^0
	for _, x := range a {
		for i := range 3 {
			y2[i] = (x & y1[mod(i-1, 3)]) | (^x & y1[i])
		}
		y1, y2 = y2, y1
	}

	z1[0] = ^0
	for _, x := range a {
		if (^x&y1[1] != 0) || (x&y1[2] != 0) {
			continue
		}
		for i := range 3 {
			z2[i] = (x & z1[mod(i-1, 3)]) | (^x & z1[i])
		}
		z1, z2 = z2, z1
	}
	return [2]int{z1[1], (z1[1] ^ y1[1]) | y1[2]}
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
