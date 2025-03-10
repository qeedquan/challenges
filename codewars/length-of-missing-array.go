/*

You get an array of arrays.
If you sort the arrays by their length, you will see, that their length-values are consecutive.
But one array is missing!


You have to write a method, that return the length of the missing array.

Example:
[[1, 2], [4, 5, 1, 1], [1], [5, 6, 7, 8, 9]] --> 3

If the array of arrays is null/nil or empty, the method should return 0.

When an array in the array is null or empty, the method should return 0 too!
There will always be a missing element and its length will be always between the given arrays.

Have fun coding it and please don't forget to vote and rank this kata! :-)

I have created other katas. Have a look if you like coding and challenges.

*/

package main

import (
	"math"
)

func main() {
	assert(lengthOfMissingArray([][]int{{1, 2}, {4, 5, 1, 1}, {1}, {5, 6, 7, 8, 9}}) == 3)
	assert(lengthOfMissingArray([][]int{{5, 2, 9}, {4, 5, 1, 1}, {1}, {5, 6, 7, 8, 9}}) == 2)
	assert(lengthOfMissingArray([][]int{{'a', 'a', 'a'}, {'a', 'a'}, {'a', 'a', 'a', 'a'}, {'a'}, {'a', 'a', 'a', 'a', 'a', 'a'}}) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lengthOfMissingArray(arrays [][]int) int {
	lengths := make(map[int]bool)
	minimum := math.MaxInt
	maximum := math.MinInt
	for _, array := range arrays {
		lengths[len(array)] = true
		minimum = min(minimum, len(array))
		maximum = max(maximum, len(array))
	}
	for i := minimum + 1; i <= maximum; i++ {
		if !lengths[i] {
			return i
		}
	}
	return 0
}
