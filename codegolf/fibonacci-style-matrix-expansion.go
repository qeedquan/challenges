/*

For each row and then column of a matrix, we can add an extra entry with the sum of the last two entries in that row or column. For example with the following input matrix:

[ 1 1 1 ]
[ 2 3 4 ]
The resulting matrix would be:

[ 1 1 1 2 ]
[ 2 3 4 7 ]
[ 3 4 5 9 ]
Given an input of an integer N and an [X,Y] matrix of size at least 2x2, perform the above expansion N times and output the result. The resulting matrix will always be of size [X+N,Y+N].

Examples:
Input:                     Output:

2, [ 0 0 ]                 [ 0 0 0 0 ]
   [ 0 0 ]                 [ 0 0 0 0 ]
                           [ 0 0 0 0 ]
                           [ 0 0 0 0 ]


3, [ 1 1 1 ]               [ 1  1  1  2  3  5 ]
   [ 2 3 4 ]               [ 2  3  4  7 11 18 ]
                           [ 3  4  5  9 14 23 ]
                           [ 5  7  9 16 25 41 ]
                           [ 8 11 14 25 39 64 ]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{
		{0, 0},
		{0, 0},
	}, 2, [][]int{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	})

	test([][]int{
		{1, 1, 1},
		{2, 3, 4},
	}, 1, [][]int{
		{1, 1, 1, 2},
		{2, 3, 4, 7},
		{3, 4, 5, 9},
	})

	test([][]int{
		{1, 1, 1},
		{2, 3, 4},
	}, 3, [][]int{
		{1, 1, 1, 2, 3, 5},
		{2, 3, 4, 7, 11, 18},
		{3, 4, 5, 9, 14, 23},
		{5, 7, 9, 16, 25, 41},
		{8, 11, 14, 25, 39, 64},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m [][]int, n int, r [][]int) {
	f := fibmex(m, n)
	dump(f)
	assert(reflect.DeepEqual(f, r))
}

func fibmex(m [][]int, n int) [][]int {
	if len(m) == 0 || len(m[0]) == 0 {
		return [][]int{}
	}

	c, r := len(m[0]), len(m)
	f := alloc(r+n, c+n)

	for i := range m {
		for j := range m[i] {
			f[i][j] = m[i][j]
		}
	}

	for i := range f {
		for j := 0; j < n; j++ {
			f[i][c+j] = f[i][c+j-2] + f[i][c+j-1]
		}
	}

	for i := 0; i < c+n; i++ {
		for j := 0; j < n; j++ {
			f[r+j][i] = f[r+j-2][i] + f[r+j-1][i]
		}
	}

	return f
}

func alloc(r, c int) [][]int {
	m := make([][]int, r)
	t := make([]int, r*c)
	for i := range m {
		m[i] = t[i*c : (i+1)*c]
	}
	return m
}

func dump(m [][]int) {
	for i := range m {
		fmt.Println(m[i])
	}
	fmt.Println()
}
