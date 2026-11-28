/*

You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:

The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

Example 1:

Input: nums = [1,3,4,8,7,9,3,5,1], k = 2

Output: [[1,1,3],[3,4,5],[7,8,9]]

Explanation:

The difference between any two elements in each array is less than or equal to 2.

Example 2:

Input: nums = [2,4,2,2,5,2], k = 2

Output: []

Explanation:

Different ways to divide nums into 2 arrays of size 3 are:

[[2,2,2],[2,4,5]] (and its permutations)
[[2,2,4],[2,2,5]] (and its permutations)
Because there are four 2s there will be an array with the elements 2 and 5 no matter how we divide it. since 5 - 2 = 3 > k, the condition is not satisfied and so there is no valid division.

Example 3:

Input: nums = [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14

Output: [[2,2,2],[4,5,5],[5,5,7],[7,8,8],[9,9,10],[11,12,12]]

Explanation:

The difference between any two elements in each array is less than or equal to 14.

Constraints:

n == nums.length
1 <= n <= 10^5
n is a multiple of 3
1 <= nums[i] <= 10^5
1 <= k <= 10^5

Hint 1
Try to use a greedy approach.

Hint 2
Sort the array and try to group each 3 consecutive elements.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(
		[]int{1, 3, 4, 8, 7, 9, 3, 5, 1}, 2,
		[][]int{{1, 1, 3}, {3, 4, 5}, {7, 8, 9}},
	)

	test(
		[]int{2, 4, 2, 2, 5, 2}, 2,
		[][]int{},
	)

	test(
		[]int{4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11}, 14,
		[][]int{{2, 2, 2}, {4, 5, 5}, {5, 5, 7}, {7, 8, 8}, {9, 9, 10}, {11, 12, 12}},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, k int, r [][]int) {
	p := divide(a, k)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func divide(a []int, k int) [][]int {
	sort.Ints(a)

	n := len(a)
	r := [][]int{}
	for i := 0; i+2 < n; i += 3 {
		if a[i+2]-a[i] > k {
			return [][]int{}
		}
		r = append(r, a[i:i+3])
	}
	return r
}
