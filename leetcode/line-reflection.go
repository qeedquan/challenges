/*

Given n points on a 2D plane, find if there is such a line parallel to the y-axis that reflects the given points symmetrically.

In other words, answer whether or not if there exists a line that after reflecting all points over the given line, the original points' set is the same as the reflected ones.

Note that there can be repeated points.

Example 1:
Input: points = [[1,1],[-1,1]]
Output: true
Explanation: We can choose the line x = 0.

Example 2:
Input: points = [[1,1],[-1,-1]]
Output: false
Explanation: We can't choose a line.


Constraints:

n == points.length
1 <= n <= 10^4
-10^8 <= points[i][j] <= 10^8

Follow up: Could you do better than O(n^2)?

*/

package main

import (
	"math"
)

func main() {
	assert(reflected([][2]int{
		{1, 1},
		{-1, 1},
	}) == true)

	assert(reflected([][2]int{
		{1, 1},
		{-1, -1},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reflected(p [][2]int) bool {
	x0 := math.MaxInt
	x1 := math.MinInt
	m := map[[2]int]bool{}
	for _, p := range p {
		x0 = min(x0, p[0])
		x1 = max(x1, p[0])
		k := [2]int{p[0], p[1]}
		m[k] = true
	}

	s := x0 + x1
	for _, p := range p {
		k := [2]int{s - p[0], p[1]}
		if !m[k] {
			return false
		}
	}
	return true
}
