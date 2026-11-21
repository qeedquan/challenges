/*

The area between the vertex of the parabola and x-axis

1-) Warning
If you don't know about the following topics, you will have problems in this kata.

Quadratic equations
Parabola
Integral

2-) Explanation
I will give you 3 values as input in the kata. These are a , b , c. The value of a will never be given as 0. These values are the coefficients of the following equation.


f(x)=ax^2+bx+c

The graph of this equation is a parabola.

This kata asks you for the area between the vertex of the parabola and x-axis.

Don't forget area isn't negative.

3-) Details
If the equation hasn't real roots, you should return 0. Because there isn't any area.

If the equation has 2 equal real roots, you should return 0. Because 0 is the real area.

If the equation has 2 unequal real root, you should return the real area.

For example

The real area: 35.265720  --->  return 35.265720

Given values is definitely between -4000 with 4000. Because the result should be under the DOUBLE_MAX value.

I set up the tolerance to 10-6 for the decimal errors.

Letter for you

If you like this kata, don't forget to vote please. Take easy...

-founded by theprotagonist

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(3, 10, 20, 0)
	test(1, -10, 25, 0)
	test(3, -42, 144, 4)
	test(1, -10, 21, 10.666667)
	test(12.225867, 54.249312, -293.764, 2539.217339)
	test(256, 2023, -3879, 58243.180912)
	test(4000, 4000, -4000, 7453.559925)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c, r float64) {
	v := area(a, b, c)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-6)
}

func area(a, b, c float64) float64 {
	d := b*b - 4*a*c
	if d <= 0 {
		return 0
	}

	s := math.Sqrt(d)
	x1 := (-b - s) / (2 * a)
	x2 := (-b + s) / (2 * a)
	if x1 > x2 {
		x1, x2 = x2, x1
	}

	k1 := a * (x2*x2*x2 - x1*x1*x1) / 3
	k2 := b * (x2*x2 - x1*x1) / 2
	k3 := c * (x2 - x1)

	return math.Abs(k1 + k2 + k3)
}
