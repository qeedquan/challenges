/*

You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.

Example 1:
Input: grid = [[0,1,0],[1,0,1]]
Output: 6
Explanation:
https://assets.leetcode.com/uploads/2024/05/08/examplerect0.png
The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

Example 2:
Input: grid = [[1,0],[0,0]]
Output: 1
Explanation:
https://assets.leetcode.com/uploads/2024/05/08/examplerect1.png
The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 0 or 1.
The input is generated such that there is at least one 1 in grid.

Hint 1
Find the minimum and maximum coordinates of a cell with a value of 1 in both directions.

*/

package main

func main() {
	assert(area([][]int{{0, 1, 0}, {1, 0, 1}}) == 6)
	assert(area([][]int{{1, 0}, {0, 0}}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func area(grid [][]int) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}

	min_r, max_r, min_c, max_c := len(grid), -1, len(grid[0]), -1
	for i := range len(grid) {
		for j := range len(grid[i]) {
			if grid[i][j] != 0 {
				min_r, max_r, min_c, max_c = min(min_r, i), max(max_r, i), min(min_c, j), max(max_c, j)
			}
		}
	}
	return (max_r - min_r + 1) * (max_c - min_c + 1)
}
