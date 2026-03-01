/*

Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ,
subsequence a has a number less than the corresponding number in b.
For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

Example 1:

Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.

Example 2:

Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
1 <= k <= nums.length

Hint 1
In lexicographical order, the elements to the left have higher priority than those that come after.
Can you think of a strategy that incrementally builds the answer from left to right?

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{3, 5, 2, 6}, 2, []int{2, 6})
	test([]int{2, 4, 3, 3, 5, 4, 9, 6}, 4, []int{2, 3, 3, 4})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, k int, r []int) {
	p := competitive(a, k)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func competitive(a []int, k int) []int {
	p := []int{}
	for i, x := range a {
		for len(p) > 0 && p[len(p)-1] > x && len(p)+(len(a)-i) > k {
			p = p[:len(p)-1]
		}
		if len(p) < k {
			p = append(p, x)
		}
	}
	return p
}
