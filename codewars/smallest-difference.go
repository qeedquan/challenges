/*

Given two arrays of integers, find the pair of values with the smallest difference and return that difference.

If both arrays are empty, return -1.

If one array is empty, return the smallest value from the non-empty array.

Note: Try to solve this without brute force.

Example:

  arr1 = [1, 3, 5, 23, 5]
  arr2 = [45, 34, 67, 2, 0]

  Output = 1

Example empty array:

  arr1 = [1, 3, 5, 23, 5]
  arr2 = []

  Output = 1

Example two empty arrays:

  arr1 = []
  arr2 = []

  Output = -1

*/

package main

import (
	"math"
	"slices"
	"sort"
)

func main() {
	arr1 := []int{1, 3, 5, 23, 5}
	arr2 := []int{45, 34, 67, 2, 0}
	longArr := []int{
		23, 4, 4, 2, 5, 6, 3434, 5, 7788, 3, 2, 45, 2, 56, 78, 89, 900, 2, 3,
		4, 5, 6, 7, 8, 10, 5, 7, 23, 2222, 45, 34, 56, 56, 23, 45, 56, 45454,
		33, 45, 12, 16, 23, 2, 67, 78, 7, 99, 31, 27, 14, 13, 56, 72, 2, 78,
		89, 34, 33, 2, 22, 55, 6, 22, 19, 45, 37, 19, 10, 2, 3, 4, 9,
	}
	negArr := []int{-3, -1, -5, -56}

	assert(smallestdiff([]int{}, []int{}) == -1)
	assert(smallestdiff(arr1, []int{}) == 1)
	assert(smallestdiff(arr2, []int{}) == 0)
	assert(smallestdiff(arr1, arr2) == 1)
	assert(smallestdiff(arr1, longArr) == 0)
	assert(smallestdiff(negArr, longArr) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func smallestdiff(a, b []int) int {
	n := len(a)
	m := len(b)
	if n == 0 && m == 0 {
		return -1
	}
	if n == 0 {
		return slices.Min(b)
	}
	if m == 0 {
		return slices.Min(a)
	}

	sort.Ints(a)
	sort.Ints(b)

	d := math.MaxInt
	for i, j := 0, 0; i < n && j < m; {
		d = min(d, abs(a[i]-b[j]))
		if a[i] < b[j] {
			i++
		} else {
			j++
		}
	}
	return d
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
