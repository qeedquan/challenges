/*

You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 10^9 + 7.

Example 1:

Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]

Output: 3

Explanation:
https://assets.leetcode.com/uploads/2025/05/01/desmos-graph-6.png

There are three distinct ways to pick four points that form a horizontal trapezoid:

Using points [1,0], [2,0], [3,2], and [2,2].
Using points [2,0], [3,0], [3,2], and [2,2].
Using points [1,0], [3,0], [3,2], and [2,2].

Example 2:

Input: points = [[0,0],[1,0],[0,1],[2,1]]

Output: 1

Explanation:

https://assets.leetcode.com/uploads/2025/04/29/desmos-graph-5.png

There is only one horizontal trapezoid that can be formed.

Constraints:

4 <= points.length <= 10^5
-10^8 <= xi, yi <= 10^8
All points are pairwise distinct.

Hint 1
For a line parallel to the x‑axis, all its points must share the same y‑coordinate.

Hint 2
Group the points by their y‑coordinate.

Hint 3
Choose two distinct groups (two horizontal lines), and from each group select two points to form a trapezoid.

*/

package main

func main() {
	assert(trapezoids([][2]int{{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}}) == 3)
	assert(trapezoids([][2]int{{0, 0}, {1, 0}, {0, 1}, {2, 1}}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func trapezoids(p [][2]int) int {
	const mod = 1e9 + 7

	c := make(map[int]int)
	for _, p := range p {
		c[p[1]] += 1
	}

	r, s := 0, 0
	for _, v := range c {
		t := v * (v - 1) / 2
		r = (r + s*t) % mod
		s += t
	}
	return r
}
