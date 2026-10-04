/*

You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

Example 1:

Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.
Example 2:

Input: nums = [1,2,5,2,3], target = 3
Output: [3]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.
Example 3:

Input: nums = [1,2,5,2,3], target = 5
Output: [4]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.


Constraints:

1 <= nums.length <= 100
1 <= nums[i], target <= 100

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{1, 2, 5, 2, 3}, 2, []int{1, 2})
	test([]int{1, 2, 5, 2, 3}, 3, []int{3})
	test([]int{1, 2, 5, 2, 3}, 5, []int{4})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, t int, r []int) {
	p := targetindices(a, t)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func targetindices(a []int, t int) []int {
	sort.Ints(a)
	f := func(i int) bool { return a[i] >= t }
	x := sort.Search(len(a), f)
	r := []int{}
	for i := x; i < len(a); i++ {
		if a[i] != t {
			break
		}
		r = append(r, i)
	}
	return r
}
