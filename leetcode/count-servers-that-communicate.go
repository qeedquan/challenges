/*

You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server.
Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

Example 1:
https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-6.jpg
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.

Example 2:
https://assets.leetcode.com/uploads/2019/11/13/untitled-diagram-4.jpg
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

Example 3:
https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-1-3.jpg

Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other.
The two servers in the third column can communicate with each other.
The server at right bottom corner can't communicate with any other server.

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1

Hint 1
Store number of computer in each row and column.

Hint 2
Count all servers that are not isolated.

*/

package main

func main() {
	assert(count([][]int{{1, 0}, {0, 1}}) == 0)
	assert(count([][]int{{1, 0}, {1, 1}}) == 3)
	assert(count([][]int{{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func count(grid [][]int) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}

	rows := make([]int, len(grid))
	cols := make([]int, len(grid[0]))
	for i := range len(grid) {
		for j := range len(grid[0]) {
			if grid[i][j] != 0 {
				rows[i] += 1
				cols[j] += 1
			}
		}
	}

	result := 0
	for i := range len(grid) {
		for j := range len(grid[0]) {
			if grid[i][j] != 0 && (rows[i] > 1 || cols[j] > 1) {
				result += 1
			}
		}
	}
	return result
}
