/*

Given an array A of distinct integers sorted in ascending order,
return the smallest index i that satisfies A[i] == i.  Return -1 if no such i exists.

Example 1:

Input: [-10,-5,0,3,7]
Output: 3
Explanation:
For the given array, A[0] = -10, A[1] = -5, A[2] = 0, A[3] = 3, thus the output is 3.


Example 2:

Input: [0,2,5,8,17]
Output: 0
Explanation:
A[0] = 0, thus the output is 0.


Example 3:

Input: [-10,-5,3,4,7,9]
Output: -1
Explanation:
There is no such i that A[i] = i, thus the output is -1.


Note:

1 <= A.length < 10^4
-10^9 <= A[i] <= 10^9

*/

package main

import (
	"sort"
)

func main() {
	assert(fixedpoint([]int{-10, -5, 0, 3, 7}) == 3)
	assert(fixedpoint([]int{0, 2, 5, 8, 17}) == 0)
	assert(fixedpoint([]int{-10, -5, 3, 4, 7, 9}) == -1)
	assert(fixedpoint([]int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) == 0)
	assert(fixedpoint([]int{0, 1, 1, 3}) == 3)
	assert(fixedpoint([]int{}) == -1)
	assert(fixedpoint([]int{-20, -10, 2, 10, 20}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fixedpoint(a []int) int {
	n := sort.Search(len(a), func(i int) bool {
		return i <= a[i]
	})
	if n >= len(a) || n != a[n] {
		return -1
	}
	return n
}
