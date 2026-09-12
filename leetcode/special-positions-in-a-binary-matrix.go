/*

Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

Example 1:
https://assets.leetcode.com/uploads/2021/12/23/special1.jpg
Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.

Example 2:
https://assets.leetcode.com/uploads/2021/12/24/special-grid.jpg
Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.

Hint 1
Keep track of 1s in each row and in each column.
Then while iterating over matrix, if the current position is 1 and current row as well as current column contains exactly one occurrence of 1.

*/

package main

func main() {
	assert(special([][]int{
		{1, 0, 0},
		{0, 0, 1},
		{1, 0, 0},
	}) == 1)

	assert(special([][]int{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
	}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func special(mat [][]int) int {
	if len(mat) == 0 || len(mat[0]) == 0 {
		return 0
	}

	rows := make([]int, len(mat))
	cols := make([]int, len(mat[0]))
	for i := range len(rows) {
		for j := range len(cols) {
			if mat[i][j] != 0 {
				rows[i] += 1
				cols[j] += 1
			}
		}
	}

	res := 0
	for i := range len(rows) {
		for j := range len(cols) {
			if mat[i][j] == rows[i] && rows[i] == cols[j] && cols[j] == 1 {
				res += 1
			}
		}
	}
	return res
}
