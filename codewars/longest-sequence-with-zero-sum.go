/*

Write a method that takes an array of signed integers, and returns the longest contiguous subsequence of this array that has a total sum of elements of exactly 0.

If more than one equally long subsequences have a zero sum, return the one starting at the highest index.

For example:
maxZeroSequenceLength([25, -35, 12, 6, 92, -115, 17, 2, 2, 2, -7, 2, -9, 16, 2, -11]) should return
[92, -115, 17, 2, 2, 2], because this is the longest zero-sum sequence in the array.

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	test(
		[]int{1, 2, -3, 7, 8, -16},
		[]int{1, 2, -3},
	)

	test(
		[]int{25, -35, 12, 6, 92, -115, 17, 2, 2, 2, -7, 2, -9, 16, 2, -11},
		[]int{92, -115, 17, 2, 2, 2},
	)

	test(
		[]int{1, 2, 3},
		[]int{},
	)

	test(
		[]int{2, -1, 1, -1, 1, -1, 1},
		[]int{-1, 1, -1, 1, -1, 1},
	)

	test(
		[]int{0},
		[]int{0},
	)

	test(
		[]int{0, 0, 0, 0, 0, 0},
		[]int{0, 0, 0, 0, 0, 0},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(array, expected []int) {
	result := maxzeros(array)
	fmt.Println(result)
	assert(slices.Equal(result, expected))
}

func maxzeros(array []int) []int {
	sum := 0
	best := 0
	start := 0
	seen := map[int]int{0: -1}
	for index, value := range array {
		sum += value
		if _, found := seen[sum]; found {
			length := index - seen[sum]
			if length > best {
				best, start = length, seen[sum]+1
			}
		} else {
			seen[sum] = index
		}
	}
	return array[start : start+best]
}
