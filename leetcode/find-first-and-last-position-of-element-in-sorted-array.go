/*

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9

*/

package main

import (
	"sort"
)

func main() {
	assert(searchrange([]int{1, 2, 3, 8, 8, 8, 9, 9}, 8) == [2]int{3, 5})
	assert(searchrange([]int{5, 7, 7, 8, 8, 10}, 8) == [2]int{3, 4})
	assert(searchrange([]int{5, 7, 7, 8, 8, 10}, 6) == [2]int{-1, -1})
	assert(searchrange([]int{}, 0) == [2]int{-1, -1})
	assert(searchrange([]int{1, 1, 1, 1, 1}, 1) == [2]int{0, 4})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func searchrange(a []int, t int) [2]int {
	x := sort.Search(len(a), func(i int) bool { return t <= a[i] })
	if x >= len(a) || a[x] != t {
		return [2]int{-1, -1}
	}

	a = a[x+1:]

	y := sort.Search(len(a), func(i int) bool { return t < a[i] })
	if y > len(a) || a[y-1] != t {
		y = 0
	}

	return [2]int{x, x + y}
}
