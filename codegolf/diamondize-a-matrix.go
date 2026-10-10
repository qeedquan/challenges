/*

Given a matrix, output a representation of the matrix where the top left element is on top, the anti-diagonal is the central row and the bottom right element is at the bottom.

For example, consider the following matrix:

1 2 3
4 5 6
7 8 9
The diamond version of this matrix is:

  1
 4 2
7 5 3
 8 6
  9
Inputs and outputs
An input matrix will be given as a list of lists (or anything similar in your language of choice). The output shall be a list of lists as well.

The matrices will only contain positive integers.

The input matrix will not necessarily be square.

The input matrix will be at least 1×1.

Test Cases
Input:  [[1]]
Output: [[1]]

Input:  [[1,2],[3,4]]
Output: [[1],[3,2],[4]]

Input:  [[1,2,3],[4,5,6]]
Output: [[1],[4,2],[5,3],[6]]

Input:  [[11,2,5],[3,99,3],[4,8,15],[16,23,42]]
Output: [[11],[3,2],[4,99,5],[16,8,3],[23,15],[42]]

Scoring
This is code-golf, so the shortest answer in bytes wins.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{{1}}, [][]int{{1}})
	test([][]int{{1, 2}, {3, 4}}, [][]int{{1}, {3, 2}, {4}})
	test([][]int{{1, 2, 3}, {4, 5, 6}}, [][]int{{1}, {4, 2}, {5, 3}, {6}})
	test([][]int{{11, 2, 5}, {3, 99, 3}, {4, 8, 15}, {16, 23, 42}}, [][]int{{11}, {3, 2}, {4, 99, 5}, {16, 8, 3}, {23, 15}, {42}})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, r [][]int) {
	p := diamondize(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func diamondize(m [][]int) [][]int {
	p := [][]int{}
	if len(m) == 0 || len(m[0]) == 0 {
		return p
	}

	r := len(m)
	c := len(m[0])
	i := 0
	j := 0
	for i < r && j < c {
		p = append(p, diag(m, i, j, r, c))
		if i < r-1 {
			i++
		} else {
			j++
		}
	}

	return p
}

func diag(m [][]int, i, j, r, c int) []int {
	x := []int{}
	for i >= 0 && j >= 0 && i < r && j < c {
		x, i, j = append(x, m[i][j]), i-1, j+1
	}
	return x
}
