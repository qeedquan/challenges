/*

Each element of an array with N integers has been modified by adding the array's largest element and subtracting its smallest element.
These modified values are provided in the same order as the original array.
Your task is to reconstruct the original array values.

Input
The first line contains a natural number N.
The second line contains N integers.
Each integer does not exceed 100 in absolute value.

Output
Print the original array values in a single line, separated by spaces.

Examples

Input #1
7
7 5 14 9 7 5 8

Answer #1
-2 -4 5 0 -2 -4 -1

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	fmt.Println(solve([]int{7, 5, 14, 9, 7, 5, 8}))
}

func solve(a []int) []int {
	n := len(a)
	if n == 0 {
		return []int{}
	}

	r := make([]int, n)
	x := slices.Max(a)
	y := slices.Min(a)
	for i := range n {
		r[i] = a[i] - x + y
	}
	return r
}
