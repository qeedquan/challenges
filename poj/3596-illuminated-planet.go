/*

Description

A space probe is on a mission to observe a planetary system. It is instructed to shoot images of a planet, which orbits a star, using its optical camera. To ensure image quality, it must take the images only when a positive portion of the planet’s surface illuminated by the star is visible.

Given the positions and radii of the planet and the star, and the position of the space probe, determine whether images can be taken in this setting. You do not have to consider the situation that the planet is occulted by the star.

Input

The input contains a single test case. The first line contains four numbers (x⊕, y⊕, z⊕) and r⊕, the Cartesian coordinates of the planet and its radius. The second line contains four numbers (x⊙, y⊙, z⊙) and r⊙, the Cartesian coordinates of the star and its radius. The third line contains three numbers (x, y, z), the Cartesian coordinates of the space probe. The input is physically consistent.

Output

If images can be taken, print “Yes”; otherwise, print “No”.

Sample Input

0 0 0 6.371e3
1.027e8 4.400e8 7.548e8 6.96e5
3.489e9 -1.036e10 -5.249e9

Sample Output

Yes

Hint

The sample uses the real physical setting of Earth, the Sun and the Voyager 2 space probe. Voyager 2 is located far south to the ecliptic and thus always has the illuminated side of Earth within its sight.

Source

PKU Campus 2008 (POJ Founder Monthly Contest – 2008.05.10), frkstyc

*/

package main

import (
	"math"
)

func main() {
	assert(illuminated(
		0, 0, 0, 6.371e3,
		1.027e8, 4.400e8, 7.548e8, 6.96e5,
		3.489e9, -1.036e10, -5.249e9,
	) == "Yes")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func illuminated(x1, y1, z1, r1, x2, y2, z2, r2, x3, y3, z3 float64) string {
	const eps = 1e-12

	a := length(x1-x2, y1-y2, z1-z2)
	b := length(x3-x2, y3-y2, z3-z2)
	c := length(x1-x3, y1-y3, z1-z3)

	x, y := position(a, b, c)

	A := alpha(a, r1, r2)
	B := beta(x, y, r1, c)

	if c <= r1+eps {
		return "No"
	}
	if A > B+eps {
		return "Yes"
	}
	return "No"
}

func length(x, y, z float64) float64 {
	return math.Sqrt(x*x + y*y + z*z)
}

func position(a, b, c float64) (float64, float64) {
	p := (a + b + c) / 2
	s := math.Sqrt(p * (p - a) * (p - b) * (p - c))
	h := (2 * s) / a
	l := math.Sqrt(c*c - h*h)
	x, y := -l, h
	if a*a+c*c-b*b > 0 {
		x = l
	}
	return x, y
}

func alpha(a, r, R float64) float64 {
	if R > r {
		return math.Pi/2 + math.Asin((R-r)/a)
	}
	return math.Acos((r - R) / a)
}

func beta(x, y, r, c float64) float64 {
	return math.Atan2(y, x) - math.Acos(r/c)
}
