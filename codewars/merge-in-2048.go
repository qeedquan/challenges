/*

Remember the game 2048? http://gabrielecirulli.github.io/2048/

The main part of this game is merging identical tiles in a row.

Implement a function that models the process of merging all of the tile values in a single row.
This function takes the array line as a parameter and returns a new array with the tile values from line slid towards the front of the array (index 0) and merged.
A given tile can only merge once.
Empty grid squares are represented as zeros.
Your function should work on arrays containing arbitrary number of elements.
Examples
merge([2,0,2,2])  -->  [4,2,0,0]
Another example with repeated merges:

merge([4,4,8,16])  -->  [8,8,16,0]
merge([8,8,16,0])  -->  [16,16,0,0]
merge([16,16,0,0]) -->  [32,0,0,0]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{2, 0, 2, 2}, []int{4, 2, 0, 0})
	test([]int{4, 4, 8, 16}, []int{8, 8, 16, 0})
	test([]int{8, 8, 16, 0}, []int{16, 16, 0, 0})
	test([]int{16, 16, 0, 0}, []int{32, 0, 0, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := merge(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func merge(a []int) []int {
	r := make([]int, len(a))
	n := 0
	m := 0
	for i := range a {
		switch {
		case m < 0 && n > 0 && a[i] == r[n-1]:
			m = n - 1
			r[m] *= 2
		case a[i] > 0:
			r[n], n = a[i], n+1
			m -= 2048 - a[n]
		}
	}
	return r
}
