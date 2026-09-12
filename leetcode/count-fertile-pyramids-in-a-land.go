/*

A farmer has a rectangular grid of land with m rows and n columns that can be divided into unit cells. Each cell is either fertile (represented by a 1) or barren (represented by a 0). All cells outside the grid are considered barren.

A pyramidal plot of land can be defined as a set of cells with the following criteria:

The number of cells in the set has to be greater than 1 and all cells must be fertile.
The apex of a pyramid is the topmost cell of the pyramid. The height of a pyramid is the number of rows it covers. Let (r, c) be the apex of the pyramid, and its height be h. Then, the plot comprises of cells (i, j) where r <= i <= r + h - 1 and c - (i - r) <= j <= c + (i - r).
An inverse pyramidal plot of land can be defined as a set of cells with similar criteria:

The number of cells in the set has to be greater than 1 and all cells must be fertile.
The apex of an inverse pyramid is the bottommost cell of the inverse pyramid. The height of an inverse pyramid is the number of rows it covers. Let (r, c) be the apex of the pyramid, and its height be h. Then, the plot comprises of cells (i, j) where r - h + 1 <= i <= r and c - (r - i) <= j <= c + (r - i).
Some examples of valid and invalid pyramidal (and inverse pyramidal) plots are shown below. Black cells indicate fertile cells.

https://assets.leetcode.com/uploads/2021/11/08/image.png

Given a 0-indexed m x n binary matrix grid representing the farmland, return the total number of pyramidal and inverse pyramidal plots that can be found in grid.

Example 1:
https://assets.leetcode.com/uploads/2021/12/22/1.JPG
Input: grid = [[0,1,1,0],[1,1,1,1]]
Output: 2
Explanation: The 2 possible pyramidal plots are shown in blue and red respectively.
There are no inverse pyramidal plots in this grid.
Hence total number of pyramidal and inverse pyramidal plots is 2 + 0 = 2.

Example 2:
https://assets.leetcode.com/uploads/2021/12/22/2.JPG
Input: grid = [[1,1,1],[1,1,1]]
Output: 2
Explanation: The pyramidal plot is shown in blue, and the inverse pyramidal plot is shown in red.
Hence the total number of plots is 1 + 1 = 2.

Example 3:
https://assets.leetcode.com/uploads/2021/12/22/3.JPG
Input: grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
Output: 13
Explanation: There are 7 pyramidal plots, 3 of which are shown in the 2nd and 3rd figures.
There are 6 inverse pyramidal plots, 2 of which are shown in the last figure.
The total number of plots is 7 + 6 = 13.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 10^5
grid[i][j] is either 0 or 1.

Hint 1
Think about how dynamic programming can help solve the problem.

Hint 2
For any fixed cell (r, c), can you calculate the maximum height of the pyramid for which it is the apex? Let us denote this value as dp[r][c].

Hint 3
How will the values at dp[r+1][c-1] and dp[r+1][c+1] help in determining the value at dp[r][c]?

Hint 4
For the cell (r, c), is there a relation between the number of pyramids for which it serves as the apex and dp[r][c]? How does it help in calculating the answer?

*/

package main

func main() {
	assert(count([][]int{
		{0, 1, 1, 0},
		{1, 1, 1, 1},
	}) == 2)

	assert(count([][]int{
		{1, 1, 1},
		{1, 1, 1},
	}) == 2)

	assert(count([][]int{
		{1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 0, 0, 1},
	}) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func count(p [][]int) int {
	if len(p) == 0 || len(p[0]) == 0 {
		return 0
	}

	m := len(p)
	n := len(p[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}

	r := 0
	for i := m - 1; i >= 0; i-- {
		for j := 0; j < n; j++ {
			if p[i][j] == 0 {
				f[i][j] = -1
			} else if i == m-1 || j == 0 || j == n-1 {
				f[i][j] = 0
			} else {
				f[i][j] = min(f[i+1][j-1], f[i+1][j], f[i+1][j+1]) + 1
				r += f[i][j]
			}
		}
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if p[i][j] == 0 {
				f[i][j] = -1
			} else if i == 0 || j == 0 || j == n-1 {
				f[i][j] = 0
			} else {
				f[i][j] = min(f[i-1][j-1], f[i-1][j], f[i-1][j+1]) + 1
				r += f[i][j]
			}
		}
	}
	return r
}
