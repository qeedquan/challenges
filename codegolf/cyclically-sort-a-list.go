/*

Given a list of Integers greater than zero, Sort each of the unique values in ascending order, then repeat the process on the remaining duplicate values and append.

Example:

[1,5,2,2,8,3,5,2,9] ==> [1,2,3,5,8,9,2,5,2]

*/

package main

import (
	"reflect"
	"sort"
)

func main() {
	assert(reflect.DeepEqual(cyclicsort([]int{1, 5, 2, 2, 8, 3, 5, 2, 9}), []int{1, 2, 3, 5, 8, 9, 2, 5, 2}))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cyclicsort(a []int) []int {
	r := [][2]int{}
	m := make(map[int]int)
	for _, v := range a {
		r = append(r, [2]int{v, m[v]})
		m[v] += 1
	}

	sort.Slice(r, func(i, j int) bool {
		if r[i][1] == r[j][1] {
			return r[i][0] < r[j][0]
		}
		return r[i][1] < r[j][1]
	})

	for i := range a {
		a[i] = r[i][0]
	}
	return a
}
