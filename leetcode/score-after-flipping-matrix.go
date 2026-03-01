/*

You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

Example 1:
https://assets.leetcode.com/uploads/2021/07/23/lc-toogle1.jpg
Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

Example 2:
Input: grid = [[0]]
Output: 1

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
grid[i][j] is either 0 or 1.

*/

package main

func main() {
	assert(score([][]int{
		{0, 0, 1, 1},
		{1, 0, 1, 0},
		{1, 1, 0, 0},
	}) == 39)

	assert(score([][]int{
		{0},
	}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func score(m [][]int) int {
	if len(m) == 0 || len(m[0]) == 0 {
		return 0
	}

	h := len(m)
	w := len(m[0])
	r := 0
	for x := range w {
		v := 0
		for y := range h {
			v += m[y][x] ^ m[y][0]
		}
		r += max(v, h-v) * (1 << (w - x - 1))
	}
	return r
}
