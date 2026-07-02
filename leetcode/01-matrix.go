/*

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Example 1:
https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.

Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

*/

package main

import (
	"math"
	"reflect"
)

func main() {
	test(
		[][]int{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
		[][]int{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
	)

	test(
		[][]int{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}},
		[][]int{{0, 0, 0}, {0, 1, 0}, {1, 2, 1}},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, r [][]int) {
	update(m)
	assert(reflect.DeepEqual(m, r))
}

func update(m [][]int) [][]int {
	for i := range len(m) {
		for j := range len(m[i]) {
			if m[i][j] == 0 {
				continue
			}
			m[i][j] = math.MaxInt
			if i > 0 {
				m[i][j] = min(m[i][j], m[i-1][j]+1)
			}
			if j > 0 {
				m[i][j] = min(m[i][j], m[i][j-1]+1)
			}
		}
	}
	for i := len(m) - 1; i >= 0; i-- {
		for j := len(m[i]) - 1; j >= 0; j-- {
			if m[i][j] == 0 {
				continue
			}
			if i < len(m)-1 {
				m[i][j] = min(m[i][j], m[i+1][j]+1)
			}
			if j < len(m[i])-1 {
				m[i][j] = min(m[i][j], m[i][j+1]+1)
			}
		}
	}
	return m
}
