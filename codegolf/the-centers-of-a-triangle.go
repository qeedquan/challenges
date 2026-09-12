/*

Circles and squares have a single, definite center point. However, the notion of the center of a triangle has long been discussed. Four different centers were known to the Ancient Greeks:

Incenter: The intersection of the angle bisectors of the triangle
Centroid: The intersection of the lines from each vertex of the triangle to the middle of its opposite side
Circumcenter: The intersection of the perpendicular bisectors of the sides
Orthocenter: The intersection of the altitudes of the triangle
Euler later proved that the centroid, circumcenter and orthocenter are collinear in any triangle. The line that these three points are on in a triangle is called the Euler Line. It is defined for every triangle except an equilateral triangle, where all the points coincide.

Your challenge is to create the shortest program or function that, when given two inputs, outputs a specific center or the Euler Line of the triangle. The first specifies the coordinates of each vertex of a triangle. The second is an integer from 1 to 5, determining what to output.

1 - Incenter
2 - Centroid
3 - Circumcenter
4 - Orthocenter
5 - Equation of Euler Line
    (if the Euler Line is vertical, output the `x` value of the line
      (e.g. output `5` if the equation of the line is `x = 5`))
You may assume that the given vertices will never be collinear, and that they will always be integer coordinates (this also excludes the possibility of having an equilateral triangle as an input, as per @R.Kap's comment).

The input array should be a valid nested array in your language, and input should be in any reasonable format. Any float values should be displayed to at least 3 decimal places, but no less. An outputted point should be a valid array in your language, matching with the input format.

Test cases:

Input: [(-2, 0), (1, 0), (0, 1)] 1
Output: (-0.089, 0.451)

Input: [(-2, 0), (1, 0), (0, 1)] 2
Output: (-0.333, 0.333)

Input: [(-2, 0), (1, 0), (0, 1)] 3
Output: (-0.5, -0.5)

Input: [(-2, 0), (1, 0), (0, 1)] 4
Output: (0, 2)

Input: [(-2, 0), (1, 0), (0, 1)] 5
Output: 5x + 2

Clarification: The input can either be from stdin, either space or new-line separated, or as the arguments to a function. The output, however, must be written to stdout.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(vec2{-2, 0}, vec2{1, 0}, vec2{0, 1}, 1)
	test(vec2{-2, 0}, vec2{1, 0}, vec2{0, 1}, 2)
	test(vec2{-2, 0}, vec2{1, 0}, vec2{0, 1}, 3)
	test(vec2{-2, 0}, vec2{1, 0}, vec2{0, 1}, 4)
	test(vec2{-2, 0}, vec2{1, 0}, vec2{0, 1}, 5)
}

func test(p1, p2, p3 vec2, t int) {
	pc := centers(p1, p2, p3, t)
	fmt.Println(pc)
}

/*

https://en.wikipedia.org/wiki/Euler_line
https://byjus.com/maths/incenter-of-a-triangle/
https://www.cuemath.com/geometry/centroid-of-a-triangle/
https://math.stackexchange.com/questions/4336754/determinant-formula-for-coordinates-of-circumcenter-and-orthocenter-of-a-triangl

*/

func centers(p1, p2, p3 vec2, t int) any {
	switch t {
	case 1:
		return incenter(p1, p2, p3)
	case 2:
		return centroid(p1, p2, p3)
	case 3:
		return circumcenter(p1, p2, p3)
	case 4:
		return orthocenter(p1, p2, p3)
	case 5:
		return eulerline(p1, p2, p3)
	}
	return nil
}

func incenter(p1, p2, p3 vec2) vec2 {
	a, b, c := barycenter(p1, p2, p3)
	d := a + b + c
	return vec2{
		(a*p1.x + b*p2.x + c*p3.x) / d,
		(a*p1.y + b*p2.y + c*p3.y) / d,
	}
}

func centroid(p1, p2, p3 vec2) vec2 {
	return vec2{
		(p1.x + p2.x + p3.x) / 3,
		(p1.y + p2.y + p3.y) / 3,
	}
}

func circumcenter(p1, p2, p3 vec2) vec2 {
	dx := det3x3([3][3]float64{
		{dot(p1, p1), p1.y, 1},
		{dot(p2, p2), p2.y, 1},
		{dot(p3, p3), p3.y, 1},
	})
	dy := det3x3([3][3]float64{
		{p1.x, dot(p1, p1), 1},
		{p2.x, dot(p2, p2), 1},
		{p3.x, dot(p3, p3), 1},
	})
	dz := det3x3([3][3]float64{
		{p1.x, p1.y, 1},
		{p2.x, p2.y, 1},
		{p3.x, p3.y, 1},
	})
	return vec2{dx / (2 * dz), dy / (2 * dz)}
}

func orthocenter(p1, p2, p3 vec2) vec2 {
	dx := det3x3([3][3]float64{
		{p1.y, p2.x*p3.x + p1.y*p1.y, 1},
		{p2.y, p3.x*p1.x + p2.y*p2.y, 1},
		{p3.y, p1.x*p2.x + p3.y*p3.y, 1},
	})
	dy := det3x3([3][3]float64{
		{p1.x*p1.x + p2.y*p3.y, p1.x, 1},
		{p2.x*p2.x + p3.y*p1.y, p2.x, 1},
		{p3.x*p3.x + p1.y*p2.y, p3.x, 1},
	})
	dz := det3x3([3][3]float64{
		{p1.x, p1.y, 1},
		{p2.x, p2.y, 1},
		{p3.x, p3.y, 1},
	})
	return vec2{dx / dz, dy / dz}
}

func eulerline(p1, p2, p3 vec2) string {
	pe := centroid(p1, p2, p3)
	pi := circumcenter(p1, p2, p3)
	if p1 == p2 && p2 == p3 {
		return pe.String()
	}

	pl := sub(pe, pi)
	if pl.x == 0 {
		return fmt.Sprintf("x=%.3f", pe.x)
	}

	b := 0.0
	if pl.x != 0 {
		b = pe.y - pl.y/pl.x*pe.x
	}

	return fmt.Sprintf("%.3fx + %.3f", pl.y/pl.x, b)
}

func barycenter(p1, p2, p3 vec2) (float64, float64, float64) {
	a := distance(p2, p3)
	b := distance(p3, p1)
	c := distance(p1, p2)
	return a, b, c
}

func distance(p1, p2 vec2) float64 {
	dx := p1.x - p2.x
	dy := p1.y - p2.y
	return math.Hypot(dx, dy)
}

func sub(p1, p2 vec2) vec2 {
	return vec2{p1.x - p2.x, p1.y - p2.y}
}

func dot(p1, p2 vec2) float64 {
	return p1.x*p2.x + p1.y*p2.y
}

func det3x3(m [3][3]float64) float64 {
	c00 := m[1][1]*m[2][2] - m[1][2]*m[2][1]
	c01 := m[1][2]*m[2][0] - m[1][0]*m[2][2]
	c02 := m[1][0]*m[2][1] - m[1][1]*m[2][0]
	return m[0][0]*c00 + m[0][1]*c01 + m[0][2]*c02
}

type vec2 struct {
	x, y float64
}

func (v vec2) String() string {
	return fmt.Sprintf("(%.3f, %.3f)", v.x, v.y)
}
