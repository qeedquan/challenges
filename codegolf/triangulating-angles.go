/*

Prompt:

You are given two sets of XY coordinates along with two angles (all are floats): X1 Y1 A1 X2 Y2 A2. The angles are relative to world coordinates: 0 being straight up or north and going clockwise.

Your program or function has to return a set of two floats of the XY coordinates the two angles cross at.

Example:

https://i.stack.imgur.com/KOIKr.png

In this case, the resulting point is between the two inputted points. For the case 100 500 50 300 600 80 (using degrees), the correct answer is 198 582. Online representation here

Other examples of edge cases: 1 1 45 4 4 45 returns NULL 1 4 45 2 4 45 returns NULL https://i.stack.imgur.com/vlmQO.jpg

Rules:

Angles can be in radians or in degrees
The program should have a separate answer if there is not a valid answer: if the two lines are parallel (zero solutions) or the same line (infinitely many solutions)
The value returned can be represented in any form: 198;582, 198 582 and 198_582 are all valid
The answer can be rounded to a full number
This is code-golf

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(100, 500, 50, 300, 600, 80, 198, 582)
	test(1, 1, 45, 4, 4, 45, 0, 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y, a, X, Y, A, rx, ry float64) {
	const eps = 1
	px, py := angle(x, y, deg2rad(a), X, Y, deg2rad(A))
	fmt.Println(px, py)
	assert(math.Abs(px-rx) < eps)
	assert(math.Abs(py-ry) < eps)
}

func angle(x, y, a, X, Y, A float64) (float64, float64) {
	M := math.Tan(A)
	m := math.Tan(a)
	if a == A {
		return 0, 0
	}

	n := (M*Y - m*y - X + x) / (M - m)
	return (n-Y)*M + X, n
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
