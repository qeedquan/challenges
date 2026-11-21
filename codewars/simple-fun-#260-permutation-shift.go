/*

Task
Define the permutation element shift as the difference between the element's value and its index. For example, for permutation [1, 0, 2, 3] of array [0, 1, 2, 3] shifts for the respective elements are [1, -1, 0, 0].

Define the permutation shift as the difference between the maximal and the minimal element shifts among all of the permutation elements.

Given a permutation of integers from 0 to n - 1 for some integer n, find its shift.

Input/Output
[input] integer array permutation

Array of integers containing each integer from 0 to n - 1, inclusive, exactly once (where n is the array length).

1 ≤ permutation.length ≤ 100

[output] an integer

Example
For permutation = [1, 0, 2, 3], the output should be 2.

Its maximal and the minimal element shifts are 1 and -1, so the output is 1 - -1 = 2.

*/

package main

import (
	"math"
)

func main() {
	assert(permshift([]int{1, 0, 2, 3}) == 2)
	assert(permshift([]int{0, 1, 2, 3, 5, 4}) == 2)
	assert(permshift([]int{5, 4, 3, 2, 1, 0}) == 10)
	assert(permshift([]int{0, 1, 2, 3, 4}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func permshift(a []int) int {
	if len(a) == 0 {
		return 0
	}

	x0 := math.MaxInt
	x1 := math.MinInt
	for i := range a {
		x := a[i] - i
		x0 = min(x0, x)
		x1 = max(x1, x)
	}
	return x1 - x0
}
