/*

Develop a program to solve the biquadratic equation:

ax^4 + bx^2 + c = 0

Input
You will receive a single line containing three numbers separated by spaces, representing the coefficients of the biquadratic equation: a, b, and c.
The absolute values of these coefficients do not exceed 100.

Output
Output a single line in one of the following formats:

If there are no roots, print "No roots" (without quotes).
If there is one root, print "One root:" (without quotes) followed by the root (separated by a space).
If there are two roots, print "Two roots:" (without quotes) followed by the smaller root and then the larger root (separated by spaces).
If there are three roots, print "Three roots:" (without quotes) followed by the three roots in ascending order (separated by spaces).
If there are four roots, print "Four roots:" (without quotes) followed by the roots in ascending order (separated by spaces).
If there are infinitely many roots, print "Many roots" (without quotes).

All roots must be printed with a precision of 10^-3.

Examples
Input #1
1 -10 9

Answer #1
Four roots: -3.000 -1.000 1.000 3.000

*/

package main

import (
	"fmt"
	"math"
	"math/cmplx"
)

func main() {
	test(1, -10, 9)
	test(-3, -5, 230)
	test(20, 35, 109)
	test(100, 200, 3000)
	test(-56, -5425, -30)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c complex128) {
	const eps = 1e-6

	x0, x1, x2, x3 := solve(a, b, c)

	z0 := a*cmplx.Pow(x0, 4) + b*cmplx.Pow(x0, 2) + c
	z1 := a*cmplx.Pow(x1, 4) + b*cmplx.Pow(x1, 2) + c
	z2 := a*cmplx.Pow(x2, 4) + b*cmplx.Pow(x2, 2) + c
	z3 := a*cmplx.Pow(x3, 4) + b*cmplx.Pow(x3, 2) + c

	fmt.Println(x0, x1, x2, x3)

	assert(math.Abs(real(z0)) < eps)
	assert(math.Abs(imag(z0)) < eps)

	assert(math.Abs(real(z1)) < eps)
	assert(math.Abs(imag(z1)) < eps)

	assert(math.Abs(real(z2)) < eps)
	assert(math.Abs(imag(z2)) < eps)

	assert(math.Abs(real(z3)) < eps)
	assert(math.Abs(imag(z3)) < eps)
}

func solve(a, b, c complex128) (r0, r1, r2, r3 complex128) {
	d := b*b - 4*a*c
	s := cmplx.Sqrt(d)
	z0 := (-b + s) / (2 * a)
	z1 := (-b - s) / (2 * a)
	r0 = cmplx.Sqrt(z0)
	r1 = cmplx.Sqrt(z1)
	r2 = -r0
	r3 = -r1
	return
}
