/*

You are given an n x n integer matrix grid.

Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

Return the generated matrix.

Example 1:

Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
Output: [[9,9],[8,6]]
Explanation: The diagram above shows the original matrix and the generated matrix.
Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.

Example 2:

Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
Output: [[2,2,2],[2,2,2],[2,2,2]]
Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.

Constraints:

n == grid.length == grid[i].length
3 <= n <= 100
1 <= grid[i][j] <= 100

Hint:
Use nested loops to run through all possible 3 x 3 windows in the matrix.
For each 3 x 3 window, iterate through the values to get the maximum value within the window.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{
		{9, 9, 8, 1},
		{5, 6, 2, 6},
		{8, 2, 6, 4},
		{6, 2, 2, 2},
	}, [][]int{
		{9, 9},
		{8, 6},
	})

	test([][]int{
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 2, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
	}, [][]int{
		{2, 2, 2},
		{2, 2, 2},
		{2, 2, 2},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, r [][]int) {
	p := largestlocal(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func largestlocal(m [][]int) [][]int {
	n := len(m)
	r := alloc(n - 2)
	for i := 0; i < n-2; i++ {
		for j := 0; j < n-2; j++ {
			for x := i; x < i+3; x++ {
				for y := j; y < j+3; y++ {
					r[i][j] = max(r[i][j], m[x][y])
				}
			}
		}
	}
	return r
}

func alloc(n int) [][]int {
	if n < 0 {
		return [][]int{}
	}

	m := make([][]int, n)
	for i := range m {
		m[i] = make([]int, n)
	}
	return m
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
