/*

Task

Alireza and Ali have a 3×3 table and playing on that. They have 4 tables (2×2) A,B,C and D in this table.

At beginning all of 9 numbers in 3×3 table is zero.

Alireza in each move choose a 2×2 table from A, B, C and D and increase all of 4 numbers in that by one.

He asks Ali, how much he increase table A, B, C and D. (if he cheats you should return [-1])

Your task is to help Ali.
Example

For

table=
[[1,2,1],
[2,4,2],
[1,2,1]]

The result should be [1,1,1,1]

For:

table=
[[3,7,4],
[5,16,11],
[2,9,7]]

The result should be [3,4,2,7]
Input/Output

    [input] 2D integer array table, 3×3 table.

    [output] an integer array

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{
		{1, 2, 1},
		{2, 4, 2},
		{1, 2, 1},
	}, []int{1, 1, 1, 1})

	test([][]int{
		{3, 7, 4},
		{5, 16, 11},
		{2, 9, 7},
	}, []int{3, 4, 2, 7})

	test([][]int{
		{1, 4, 2},
		{5, 10, 5},
		{4, 7, 3},
	}, []int{-1})

	test([][]int{
		{2, 4, 2},
		{4, 6, 4},
		{2, 4, 2},
	}, []int{-1})

	test([][]int{
		{2, 4, 2},
		{4, 8, 4},
		{2, 4, 2},
	}, []int{2, 2, 2, 2})

	test([][]int{
		{1, 3, 2},
		{5, 10, 5},
		{4, 7, 3},
	}, []int{1, 2, 4, 3})

	test([][]int{
		{1, 2, 1},
		{1, 2, 1},
		{1, 2, 1},
	}, []int{-1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m [][]int, r []int) {
	p := tablegame(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func tablegame(m [][]int) []int {
	switch {
	case m[1][1] != m[0][0]+m[0][2]+m[2][0]+m[2][2]:
		fallthrough
	case m[0][1] != m[0][0]+m[0][2]:
		fallthrough
	case m[1][0] != m[0][0]+m[2][0]:
		fallthrough
	case m[1][2] != m[0][2]+m[2][2]:
		fallthrough
	case m[2][1] != m[2][0]+m[2][2]:
		return []int{-1}
	}
	return []int{m[0][0], m[0][2], m[2][0], m[2][2]}
}
