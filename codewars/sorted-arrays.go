/*

Given any number of arrays each sorted in ascending order, find the nth smallest number of all their elements.

All the arguments except the last will be arrays, the last argument is n.

nthSmallest([1,5], [2], [4,8,9], 4) // returns 5 because it's the 4th smallest value
Be mindful of performance.

*/

package main

import (
	"sort"
)

func main() {
	assert(nthsmallest([][]int{{2, 4, 6, 8, 10, 12}}, 5) == 10)
	assert(nthsmallest([][]int{{2, 2, 2, 2, 2}}, 3) == 2)
	assert(nthsmallest([][]int{{1, 5}, {2}, {4, 8, 9}}, 4) == 5)
	assert(nthsmallest([][]int{{1}, {2}, {3}, {4}, {5, 6, 7, 8}, {9}, {10}}, 7) == 7)
	assert(nthsmallest([][]int{{1, 5}, {2}, {4, 8, 9}}, 4) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func nthsmallest(a [][]int, n int) int {
	x := []int{}
	for _, v := range a {
		x = append(x, v...)
	}

	sort.Ints(x)
	if n >= len(x) {
		return 0
	}
	return x[n-1]
}
