/*

You are given an n x n grid where we place some 1 x 1 x 1 cubes that are axis-aligned with the x, y, and z axes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of the cell (i, j).

We view the projection of these cubes onto the xy, yz, and zx planes.

A projection is like a shadow, that maps our 3-dimensional figure to a 2-dimensional plane. We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

Return the total area of all three projections.



Example 1:


Input: grid = [[1,2],[3,4]]
Output: 17
Explanation: Here are the three projections ("shadows") of the shape made with each axis-aligned plane.
Example 2:

Input: grid = [[2]]
Output: 5
Example 3:

Input: grid = [[1,0],[0,2]]
Output: 8


Constraints:

n == grid.length == grid[i].length
1 <= n <= 50
0 <= grid[i][j] <= 50

*/

package main

import "math"

func main() {
	assert(projarea([][]int{{2}}) == 5)
	assert(projarea([][]int{{1, 2}, {3, 4}}) == 17)
	assert(projarea([][]int{{1, 0}, {0, 2}}) == 8)
	assert(projarea([][]int{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}) == 14)
	assert(projarea([][]int{{2, 2, 2}, {2, 1, 2}, {2, 2, 2}}) == 21)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func projarea(a [][]int) int {
	s := 0
	for i := range a {
		r, c := math.MinInt, math.MinInt
		for j := range a[i] {
			if a[i][j] > 0 {
				s += 1
			}

			r = max(r, a[i][j])
			c = max(c, a[j][i])
		}
		s += r + c
	}
	return s
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
