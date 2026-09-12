/*

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation:
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1).
For nums[3]=2 there exist one smaller number than it (1).
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]


Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{8, 1, 2, 2, 3}, []int{4, 0, 1, 1, 3})
	test([]int{6, 5, 4, 8}, []int{2, 1, 0, 3})
	test([]int{7, 7, 7, 7}, []int{0, 0, 0, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := smallers(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func smallers(a []int) []int {
	b := append([]int{}, a...)
	sort.Ints(b)

	r := make([]int, len(a))
	for i := range a {
		r[i] = sort.Search(len(a), func(j int) bool {
			return a[i] <= b[j]
		})
	}
	return r
}
