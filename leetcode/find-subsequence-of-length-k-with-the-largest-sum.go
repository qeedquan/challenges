/*

You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation:
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7.
Another possible subsequence is [4, 3].

Constraints:

1 <= nums.length <= 1000
-10^5 <= nums[i] <= 10^5
1 <= k <= nums.length

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{2, 1, 3, 3}, 2, []int{3, 3})
	test([]int{-1, -2, 3, 4}, 3, []int{-1, 3, 4})
	test([]int{3, 4, 3, 3}, 2, []int{3, 4})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, k int, r []int) {
	p := maxsubseq(a, k)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func maxsubseq(a []int, k int) []int {
	if k < 0 || k > len(a) {
		return nil
	}

	x := make([][2]int, len(a))
	for i, v := range a {
		x[i] = [2]int{i, v}
	}

	sort.Slice(x, func(i, j int) bool {
		return x[i][1] > x[j][1]
	})

	x = x[:k]
	sort.Slice(x, func(i, j int) bool {
		return x[i][0] < x[j][0]
	})

	r := make([]int, k)
	for i := range x {
		r[i] = x[i][1]
	}

	return r
}
