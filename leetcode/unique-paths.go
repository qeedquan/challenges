/*

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

Example 1:
https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:

1 <= m, n <= 100

*/

package main

func main() {
	assert(uniquepaths(3, 7) == 28)
	assert(uniquepaths(3, 2) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func uniquepaths(m, n int) int {
	if m <= 1 || n <= 1 {
		return 1
	}

	p := make([][]int, m)
	for i := range p {
		p[i] = make([]int, n)
	}

	for i := range n {
		p[0][i] = 1
	}

	for i := range m {
		p[i][0] = 1
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			p[i][j] = p[i-1][j] + p[i][j-1]
		}
	}

	return p[m-1][n-1]
}
