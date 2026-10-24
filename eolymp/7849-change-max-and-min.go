/*

Given an array of n integers. Change all its maximum elements to the minimum value, and all its minimum elements to the maximum value.

Input
The first line contains the number n (n≤100). The next line contains n integers, each of which does not exceed 100 in absolute value.

Output
Print the updated array.

Examples

Input #1
7
3 5 -7 7 5 -9 -4

Answer #1
3 5 -7 -9 5 7 -4

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	fmt.Println(solve([]int{3, 5, -7, 7, 5, -9, -4}))
}

func solve(a []int) []int {
	n := len(a)
	if n == 0 {
		return a
	}

	x := slices.Min(a)
	y := slices.Max(a)
	for i := range a {
		if a[i] == x {
			a[i] = y
		} else if a[i] == y {
			a[i] = x
		}
	}
	return a
}
