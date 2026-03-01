/*

Return a new array that contains exactly the same elements as the input array, but with elements a and b swapped.

If the array has multiple copies of a, swap only the first one that appears in the array.
If the array has multiple copies of b, swap only the last one that appears in the array.

For example:

([1, 2, 3, 4], 2, 4) -> [1, 4, 3, 2]
([1, 2, 3, 4, 1, 2, 3, 4], 2, 4) -> [1, 4, 3, 4, 1, 2, 3, 2]

*/

package main

import (
	"fmt"
	"reflect"
	"slices"
)

func main() {
	test([]int{1, 2, 3, 4}, 2, 4, []int{1, 4, 3, 2})
	test([]int{1, 2, 3, 4, 1, 2, 3, 4}, 2, 4, []int{1, 4, 3, 4, 1, 2, 3, 2})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, x, y int, r []int) {
	p := swaptwo(a, x, y)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func swaptwo(a []int, x, y int) []int {
	r := append([]int{}, a...)
	i := slices.Index(r, x)
	j := -1
	for j = range slices.Backward(a) {
		if a[j] == y {
			break
		}
	}
	if i >= 0 && j >= 0 {
		r[i], r[j] = r[j], r[i]
	}
	return r
}
