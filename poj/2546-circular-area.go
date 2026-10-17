/*

Description

Your task is to write a program, which, given two circles, calculates the area of their intersection with the accuracy of three digits after decimal point.
Input

In the single line of input file there are space-separated real numbers x1 y1 r1 x2 y2 r2. They represent center coordinates and radii of two circles.
Output

The output file must contain single real number - the area.
Sample Input

20.0 30.0 15.0 40.0 30.0 30.0
Sample Output

608.366
Source

Northeastern Europe 2000, Far-Eastern Subregion

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(20, 30, 15, 40, 30, 30, 608.366)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x1, y1, r1, x2, y2, r2, ra float64) {
	a := area(x1, y1, r1, x2, y2, r2)
	fmt.Println(a)
	assert(math.Abs(a-ra) < 1e-3)
}

func area(x1, y1, r1, x2, y2, r2 float64) float64 {
	d := distance(x1, y1, x2, y2)
	switch {
	case d >= r1+r2 || r1 <= 0 || r2 <= 0:
		return 0
	case d <= math.Abs(r1-r2):
		r := min(r1, r2)
		return math.Pi * r * r
	}
	a1 := math.Acos((r1*r1 + d*d - r2*r2) / (2 * r1 * d))
	a2 := math.Acos((r2*r2 + d*d - r1*r1) / (2 * r2 * d))
	s1 := (math.Sin(a1*2)*r1*r1 + math.Sin(a2*2)*r2*r2) / 2
	s2 := r1*r1*a1 + r2*r2*a2
	return s2 - s1
}

func distance(x1, y1, x2, y2 float64) float64 {
	return math.Hypot(x2-x1, y2-y1)
}
