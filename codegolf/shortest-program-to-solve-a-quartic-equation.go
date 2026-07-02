/*

Write the shortest program to solve a quartic equation.

A quartic equation is a polynomial equation of the form:

ax^4 + bx^3 + cx^2 + dx + e=0

A solution for x is a number such that the above evaluates to 0.

Rules

The program must take in the 5 floating point coefficients of the equation ax^4 + bx^3 + cx^2 + dx + e as "a b c d e" separated by spaces.
It must then output a single real solution. If there exist no real solutions then it outputs an "n".
No bonus for extra solutions.
No use of CAS (Computer algebra systems). This includes symbolic manipulation properties of Mathematica and related software.
No connecting to external libraries, web calculators etc...
You may use formulas or your own manipulation
Native math libraries that do not solve equations may be used, eg. .NET: System.Math
You may deduct 50 from your char count if recursion is a main technique used.
As long as there is no difference with the answer obtained algebraically, numerical approximation is welcome however adds 25 chars to your solution. This really relies on the accuracy of the floating-point numbers. (Which should be 64 bit).
The winner will be picked in 1 week. (26/02/2014)

*/

package main

import (
	"fmt"
	"math"
	"math/cmplx"
)

func main() {
	test(1, 2, 3, 4, 5)
	test(1, 0, 6, -60, 36)
	test(3, 4, 5, 629, 12)
	test(1, 0, 1, 0, 0)
	test(1, 0, -1, 0, 0)
	test(1, 0, -1, 0, 0.25)
	test(54, 254, 223, 45, 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c, d, e complex128) {
	const eps = 1e-8

	r := quartic(a, b, c, d, e)
	fmt.Println(r)
	for _, x := range r {
		z := eval(x, a, b, c, d, e)
		assert(math.Abs(real(z)) < eps)
		assert(math.Abs(imag(z)) < eps)
	}
}

func eval(x, a, b, c, d, e complex128) complex128 {
	return a*x*x*x*x + b*x*x*x + c*x*x + d*x + e
}

/*

https://en.wikipedia.org/wiki/Quartic_equation#Ferrari's_solution
https://proofwiki.org/wiki/Ferrari's_Method

*/

func quartic(a, b, c, d, e complex128) (r [4]complex128) {
	A := -(3*b*b)/(8*a*a) + c/a
	B := (b*b*b)/(8*a*a*a) - (b*c)/(2*a*a) + d/a
	C := -(3*b*b*b*b)/(256*a*a*a*a) + (c*b*b)/(16*a*a*a) - (b*d)/(4*a*a) + e/a
	if B == 0 {
		D := -b / (2 * a)
		T := cmplx.Sqrt(A*A - 4*C)
		S0 := cmplx.Sqrt((-A + T) / 2)
		S1 := cmplx.Sqrt((-A - T) / 2)
		r[0] = D + S0
		r[1] = D - S0
		r[2] = D + S1
		r[3] = D - S1
		return
	}

	P := -(A*A)/12 - C
	Q := -(A*A*A)/108 + (A*C)/3 - (B*B)/8
	R := -(Q / 2) + cmplx.Sqrt((Q*Q)/4+(P*P*P)/27)
	U := cmplx.Pow(R, 1.0/3)
	Y := -(5 * A) / 6
	if U == 0 {
		Y += -cmplx.Pow(Q, 1.0/3)
	} else {
		Y += U - P/(3*U)
	}
	W := cmplx.Sqrt(A + 2*Y)

	D := -b / (4 * a)
	S := (2 * B) / W
	T0 := cmplx.Sqrt(-(3*A + 2*Y + S))
	T1 := cmplx.Sqrt(-(3*A + 2*Y - S))
	r[0] = D + (W+T0)/2
	r[1] = D + (W-T0)/2
	r[2] = D + (-W+T1)/2
	r[3] = D + (-W-T1)/2

	return
}
