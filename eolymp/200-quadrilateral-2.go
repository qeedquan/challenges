/*

Four points are given on the plane. Determine whether they form a square.

Input
Four lines follow, each containing two integers — the coordinates of the given points. The coordinates are integers, and their absolute values do not exceed 1000.

Output
If the given points are the vertices of a square, print YES. Otherwise, print NO.

Examples

Input #1
0 0
1 1
0 1
1 0

Answer #1
YES

*/

package main

func main() {
	assert(solve(0, 0, 1, 1, 0, 1, 1, 0) == "YES")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x1, y1, x2, y2, x3, y3, x4, y4 int) string {
	a := (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)
	b := (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2)
	c := (x4-x3)*(x4-x3) + (y4-y3)*(y4-y3)
	d := (x1-x4)*(x1-x4) + (y1-y4)*(y1-y4)
	e := (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)
	f := (x2-x4)*(x2-x4) + (y2-y4)*(y2-y4)

	if a == b && b == c && c == d && e == f && a != 0 && e != 0 && a != e {
		return "YES"
	}
	if a == f && f == c && c == e && b == d && a != 0 && b != 0 && a != b {
		return "YES"
	}
	if e == b && b == f && f == d && a == c && e != 0 && a != 0 && e != a {
		return "YES"
	}
	return "NO"
}
