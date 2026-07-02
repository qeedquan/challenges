/*

You can determine the volume of objects based on a given set of dimensions:

The volume of a sphere can be determined using a single number, the radius (r)
The volume of a cylinder can be determined using two numbers, the radius (r) and the height (h)
The volume of a box can be determined using three numbers, the length (l), width (w) and the height (h)
The volume of an irregular triangular pyramid can be determined using four numbers, the side lengths (a, b, c) and the height (h).
The challenge is to determine the volume of an object given one of the following inputs:

A single number (r) or (r, 0, 0, 0) => V = 4/3*pi*r^3
Two numbers (r, h) or (r, h, 0, 0) => V = pi*r^2*h
Three numbers (l, w, h) or (l, w, h, 0) => V = l*w*h
Four numbers (a, b, c, h) => V = (1/3)*A*h, where A is given by Heron's formula: A = 1/4*sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c))
Rules and clarifications:

The input can be both integers and/or decimals
You can assume all input dimensions will be positive
If Pi is hard coded it must be accurate up to: 3.14159.
The output must have at least 6 significant digits, except for numbers that can be accurately represented with fewer digits. You can output 3/4 as 0.75, but 4/3 must be 1.33333 (more digits are OK)
How to round inaccurate values is optional
Behaviour for invalid input is undefined
Standard rules for I/O. The input can be list or separate arguments
This is code golf, so the shortest solution in bytes win.

Test cases:

calc_vol(4)
ans =  268.082573106329

calc_vol(5.5, 2.23)
ans =  211.923986429533

calc_vol(3.5, 4, 5)
ans =  70

calc_vol(4, 13, 15, 3)
ans =  24

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(268.082573106329, 4)
	test(211.923986429533, 5.5, 2.23)
	test(70, 3.5, 4, 5)
	test(24, 4, 13, 15, 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(r float64, a ...float64) {
	v := volume(a...)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-6)
}

func volume(a ...float64) float64 {
	switch len(a) {
	case 1:
		return sphere(a[0])
	case 2:
		return cylinder(a[0], a[1])
	case 3:
		return box(a[0], a[1], a[2])
	case 4:
		return pyramid(a[0], a[1], a[2], a[3])
	}
	return -1
}

func sphere(r float64) float64 {
	return (4 * math.Pi / 3) * r * r * r
}

func cylinder(r, h float64) float64 {
	return math.Pi * r * r * h
}

func box(l, w, h float64) float64 {
	return l * w * h
}

func pyramid(a, b, c, h float64) float64 {
	A := 0.25 * math.Sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c))
	return 1.0 / 3 * A * h
}
