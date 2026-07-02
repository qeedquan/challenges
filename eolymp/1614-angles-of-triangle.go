/*

Given a triangle, determine the value of its largest angle.

Input
The coordinates of the three vertices of the triangle are given (first the coordinates of the first vertex, then the second, then the third).
Each coordinate is an integer, and the absolute value of any coordinate does not exceed 10^4.

Output
Print the value of the largest angle of the triangle in degrees, with 6 digits after the decimal point.

Examples

Input #1
0 0
3 0
0 4

Answer #1
90.000000

Input #4
-1 1
-10000 -10000
10000 10000

Answer #4
179.988541

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(0, 0, 3, 0, 0, 4))
	fmt.Println(solve(-1, 1, -10000, -10000, 10000, 10000))
}

// https://en.wikipedia.org/wiki/Law_of_cosines
func solve(x1, y1, x2, y2, x3, y3 float64) float64 {
	a := math.Hypot(x2-x1, y2-y1)
	b := math.Hypot(x3-x2, y3-y2)
	c := math.Hypot(x3-x1, y3-y1)
	A := math.Acos((b*b + c*c - a*a) / (2 * b * c))
	B := math.Acos((a*a + c*c - b*b) / (2 * a * c))
	C := math.Acos((a*a + b*b - c*c) / (2 * a * b))
	return rad2deg(max(A, B, C))
}

func rad2deg(x float64) float64 {
	return x * 180 / math.Pi
}
