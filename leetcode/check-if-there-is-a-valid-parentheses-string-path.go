/*

A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

The path starts from the upper left cell (0, 0).
The path ends at the bottom-right cell (m - 1, n - 1).
The path only ever moves down or right.
The resulting parentheses string formed by the path is valid.
Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

Example 1:
https://assets.leetcode.com/uploads/2022/03/15/example1drawio.png
Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.

Example 2:
https://assets.leetcode.com/uploads/2022/03/15/example2drawio.png
Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is either '(' or ')'.

Hint 1
What observations can you make about the number of open brackets and close brackets for any prefix of a valid bracket sequence?

Hint 2
The number of open brackets must always be greater than or equal to the number of close brackets.

Hint 3
Could you use dynamic programming?

*/

package main

func main() {
	assert(validpath([][]byte{
		{'(', '(', '('},
		{')', '(', ')'},
		{'(', '(', ')'},
		{'(', '(', ')'},
	}) == true)

	assert(validpath([][]byte{
		{')', ')'},
		{'(', '('},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func validpath(p [][]byte) bool {
	if len(p) == 0 || len(p[0]) == 0 {
		return true
	}

	m := len(p)
	n := len(p[0])
	if (m+n-1)%2 == 1 || p[0][0] == ')' || p[m-1][n-1] == '(' {
		return false
	}

	v := make([][][]bool, m)
	for i := range v {
		v[i] = make([][]bool, n)
		for j := range v[i] {
			v[i][j] = make([]bool, m+n)
		}
	}
	return dfs(p, v, m, n, 0, 0, 0)
}

func dfs(p [][]byte, v [][][]bool, m, n, i, j, k int) bool {
	dirs := [3]int{1, 0, 1}

	if v[i][j][k] {
		return false
	}

	v[i][j][k] = true
	if p[i][j] == '(' {
		k++
	} else {
		k--
	}

	if k < 0 || k > m-i+n-j {
		return false
	}

	if i == m-1 && j == n-1 {
		return k == 0
	}

	for d := 0; d < 2; d++ {
		x, y := i+dirs[d], j+dirs[d+1]
		if x >= 0 && x < m && y >= 0 && y < n && dfs(p, v, m, n, x, y, k) {
			return true
		}
	}
	return false
}
