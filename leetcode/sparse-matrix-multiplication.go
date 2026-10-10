/*

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[][]int{{1, 0, 0}, {-1, 0, 3}},
		[][]int{{7, 0, 0}, {0, 0, 0}, {0, 0, 1}},
		[][]int{{7, 0, 0}, {-7, 0, 3}},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, r [][]int) {
	c := mul(a, b)
	fmt.Println(c)
	assert(reflect.DeepEqual(c, r))
}

func mul(a, b [][]int) [][]int {
	if len(a) == 0 || len(a[0]) == 0 || len(b) == 0 || len(b[0]) == 0 {
		return [][]int{}
	}

	m := len(a)
	n := len(a[0])
	l := len(b[0])
	r := make([][]int, m)
	for i := range r {
		r[i] = make([]int, l)
	}

	for i := range m {
		for k := range n {
			if a[i][k] == 0 {
				continue
			}
			for j := range l {
				r[i][j] += a[i][k] * b[k][j]
			}
		}
	}
	return r
}
