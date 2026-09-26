/*

Given the coordinates of the vertices of a triangle and a point, determine the position of the point relative to the triangle.

Output In if the point is inside the triangle, Edge if the point lies on one of the triangle's sides,
Vertex if the point coincides with one of the triangle's vertices, and Out if the point is outside the triangle.

Input
The input consists of four lines, each containing 2 integers, not exceeding 10000000 in absolute value.

The first three lines provide the coordinates of the triangle's vertices: A(X1,Y1), B(X2,Y2), C(X3,Y3).
The fourth line gives the coordinates of the point O(X0,Y0).

Output
Output the position of the point relative to the triangle.

Examples

Input #1
-2 -2
3 1
0 1
0 0

Answer #1
In

*/

package main

func main() {
	assert(solve(-2, -2, 3, 1, 0, 1, 0, 0) == "In")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x1, y1, x2, y2, x3, y3, x, y int) string {
	if (x == x1 && y == y1) || (x == x2 && y == y2) || (x == x3 && y == y3) {
		return "Vertex"
	}

	s := abs(x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3)
	s1 := abs(x1*y + x*y2 + x2*y1 - x*y1 - y*x2 - x1*y2)
	s2 := abs(x*y2 + x2*y3 + x3*y - x2*y - x3*y2 - x*y3)
	s3 := abs(x1*y + x*y3 + x3*y1 - x*y1 - x3*y - y3*x1)

	if (s1 == 0 || s2 == 0 || s3 == 0) && s == s1+s2+s3 {
		return "Edge"
	}
	if s == s1+s2+s3 {
		return "In"
	}
	return "Out"
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
