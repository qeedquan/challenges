/*

Challenge:
Take a list, L containing positive integers as input:

3 5 2 1 6
and create a matrix where the n'th column contains the vector 1:L(n), where shorter rows are padded with zeros.

Test cases:
3   5   2   1   6
-----------------
1   1   1   1   1
2   2   2   0   2
3   3   0   0   3
0   4   0   0   4
0   5   0   0   5
0   0   0   0   6

1
-
1

1   2   3   4   3   2   1
-------------------------
1   1   1   1   1   1   1
0   2   2   2   2   2   0
0   0   3   3   3   0   0
0   0   0   4   0   0   0

Rules:
Optional input and output formats
List of lists is an acceptable output format
The matrix must be as small as possible (you may not pad it with more zeros than needed)
Shortest code in each language wins
Explanations are highly encouraged

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{3, 5, 2, 1, 6}, [][]int{
		{1, 1, 1, 1, 1},
		{2, 2, 2, 0, 2},
		{3, 3, 0, 0, 3},
		{0, 4, 0, 0, 4},
		{0, 5, 0, 0, 5},
		{0, 0, 0, 0, 6},
	})

	test([]int{1}, [][]int{
		{1},
	})

	test([]int{1, 2, 3, 4, 3, 2, 1}, [][]int{
		{1, 1, 1, 1, 1, 1, 1},
		{0, 2, 2, 2, 2, 2, 0},
		{0, 0, 3, 3, 3, 0, 0},
		{0, 0, 0, 4, 0, 0, 0},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, r [][]int) {
	m := columns(a)
	dump(m)
	assert(reflect.DeepEqual(m, r))
}

func columns(a []int) [][]int {
	r := maximum(a)
	c := len(a)
	m := allocate(r, c)
	for i, v := range a {
		for j := 0; j < v; j++ {
			m[j][i] = j + 1
		}
	}
	return m
}

func allocate(r, c int) [][]int {
	m := make([][]int, r)
	for i := range m {
		m[i] = make([]int, c)
	}
	return m
}

func maximum(a []int) int {
	r := 0
	for _, v := range a {
		r = max(r, v)
	}
	return r
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func dump(m [][]int) {
	for i := range m {
		for j := range m[i] {
			fmt.Printf("%d ", m[i][j])
		}
		fmt.Println()
	}
	fmt.Println()
}
