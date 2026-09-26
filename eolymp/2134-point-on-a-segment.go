/*

Determine whether a given point lies on a given segment.

Input
Six integers are given: the coordinates of the point, and the coordinates of the endpoints of the segment. All integers do not exceed 10000 in absolute value.

Output
Print YES if the point lies on the segment, and NO otherwise.

Examples
Input #1
3 3 1 2 5 4

Answer #1
YES

Input #2
3 3 1 2 5 3

Answer #2
NO

*/

package main

import "math"

func main() {
	assert(solve(3, 3, 1, 2, 5, 4) == "YES")
	assert(solve(3, 3, 1, 2, 5, 3) == "NO")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(p1, p2, x1, y1, x2, y2 float64) string {
	d := math.Sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
	d1 := math.Sqrt((p1-x1)*(p1-x1) + (p2-y1)*(p2-y1))
	d2 := math.Sqrt((x2-p1)*(x2-p1) + (y2-p2)*(y2-p2))
	if d1+d2 > d {
		return "NO"
	}
	return "YES"
}
