/*

Construct a triangle given two sides and included angle.

Input
Contains three real numbers - the lengths of two sides of the triangle and the angle between them in degrees.
The lengths of the sides are positive numbers not exceeding 10^-4, the angle is a positive number less than 180.

Output
Print 6 real numbers - the coordinates of the vertices of any triangle corresponding to the given input data with an accuracy of at least 6 decimal digits.

Examples
Input #1
10 5 60

Answer #1
0 0
10.0 0
2.5000000000 4.3301270189 (wrong, should be: 7.5 4.3301270189)

*/

package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func main() {
	test(10, 5, 60)
	test(3, 4, 90)
	test(5, 12, 90)
	test(45, 60, 70)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, t float64) {
	const eps = 1e-6
	p1, p2, p3 := solve(a, b, t)
	A := dist(p1, p2)
	B := dist(p2, p3)
	C := dist(p1, p3)
	T := ang(C, A, B)

	fmt.Println(p1)
	fmt.Println(p2)
	fmt.Println(p3)
	fmt.Println()

	assert(math.Abs(A-a) < eps)
	assert(math.Abs(B-b) < eps)
	assert(math.Abs(T-t) < eps)
}

func solve(a, b, t float64) (p1, p2, p3 Point) {
	c := math.Sqrt(a*a + b*b - 2*a*b*math.Cos(deg2rad(t)))
	p2.x = a
	p3.x = (a*a + c*c - b*b) / (2 * a)
	p3.y = math.Sqrt(c*c - p3.x*p3.x)
	return
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}

func rad2deg(x float64) float64 {
	return x * 180 / math.Pi
}

func dist(a, b Point) float64 {
	return math.Hypot(a.x-b.x, a.y-b.y)
}

func ang(a, b, c float64) float64 {
	return rad2deg(math.Acos((b*b + c*c - a*a) / (2 * b * c)))
}
