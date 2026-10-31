/*

Write a function groupIn10s which takes any number of arguments, and groups them into sets of 10s and sorts each group in ascending order.

The return value should be an array of arrays, so that numbers between 0-9 inclusive are in position 0 and numbers 10-19 are in position 1, etc.

Here's an example of the required output:

const grouped = groupIn10s(8, 12, 38, 3, 17, 19, 25, 35, 50)

grouped[0]     // [3, 8]
grouped[1]     // [12, 17, 19]
grouped[2]     // [25]
grouped[3]     // [35, 38]
grouped[4]     // undefined
grouped[5]     // [50]

*/

package main

import (
	"fmt"
	"slices"
	"sort"
)

func main() {
	fmt.Println(group10([]int{8, 12, 38, 3, 17, 19, 25, 35, 50}))
}

func group10(a []int) [][]int {
	m := slices.Max(a)
	r := make([][]int, m/10+1)
	for _, x := range a {
		i := x / 10
		r[i] = append(r[i], x)
	}
	for i := range r {
		sort.Ints(r[i])
	}
	return r
}
