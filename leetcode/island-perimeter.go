/*

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:
https://assets.leetcode.com/uploads/2018/10/12/island.png
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:
Input: grid = [[1]]
Output: 4

Example 3:
Input: grid = [[1,0]]
Output: 4


Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.

*/

package main

func main() {
	assert(perimeter([][]int{
		{0, 1, 0, 0},
		{1, 1, 1, 0},
		{0, 1, 0, 0},
		{1, 1, 0, 0},
	}) == 16)

	assert(perimeter([][]int{
		{1},
	}) == 4)

	assert(perimeter([][]int{
		{1, 0},
	}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func perimeter(p [][]int) int {
	if len(p) == 0 || len(p[0]) == 0 {
		return 0
	}

	m := len(p)
	n := len(p[0])
	r := 0
	for i := range m {
		for j := range n {
			if p[i][j] == 1 {
				r += 4
				if i < m-1 && p[i+1][j] == 1 {
					r -= 2
				}
				if j < n-1 && p[i][j+1] == 1 {
					r -= 2
				}
			}
		}
	}
	return r
}
