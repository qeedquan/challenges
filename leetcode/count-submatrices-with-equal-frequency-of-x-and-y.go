/*

Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:

grid[0][0]
an equal frequency of 'X' and 'Y'.
at least one 'X'.

Example 1:

Input: grid = [["X","Y","."],["Y",".","."]]

Output: 3

Explanation:
https://assets.leetcode.com/uploads/2024/06/07/examplems.png

Example 2:

Input: grid = [["X","X"],["X","Y"]]

Output: 0

Explanation:

No submatrix has an equal frequency of 'X' and 'Y'.

Example 3:

Input: grid = [[".","."],[".","."]]

Output: 0

Explanation:

No submatrix has at least one 'X'.

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 'X', 'Y', or '.'.

Hint 1
Replace ’X’ with 1, ’Y’ with -1 and ’.’ with 0.

Hint 2
You need to find how many submatrices grid[0..x][0..y] have a sum of 0 and at least one ’X’.

Hint 3
Use prefix sum to calculate submatrices sum.

*/

package main

func main() {
	assert(submatrices([][]int{
		{'X', 'Y', '.'},
		{'Y', '.', '.'},
	}) == 3)

	assert(submatrices([][]int{
		{'X', 'X'},
		{'X', 'Y'},
	}) == 0)

	assert(submatrices([][]int{
		{'.', '.'},
		{'.', '.'},
	}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func submatrices(m [][]int) int {
	if len(m) == 0 || len(m[0]) == 0 {
		return 0
	}

	w, h := len(m[0]), len(m)
	p1 := make([][]int, h+1)
	p2 := make([][]int, h+1)
	for i := range p1 {
		p1[i] = make([]int, w+1)
		p2[i] = make([]int, w+1)
	}

	r := 0
	for i := range h {
		for j := range w {
			p1[i+1][j+1] = p1[i][j+1] + p1[i+1][j] - p1[i][j] + truth(m[i][j] == 'X')
			p2[i+1][j+1] = p2[i][j+1] + p2[i+1][j] - p2[i][j] + truth(m[i][j] == 'Y')
			if p1[i+1][j+1] == p2[i+1][j+1] && p2[i+1][j+1] != 0 {
				r += 1
			}
		}
	}
	return r
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
