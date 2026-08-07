/*

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:

Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Example 2:

Input: nums = [4,2,3,4]
Output: 4


Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000

*/

package main

import "sort"

func main() {
	assert(triangle([]int{2, 2, 3, 4}) == 3)
	assert(triangle([]int{4, 2, 3, 4}) == 4)
	assert(triangle([]int{1, 2}) == 0)
	assert(triangle([]int{1}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func triangle(a []int) int {
	sort.Ints(a)

	r := 0
	for k := len(a) - 1; k > 1; k-- {
		for i, j := 0, k-1; i < j; {
			if a[i]+a[j] > a[k] {
				r += j - i
				j -= 1
			} else {
				i += 1
			}
		}
	}
	return r
}
