/*

Given a triangular pyramid with vertices A(x1, y1, z1) B(x2, y2, z2) C(x3, y3, z3) and S(x4, y4, z4) find the total surface area of the pyramid.

Input
The coordinates x, y, and z of the pyramid's vertices are given in four lines. All coordinates are integers with absolute values not exceeding 100.

Output
Print the total surface area of the pyramid, rounded to the nearest tenth.

Examples

Input #1
-3 0 0
0 6 0
3 0 0
0 2 5

Answer #1
69.8

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.1f\n", solve(-3, 0, 0, 0, 6, 0, 3, 0, 0, 0, 2, 5))
}

func solve(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4 float64) float64 {
	a := math.Sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2))
	b := math.Sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) + (z2-z3)*(z2-z3))
	c := math.Sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3) + (z1-z3)*(z1-z3))
	d := math.Sqrt((x1-x4)*(x1-x4) + (y1-y4)*(y1-y4) + (z1-z4)*(z1-z4))
	e := math.Sqrt((x2-x4)*(x2-x4) + (y2-y4)*(y2-y4) + (z2-z4)*(z2-z4))
	f := math.Sqrt((x3-x4)*(x3-x4) + (y3-y4)*(y3-y4) + (z3-z4)*(z3-z4))

	p1 := (a + b + c) / 2
	p2 := (a + d + e) / 2
	p3 := (e + b + f) / 2
	p4 := (c + d + f) / 2

	s1 := math.Sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - c))
	s2 := math.Sqrt(p2 * (p2 - a) * (p2 - d) * (p2 - e))
	s3 := math.Sqrt(p3 * (p3 - e) * (p3 - b) * (p3 - f))
	s4 := math.Sqrt(p4 * (p4 - d) * (p4 - f) * (p4 - c))

	return s1 + s2 + s3 + s4
}
