/*

Construct a triangle given the lengths of its three sides.

Input
The input consists of three real numbers, representing the lengths of the sides of a triangle.
All side lengths are positive real numbers, each not exceeding 10^4, and they satisfy the triangle inequality.

Output
Output 6 real numbers: the coordinates of the vertices of any triangle with the given side lengths.
The coordinates must be output with a precision of at least 6 decimal places.

Examples

Input #1
3 4 5

Answer #1
0 0
3.0 0
0.0000000000 4.0000000000

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
	test(3, 4, 5)
	test(5, 12, 13)
	test(10, 15, 23)
	test(40, 50, 80)
	test(100.2, 110.56, 120.14)
	test(500, 600, 700)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c float64) {
	const eps = 1e-6
	p1, p2, p3 := solve(a, b, c)
	A := dist(p1, p2)
	B := dist(p2, p3)
	C := dist(p1, p3)
	fmt.Println(A, B, C)
	assert(math.Abs(A-a) < eps)
	assert(math.Abs(B-b) < eps)
	assert(math.Abs(C-c) < eps)
}

func solve(a, b, c float64) (p1, p2, p3 Point) {
	p2.x = a
	p3.x = (a*a + c*c - b*b) / (2 * a)
	p3.y = math.Sqrt(c*c - p3.x*p3.x)
	return
}

func dist(a, b Point) float64 {
	return math.Hypot(a.x-b.x, a.y-b.y)
}
