/*

Determine whether the point (x,y) belongs to a rectangle with diagonal vertices (x1,y1), (x2,y2).
The sides of the rectangle are parallel to the coordinate axes.

Input
Six real numbers x, y, x1, y1, x2, y2 — the coordinates of the point and the diagonal vertices of the rectangle, respectively.
The numeric values do not exceed 100 by absolute value.

Output
Print 1 if the point belongs to the rectangle (including its border), otherwise print 0.

Examples

Input #1
1 2 3 4 0 0

Answer #1
1

*/

package main

func main() {
	assert(solve(1, 2, 3, 4, 0, 0) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x, y, x1, y1, x2, y2 int) int {
	a := abs(x1 - x2)
	b := abs(y1 - y2)
	s := 2 * a * b
	s1 := abs(x*(y2-y1) + x2*(y1-y) + x2*(y-y2))
	s2 := abs(x*(y1-y1) + x1*(y1-y) + x2*(y-y1))
	s3 := abs(x*(y1-y2) + x1*(y2-y) + x1*(y-y1))
	s4 := abs(x*(y2-y2) + x2*(y2-y) + x1*(y-y2))
	if s == s1+s2+s3+s4 {
		return 1
	}
	return 0
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
