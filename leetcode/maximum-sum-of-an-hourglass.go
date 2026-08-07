/*

You are given an m x n integer matrix grid.

We define an hourglass as a part of the matrix with the following form:

Return the maximum sum of the elements of an hourglass.

Note that an hourglass cannot be rotated and must be entirely contained within the matrix.

Example 1:
https://assets.leetcode.com/uploads/2022/08/21/img.jpg
Input: grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
Output: 30
Explanation: The cells shown above represent the hourglass with the maximum sum: 6 + 2 + 1 + 2 + 9 + 2 + 8 = 30.

Example 2:
https://assets.leetcode.com/uploads/2022/08/21/2.jpg
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 35
Explanation: There is only one hourglass in the matrix, with the sum: 1 + 2 + 3 + 5 + 7 + 8 + 9 = 35.

Constraints:

m == grid.length
n == grid[i].length
3 <= m, n <= 150
0 <= grid[i][j] <= 10^6

Hint 1
Each 3x3 submatrix has exactly one hourglass.

Hint 2
Find the sum of each hourglass in the matrix and return the largest of these values.

*/

package main

import (
	"math"
)

func main() {
	assert(maxsum([][]int{{6, 2, 1, 3}, {4, 2, 1, 5}, {9, 2, 8, 7}, {4, 1, 2, 9}}) == 30)
	assert(maxsum([][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) == 35)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxsum(m [][]int) int {
	if len(m) < 3 || len(m[0]) < 3 {
		return 0
	}

	r := math.MinInt
	for i := range len(m) - 2 {
		for j := range len(m[0]) - 2 {
			r = max(r, count(m, i, j))
		}
	}
	return r
}

func count(m [][]int, i, j int) int {
	return m[i][j] + m[i][j+1] + m[i][j+2] + m[i+1][j+1] + m[i+2][j] + m[i+2][j+1] + m[i+2][j+2]
}
