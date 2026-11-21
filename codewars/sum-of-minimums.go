/*

Given a 2D ( nested ) list ( array, vector, .. ) of size m * n, your task is to find the sum of the minimum values in each row.

For Example:

[ [ 1, 2, 3, 4, 5 ]        #  minimum value of row is 1
, [ 5, 6, 7, 8, 9 ]        #  minimum value of row is 5
, [ 20, 21, 34, 56, 100 ]  #  minimum value of row is 20
]
So the function should return 26 because the sum of the minimums is 1 + 5 + 20 = 26.

Note: You will always be given a non-empty list containing positive values.

ENJOY CODING :)

*/

package main

import "slices"

func main() {
	assert(sum([][]int{
		{1, 2, 3, 4, 5},
		{5, 6, 7, 8, 9},
		{20, 21, 34, 56, 100},
	}) == 26)

	assert(sum([][]int{
		{7, 9, 8, 6, 2},
		{6, 3, 5, 4, 3},
		{5, 8, 7, 4, 5},
	}) == 9)

	assert(sum([][]int{
		{11, 12, 14, 54},
		{67, 89, 90, 56},
		{7, 9, 4, 3},
		{9, 8, 6, 7},
	}) == 76)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sum(m [][]int) int {
	r := 0
	for i := range m {
		r += slices.Min(m[i])
	}
	return r
}
