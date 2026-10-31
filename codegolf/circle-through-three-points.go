/*

Given the Cartesian coordinates of three points on a plane, find the equation of the circle through them all.
The three points will not be on a straight line.

Each line of input to your program will contain the x and y coordinates of three points, in the order A(x),A(y),B(x),B(y),C(x),C(y).
These coordinates will be real numbers less than 1,000,000 separated from each other by space.

The solution is to be printed as an equation of the form (x-h)^2 + (y-k)^2 = r^2.
Values for h, k, r are to be printed with three digits after the decimal point.
Plus and minus signs in the equations should be changed as needed to avoid multiple signs before a number.

Sample Inputs

7.0 -5.0 -1.0 1.0 0.0 -6.0
1.0 7.0 8.0 6.0 7.0 -2.0

Sample Outputs

(x - 3.000)^2 + (y + 2.000)^2 = 5.000^2
(x - 3.921)^2 + (y - 2.447)^2 = 5.409^2

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(7, -5, -1, 1, 0, -6, 3, -2, 5)
	test(1, 7, 8, 6, 7, -2, 3.921, 2.447, 5.409)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x1, y1, x2, y2, x3, y3, rx, ry, rr float64) {
	const eps = 1e-3
	cx, cy, r := cf3p(x1, y1, x2, y2, x3, y3)
	fmt.Println(cx, cy, r)
	assert(math.Abs(cx-rx) < eps)
	assert(math.Abs(cy-ry) < eps)
	assert(math.Abs(r-rr) < eps)
}

// http://ambrnet.com/TrigoCalc/Circle3D.htm
func cf3p(x1, y1, x2, y2, x3, y3 float64) (cx, cy, r float64) {
	xy1 := x1*x1 + y1*y1
	xy2 := x2*x2 + y2*y2
	xy3 := x3*x3 + y3*y3

	A := det3x3([3][3]float64{
		{x1, y1, 1},
		{x2, y2, 1},
		{x3, y3, 1},
	})

	B := -det3x3([3][3]float64{
		{xy1, y1, 1},
		{xy2, y2, 1},
		{xy3, y3, 1},
	})

	C := det3x3([3][3]float64{
		{xy1, x1, 1},
		{xy2, x2, 1},
		{xy3, x3, 1},
	})

	D := -det3x3([3][3]float64{
		{xy1, x1, y1},
		{xy2, x2, y2},
		{xy3, x3, y3},
	})

	cx = -B / (2 * A)
	cy = -C / (2 * A)
	r = math.Sqrt((B*B + C*C - 4*A*D) / (4 * A * A))
	return
}

func det3x3(m [3][3]float64) float64 {
	c00 := m[1][1]*m[2][2] - m[1][2]*m[2][1]
	c01 := m[1][2]*m[2][0] - m[1][0]*m[2][2]
	c02 := m[1][0]*m[2][1] - m[1][1]*m[2][0]
	return m[0][0]*c00 + m[0][1]*c01 + m[0][2]*c02
}
