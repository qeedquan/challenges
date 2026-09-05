/*

A quadrilateral is given on the plane by the coordinates of its vertices in order. Determine the number of right angles in the quadrilateral.

Input
The input consists of the coordinates of the four vertices of the quadrilateral in order. Each coordinate is an integer with an absolute value not greater than 100.

Output
Print a single integer — the number of right angles in the quadrilateral.

Input #1
-1 0 -1 4 2 4 4 1

Answer #1
1

*/

package main

func main() {
	assert(solve(-1, 0, -1, 4, 2, 4, 4, 1) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x1, y1, x2, y2, x3, y3, x4, y4 int) int {
	a := dist2(x1, y1, x2, y2)
	b := dist2(x2, y2, x3, y3)
	c := dist2(x3, y3, x4, y4)
	d := dist2(x1, y1, x4, y4)
	e := dist2(x1, y1, x3, y3)
	f := dist2(x2, y2, x4, y4)

	x := a + d
	y := a + b
	z := b + c
	w := c + d
	m := e
	n := f

	r := bool2(x == n)
	r += bool2(y == m)
	r += bool2(z == n)
	r += bool2(w == m)
	return r
}

func dist2(x1, y1, x2, y2 int) int {
	dx := x2 - x1
	dy := y2 - y1
	return dx*dx + dy*dy
}

func bool2(x bool) int {
	if x {
		return 1
	}
	return 0
}
