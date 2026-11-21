/*

Find the coordinates of the center of inscribed circle for the given triangle.

Input
The coordinates of the three triangle vertices (first the coordinates of the first vertex, then the second, then the third).
Coordinates are a pair of integers not exceeding 10^4 by absolute value.

Output
Print two numbers - the coordinates of the center of inscribed circle with at least 6 digits after the decimal point.

Examples
Input #1
0 0
3 0
0 4

Answer #1
1.0 1.0

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(0, 0, 3, 0, 0, 4))
}

// https://byjus.com/maths/incenter-of-a-triangle/
func solve(x1, y1, x2, y2, x3, y3 float64) (float64, float64) {
	a := dist(x2, y2, x3, y3)
	b := dist(x1, y1, x3, y3)
	c := dist(x1, y1, x2, y2)
	d := a + b + c
	x := a*x1 + b*x2 + c*x3
	y := a*y1 + b*y2 + c*y3
	return x / d, y / d
}

func dist(x1, y1, x2, y2 float64) float64 {
	dx := x1 - x2
	dy := y1 - y2
	return math.Hypot(dx, dy)
}
