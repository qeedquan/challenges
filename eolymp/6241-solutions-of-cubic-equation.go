/*

Hannah asked you to determine all distinct real solutions of a cubic equation of the following form:

Ax^3 + Bx^2 + Cx + D = 0

This task can be quite complicated, especially if one of the solutions is irrational.
Before you start to complain, Hannah assures you that she will only give you cubic equations with at least one integer solution.

Your task is to find all distinct real solutions of the cubic equation, given the coefficients A, B, C, and D, where A != 0.
The coefficients A, B, C, and D can be any real numbers between −2000000 and 2000000, inclusive.
The range of possible values for x is −1000000 to 1000000.

Input
The first line contains an integer N (0<N<100), the number of test cases. Each of the following N lines contains four real numbers A, B, C, and D, with A=0.

Output
For each test case, print all distinct real solutions of the cubic equation in a single line, sorted in increasing order.
Each real solution must be rounded to the nearest ten-thousandth and printed with exactly four digits after the decimal point.
If there are multiple solutions, separate them with exactly one space.

Examples

Input #1
3
1.5 -5 2 -1.5
2 -7 7 -2
2 0 0 0

Answer #1
3.0000
0.5000 1.0000 2.0000
0.0000

*/

package main

import (
	"fmt"
	"math/cmplx"
)

func main() {
	test(1.5, -5, 2, -1.5)
	test(2, -7, 7, -2)
	test(2, 0, 0, 0)
}

func test(a, b, c, d complex128) {
	r0, r1, r2 := solve(a, b, c, d)
	fmt.Printf("% .3f\n", r0)
	fmt.Printf("% .3f\n", r1)
	fmt.Printf("% .3f\n", r2)
	fmt.Println()
}

// https://en.wikipedia.org/wiki/Cubic_equation
func solve(a, b, c, d complex128) (r0, r1, r2 complex128) {
	d0 := b*b - 3*a*c
	d1 := 2*b*b*b - 9*a*b*c + 27*a*a*d
	d2 := cmplx.Sqrt(d1*d1 - 4*d0*d0*d0)

	D := d1 + d2
	if D == 0 {
		D = d1 - d2
	}
	C := cmplx.Pow(D/2, 1.0/3)

	z := (-1 + cmplx.Sqrt(-3)) / 2
	z0 := cmplx.Pow(z, 0)
	z1 := cmplx.Pow(z, 1)
	z2 := cmplx.Pow(z, 2)

	y0 := 0 + 0i
	y1 := 0 + 0i
	y2 := 0 + 0i
	if C != 0 {
		y0 = d0 / (z0 * C)
		y1 = d0 / (z1 * C)
		y2 = d0 / (z2 * C)
	}

	r0 = -(b + z0*C + y0) / (3 * a)
	r1 = -(b + z1*C + y1) / (3 * a)
	r2 = -(b + z2*C + y2) / (3 * a)
	return
}
