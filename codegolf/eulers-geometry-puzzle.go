/*

Today (or tomorrow, depending on your timezone, by the time of posting) is the birthday of the great mathematician and physicist Leonhard Euler. To celebrate his birthday, this challenge is about one of his theorems in geometry.

For a triangle, we define its incircle to be the largest circle inside the triangle and its circumcircle to be the circle that passes through all of the traingle's vertices.

Consider a triangle in a plane, we plot the center of its incircle I (sometimes called incenter) and the center of its circumcircle O (sometimes called circumcenter).
Let r be the radius of the incircle, R be the radius of circumcircle, d be the distance between I and O. Euler's theorem in geometry states that d^2=R(R-2r).

The challenge
In the spirit of this theorem, your task, is for a triangle given by the lengths of its three sides, output d (the distance between incenter I and circumcenter O described above).

Your code needs to take only the length of the three sides of triangle and output d. Inputs and outputs can be in any reasonable format.
The absolute error or relative error from your output and correct answer must be no greater than 10^-2.
It's guaranteed that the three side lengths are positive integers and can form a non-degenerate triangle.
Standard loopholes are forbidden.
Since this is a code-golf, the shortest code in bytes wins!

Examples
In the samples, the outputs are rounded to 3 decimal places. You, however, are free to round them to more decimal places.

[a,b,c]       -> d
[2,3,4]       -> 1.265
[3,4,5]       -> 1.118
[3,5,7]       -> 3.055
[7,9,10]      -> 1.507
[8,8,8]       -> 0.000
[123,234,345] -> 309.109

List of sample inputs:

[[2,3,4],[3,4,5],[3,5,7],[7,9,10],[8,8,8],[123,234,345]]

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(2, 3, 4, 1.265)
	test(3, 4, 5, 1.118)
	test(3, 5, 7, 3.055)
	test(7, 9, 10, 1.507)
	test(8, 8, 8, 0)
	test(123, 234, 345, 309.109)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c, r float64) {
	p := distance(a, b, c)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-3)
}

/*

@Arnauld

How?
This is derived from:

The semiperimeter s of the triangle:

s = (a+b+c)/2

The circumradius R of the triangle:

R = a*b*c / (4*sqrt(s*(s-a)*(s-b)*(s-c)))

The product of the inradius r and the circumradius:

r*R = a*b*c / (2*(a+b+c)) = a*b*c/(4*s)

Euler's theorem:
d = sqrt(R*(R - 2*r)) = sqrt(R*R - 2*r*R) = sqrt(R*R - a*b*c/(2*s))

*/

func distance(a, b, c float64) float64 {
	s := semiperimeter(a, b, c)
	R := circumradius(a, b, c, s)
	return math.Sqrt(R*R - (a*b*c)/(2*s))
}

func semiperimeter(a, b, c float64) float64 {
	return (a + b + c) / 2
}

func circumradius(a, b, c, s float64) float64 {
	return a * b * c / (4 * math.Sqrt(s*(s-a)*(s-b)*(s-c)))
}
