/*

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
https://assets.leetcode.com/uploads/2021/02/18/enclaves1.jpg
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:
https://assets.leetcode.com/uploads/2021/02/18/enclaves2.jpg
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

Hint 1
Can you model this problem as a graph problem? Create n * m + 1 nodes where n * m nodes represents each cell of the map and one extra node to represent the exterior of the map.

Hint 2
In the map add edges between neighbors on land cells. And add edges between the exterior and land nodes which are in the boundary.
Return as answer the number of nodes that are not reachable from the exterior node.

*/

package main

func main() {
	assert(enclaves([][]int{
		{0, 0, 0, 0},
		{1, 0, 1, 0},
		{0, 1, 1, 0},
		{0, 0, 0, 0},
	}) == 3)

	assert(enclaves([][]int{
		{0, 1, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 0},
	}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func enclaves(A [][]int) int {
	for i := 0; i < len(A); i++ {
		dfs(A, i, 0)
		dfs(A, i, len(A[0])-1)
	}
	for j := 1; j < len(A)-1; j++ {
		dfs(A, 0, j)
		dfs(A, len(A)-1, j)
	}

	r := 0
	for i := range A {
		for j := range A[i] {
			r += A[i][j]
		}
	}
	return r
}

func dfs(A [][]int, i, j int) {
	dirs := [][2]int{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}
	if !(0 <= i && i < len(A) && 0 <= j && j < len(A[0]) && A[i][j] != 0) {
		return
	}

	A[i][j] = 0
	for _, d := range dirs {
		dfs(A, i+d[0], j+d[1])
	}
}
