/*

Given an array (or list or vector) of arrays (or, guess what, lists or vectors) of integers, your goal is to return the sum of a specific set of numbers, starting with elements whose position is equal to the main array length and going down by one at each step.

Say for example the parent array (etc, etc) has 3 sub-arrays inside: you should consider the third element of the first sub-array, the second of the second array and the first element in the third one: [[3, 2, 1, 0], [4, 6, 5, 3, 2], [9, 8, 7, 4]] would have you considering 1 for [3, 2, 1, 0], 6 for [4, 6, 5, 3, 2] and 9 for [9, 8, 7, 4], which sums up to 16.

One small note is that not always each sub-array will have enough elements, in which case you should then use a default value (if provided) or 0 (if not provided), as shown in the test cases.

*/

package main

func main() {
	assert(elementsum([][]int{{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}}) == 16)
	assert(elementsum([][]int{{3}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}}) == 15)
	assert(elementsum([][]int{{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {}}) == 7)
	assert(elementsum([][]int{{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {5}}) == 12)
	assert(elementsum([][]int{{3, 2}, {4}, {}}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func elementsum(a [][]int) int {
	r := 0
	for i := range a {
		j := len(a) - i - 1
		if 0 <= j && j < len(a[i]) {
			r += a[i][j]
		}
	}
	return r
}
