/*

Introduction
Imagine you are on a two dimensional cartesian plane and want to determine your position on it. You know 3 points on that plane and your distance to each of them. While it is always possible to calculate your position from that, doing that in your head is pretty hard. So you decide to write a program for that.

The Challenge
Given 3 points and your distance to them, output the cordinates of your position.

Input and output may be in any convenient format, including using complex instead of real numbers. Please clarify in your answer which format you use.
You will always get exactly 3 distinct points with their distance to you.
The coordinates and distances will be floats with arbitrary precision. Your output has to be correct to 3 decimal places. Rounding is up to you. Please clarify in your answer.
You may assume that the three points are not collinear, so there will be always an unique solution.
You are not allowed to bruteforce the solution.
You may not use any builtins that trivialize this particular problem. Builtins for vector norms, etc. are allowed though.

Hint to get started:

Think about a circle around each of those 3 points with their distance to you as radius.

Rules
Function or full program allowed.
Default rules for input/output.
Standard loopholes apply.
This is code-golf, so lowest byte-count wins. Tiebreaker is earlier submission.

Test cases
Input format for one point here is [[x,y],d] with x and y being the coordinates and d being the distance to this point. The 3 of those points are arranged in a list. Output will be x and then y in a list.

[[[1, 2], 1.414], [[1, 1], 2.236], [[2, 2], 1.0]] -> [2, 3]
[[[24.234, -13.902], 31.46], [[12.3242, 234.12], 229.953], [[23.983, 0.321], 25.572]] -> [-1.234, 4.567]
[[[973.23, -123.221], 1398.016], [[-12.123, -98.001], 990.537], [[-176.92, 0], 912.087]] -> [12.345, 892.234]

You can generate additional test cases with this Pyth program. Location goes on the first line of the input and the 3 points are on the following 3 lines.

Happy Coding!

*/

package main

import (
	"fmt"
	"math"
)

type Location struct {
	x, y, r float64
}

func main() {
	test(
		Location{1, 2, 1.414},
		Location{1, 1, 2.236},
		Location{2, 2, 1.0},
		Location{2, 3, 0},
	)

	test(
		Location{24.234, -13.902, 31.46},
		Location{12.3242, 234.12, 229.953},
		Location{23.983, 0.321, 25.572},
		Location{-1.234, 4.567, 0},
	)

	test(
		Location{973.23, -123.221, 1398.016},
		Location{-12.123, -98.001, 990.537},
		Location{-176.92, 0, 912.087},
		Location{12.345, 892.234, 0},
	)

	test(
		Location{0, 0, math.Sqrt(2)},
		Location{0, 1, 1},
		Location{1, 0, 1},
		Location{1, 1, 0},
	)

	test(
		Location{0, 0, 4},
		Location{3, 0, 5},
		Location{3, 4, 3},
		Location{0, 4, 0},
	)

	test(
		Location{-1, 0, 9.055385138137417},
		Location{5, 6, 5.830951894845301},
		Location{11, 3, 3.605551275463989},
		Location{8, 1, 0},
	)

	test(
		Location{-100, -100, 145.69145479402695},
		Location{1000, 20, 999.1126062661806},
		Location{0, 0, 5.0990195135927845},
		Location{1, 5, 0},
	)

	test(
		Location{3, 2, 6.324555320336759},
		Location{-5, -3, 6.082762530298219},
		Location{-2, -1, 4.242640687119285},
		Location{1, -4, 0},
	)

	test(
		Location{-3, 2, 8.246211251235321},
		Location{0, -1, 5.0990195135927845},
		Location{1, 5, 6.4031242374328485},
		Location{5, 0, 0},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c, r Location) {
	const eps = 1e-2
	p := trilaterate(a, b, c)
	fmt.Println(p.x, p.y)
	assert(math.Abs(p.x-r.x) < eps)
	assert(math.Abs(p.y-r.y) < eps)
}

/*

https://math.stackexchange.com/questions/884807/find-x-location-using-3-known-x-y-location-using-trilateration

Use the distance equation. If your unknown point is (x,y), your known points are (xi,yi) which are distances ri from your unknown point, then you get three equations:

(x - x1)^2 + (y - y1)^2 = r1^2
(x - x2)^2 + (y - y2)^2 = r2^2
(x - x3)^2 + (y - y3)^2 = r3^2

We can expand out the squares in each one:

x^2 - 2*x1*x + x1^2 + y^2 - 2*y1*y + y1^2 = r1^2
x^2 - 2*x2*x + x2^2 + y^2 - 2*y2*y + y2^2 = r2^2
x^2 - 2*x3*x + x3^2 + y^2 - 2*y3*y + y3^2 = r3^2

If we subtract the second equation from the first, we get

(-2*x1 + 2*x2)*x + (-2*y1 + 2*y2)*y = r1^2 - r2^2 - x1^2 + x2^2 - y1^2 + y2^2

Likewise, subtracting the third equation from the second,

(-2*x2 + 2*x3)*x + (-2*y2 + 2*y3)*y = r2^2 - r3^2 - x2^2 + x3^2 - y2^2 + y3^2

This is a system of two equations in two unknowns:

Ax+By=C
Dx+Ey=F

which has the solution:

x=(CE-FB)/(EA−BD)
y=(CD-AF)/(BD−AE)

*/

func trilaterate(a, b, c Location) Location {
	x1, x2, x3 := a.x, b.x, c.x
	y1, y2, y3 := a.y, b.y, c.y
	r1, r2, r3 := a.r, b.r, c.r
	A := -2*x1 + 2*x2
	B := -2*y1 + 2*y2
	C := r1*r1 - r2*r2 - x1*x1 + x2*x2 - y1*y1 + y2*y2
	D := -2*x2 + 2*x3
	E := -2*y2 + 2*y3
	F := r2*r2 - r3*r3 - x2*x2 + x3*x3 - y2*y2 + y3*y3
	return Location{
		x: (C*E - F*B) / (E*A - B*D),
		y: (C*D - A*F) / (B*D - A*E),
	}
}
