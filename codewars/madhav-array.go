/*

A Madhav array has the following property:

a[0] = a[1] + a[2] = a[3] + a[4] + a[5] = a[6] + a[7] + a[8] + a[9] = ...

Complete the function/method that returns true if the given array is a Madhav array, otherwise it returns false.

Edge cases: An array of length 0 or 1 should not be considered a Madhav array as there is nothing to compare.

*/

package main

import (
	"math"
)

func main() {
	assert(madhav([]int{2, 1, 1}) == true)
	assert(madhav([]int{2, 1, 1, 4, -1, -1}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func madhav(a []int) bool {
	if len(a) < 2 {
		return false
	}

	for i := 1; i < math.MaxInt; i++ {
		n := triangular(i)
		m := triangular(i + 1)
		if m == len(a) {
			break
		}
		if m > len(a) || a[0] != sum(a[n:m]) {
			return false
		}
	}
	return true
}

func sum(a []int) int {
	r := 0
	for _, v := range a {
		r += v
	}
	return r
}

func triangular(n int) int {
	return n * (n + 1) / 2
}
