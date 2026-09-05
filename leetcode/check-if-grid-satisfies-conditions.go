/*

You are given a 2D matrix grid of size m x n. You need to check if each cell grid[i][j] is:

Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).
Return true if all the cells satisfy these conditions, otherwise, return false.

Example 1:
Input: grid = [[1,0,2],[1,0,2]]
Output: true
Explanation:
https://assets.leetcode.com/uploads/2024/04/15/examplechanged.png
All the cells in the grid satisfy the conditions.

Example 2:
Input: grid = [[1,1,1],[0,0,0]]
Output: false

Explanation:
https://assets.leetcode.com/uploads/2024/03/27/example21.png
All cells in the first row are equal.

Example 3:
Input: grid = [[1],[2],[3]]
Output: false
Explanation:
https://assets.leetcode.com/uploads/2024/03/31/changed.png
Cells in the first column have different values.


Constraints:

1 <= n, m <= 10
0 <= grid[i][j] <= 9

Hint 1
Check if each column has same value in each cell.

Hint 2
If the previous condition is satisfied, we can simply check the first cells in adjacent columns.

*/

package main

func main() {
	assert(satisfy([][]int{
		{1, 0, 2},
		{1, 0, 2},
	}) == true)

	assert(satisfy([][]int{
		{1, 1, 1},
		{0, 0, 0},
	}) == false)

	assert(satisfy([][]int{
		{1},
		{2},
		{3},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func satisfy(m [][]int) bool {
	for i := range len(m) {
		for j := range len(m[i]) {
			if i+1 < len(m) && m[i][j] != m[i+1][j] {
				return false
			}
			if j+1 < len(m[i]) && m[i][j] == m[i][j+1] {
				return false
			}
		}
	}
	return true
}
