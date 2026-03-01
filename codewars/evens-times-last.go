/*

Given a sequence of integers, return the sum of all the integers that have an even index (odd index in COBOL), multiplied by the integer at the last index.

Indices in sequence start from 0.

If the sequence is empty, you should return 0.

*/

package main

func main() {
	assert(evenlast([]int{2, 3, 4, 5}) == 30)
	assert(evenlast([]int{}) == 0)
	assert(evenlast([]int{2, 2, 2, 2}) == 8)
	assert(evenlast([]int{1, 3, 3, 1, 10}) == 140)
	assert(evenlast([]int{-11, 3, 3, 1, 10}) == 20)
	assert(evenlast([]int{-11}) == 121)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func evenlast(a []int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	r := a[0]
	for i := 2; i < n; i += 2 {
		r += a[i]
	}
	return r * a[n-1]
}
