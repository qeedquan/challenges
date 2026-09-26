/*

In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.


Example 1:
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.

Hint 1
Use recursion to try all such paths and find the one with the maximum value.

*/

package main

func main() {
	assert(maxgold([][]int{{0, 6, 0}, {5, 8, 7}, {0, 9, 0}}) == 24)
	assert(maxgold([][]int{{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}}) == 28)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxgold(m [][]int) int {
	r := 0
	for i := range m {
		for j := range m[i] {
			if m[i][j] != 0 {
				r = max(r, backtrack(m, i, j))
			}
		}
	}
	return r
}

func backtrack(m [][]int, i, j int) int {
	dirs := [][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

	r := 0
	m[i][j] = -m[i][j]
	for _, d := range dirs {
		ni, nj := i+d[0], j+d[1]
		if !(0 <= ni && ni < len(m) && 0 <= nj && nj < len(m[i]) && m[ni][nj] > 0) {
			continue
		}
		r = max(r, backtrack(m, ni, nj))
	}
	m[i][j] = -m[i][j]
	return m[i][j] + r
}
