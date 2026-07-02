/*

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

*/

package main

import (
	"sort"
)

func main() {
	assert(negatives([][]int{
		{4, 3, 2, -1},
		{3, 2, 1, -1},
		{1, 1, -1, -2},
		{-1, -1, -2, -3},
	}) == 8)

	assert(negatives([][]int{
		{3, 2},
		{1, 0},
	}) == 0)

	assert(negatives([][]int{
		{9, 8, 7, 6},
		{5, 4, 3, 2},
		{1, 0, -1, -2},
		{-3, -4, -5, -6},
	}) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func negatives(m [][]int) int {
	if len(m) == 0 || len(m[0]) == 0 {
		return 0
	}

	r, c, n := len(m), len(m[0]), 0
	for i := 0; i < r; i++ {
		x := sort.Search(c, func(j int) bool {
			return m[i][j] < 0
		})
		n += c - x
	}
	return n
}
