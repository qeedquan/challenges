/*

This is somewhat similar to The centers of a triangle, but with a different point. The Fermat Point is the point P in triangle ABC such that the value of AP + BP + CP is minimized. There are two cases:

If there is an angle greater than 120 degrees, that vertex is the fermat point. Otherwise, draw equilateral triangles on each of the sides of ABC. Connect the far vertex of each equilateral triangle to the opposite vertex of triangle ABC. Doing this for each of the three equilateral triangles results in a single common point of intersection for all three lines, which is the Fermat Point.

It should run within 5 seconds on a reasonable machine.

Input: A set of 3 points, not necessarily integers. This can be taken as a nested array, string, list of tuples, etc. (whatever suits your language).

Output: The coordinates of the Fermat point, again, however your language best handles points. Floating point inaccuracies will not be counted against you.

Test Cases:

[[1, 1], [2, 2], [1, 2]] --> [1.2113248654051871, 1.788675134594813]
[[-1, -1], [-2, -1], [0, 0]] --> [-1, -1]
[[-1, -1], [1, -1], [0, 1]] --> [0, -0.42264973081037427]
[[0, 0], [0.5, 0.8660254037844386], [-5, 0]] --> [0, 0]
[[0, 0], [0, -5], [-0.8660254037844386, 0.5]] --> [0, 0]

This is code golf so shortest code wins!

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(vec2{1, 1}, vec2{2, 2}, vec2{1, 2}, vec2{1.2113248654051871, 1.788675134594813})
	test(vec2{-1, -1}, vec2{-2, -1}, vec2{0, 0}, vec2{-1, -1})
	test(vec2{-1, -1}, vec2{1, -1}, vec2{0, 1}, vec2{0, -0.42264973081037427})
	test(vec2{0, 0}, vec2{0.5, 0.8660254037844386}, vec2{-5, 0}, vec2{0, 0})
	test(vec2{0, 0}, vec2{0, -5}, vec2{-0.8660254037844386, 0.5}, vec2{0, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c, r vec2) {
	const eps = 1e-6
	p := fermat_point(a, b, c)
	fmt.Println(p)
	assert(math.Abs(p.x-r.x) < eps)
	assert(math.Abs(p.y-r.y) < eps)
}

type vec2 struct {
	x, y float64
}

func distance(p, q vec2) float64 {
	dx := p.x - q.x
	dy := p.y - q.y
	return math.Hypot(dx, dy)
}

func sides(a, b, c vec2) (float64, float64, float64) {
	return distance(b, c), distance(c, a), distance(a, b)
}

func sides_to_angle(a, b, c float64) float64 {
	return math.Acos((b*b + c*c - a*a) / (2 * b * c))
}

func sides_to_secant(a, b, c float64) float64 {
	return 1 / math.Cos(sides_to_angle(a, b, c)-math.Pi/6)
}

func trilinear_to_cartesian(a, b, c vec2, p, q, r float64) vec2 {
	d := p + q + r
	return vec2{
		(a.x*p + b.x*q + c.x*r) / d,
		(a.y*p + b.y*q + c.y*r) / d,
	}
}

// ported from @abybaddi009 solution
func fermat_point(a, b, c vec2) vec2 {
	switch {
	case sides_to_angle(sides(a, b, c)) >= 2*math.Pi/3:
		return a
	case sides_to_angle(sides(b, c, a)) >= 2*math.Pi/3:
		return b
	case sides_to_angle(sides(c, a, b)) >= 2*math.Pi/3:
		return c
	}

	return trilinear_to_cartesian(a, b, c,
		distance(b, c)*sides_to_secant(sides(a, b, c)),
		distance(c, a)*sides_to_secant(sides(b, c, a)),
		distance(a, b)*sides_to_secant(sides(c, a, b)))
}
