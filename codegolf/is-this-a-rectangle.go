/*

The challenge:
Given four coordinates, each in x y form, your job is to find out whether or not the given coordinates form a rectangle, and output a truthy/falsey.

Rules:
For the sake of simplicity, squares, lines (two identical pairs of coordinates) or dots (all four of the coordinates are the same) are all counted as rectangles

Coordinates for rectangles can be given in any order, for example this:

A----B
|    |
D----C
and this:

A---B
|   |
|   |
|   |
C---D
are both rectangles.

Rectangles can be rotated, so they won't always be parallel to x and y axis.

You may take input in any form you like as long as the order for each coordinate is not mixed: [x,x,x,x,y,y,y,y] is not acceptable, where as [x,y,x,y,x,y,x,y] or [(x,y),(x,y),(x,y),(x,y)] is fine.

Complex numbers are a valid form of input

This is codegolf, so lowest byte count wins.

Test cases:
[0,2, 3,2, 3,0, 0,0]      Truthy
[3,5, 2,0, 0,2, 5,3]      Truthy
[6,3, 3,5, 0,2, 3,0]      Falsy
[1,4, 5,2, 4,0, 0,2]      Truthy
[0,0, 0,0, 3,2, 4,0]      Falsy
[1,1, 1,1, 1,1, 1,1]      Truthy
[1,4, 100,1, 100,1, 1,4]  Truthy

*/

package main

import (
	"math"
	"math/cmplx"
)

func main() {
	assert(rectangle(0+2i, 3+2i, 3+0i, 0+0i) == true)
	assert(rectangle(3+5i, 2+0i, 0+2i, 5+3i) == true)
	assert(rectangle(6+3i, 3+5i, 0+2i, 3+0i) == false)
	assert(rectangle(1+4i, 5+2i, 4+0i, 0+2i) == true)
	assert(rectangle(0+0i, 0+0i, 3+2i, 4+0i) == false)
	assert(rectangle(1+1i, 1+1i, 1+1i, 1+1i) == true)
	assert(rectangle(1+4i, 100+1i, 100+1i, 1+4i) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Noodle9

Calculates the distances from the quadrilateral's centre of mass to all of its vertices and tests if they're equal.

@xnor
Here's an argument that convinced me only a rectangle passes your test. Consider the circle on which four points lie.
Its center must be the points' center of mass.
One way to "average" the four points is to take the midpoint between two points and then midpoint between the other two points, and take the midpoint between those midpoints.
To get the center of the circle at the end, the two midpoints must be opposite each inside the circle.

Draw the segment between the two midpoints. We can obtain the pair of points on the circle producing a midpoint by drawing the perpendicular to that segment and intersecting it with the circle.
In fact, this the only such of pair of points on the circle. Doing so for both midpoints, we find that central segment is now perpendicular to two equal-length segments whose endpoints are the four corners, so they form a rectangle.
(This was all probably confusing without a drawing...)

*/

func rectangle(a, b, c, d complex128) bool {
	p := (a + b + c + d) / 4
	v0 := cmplx.Abs(p - a)
	v1 := cmplx.Abs(p - b)
	v2 := cmplx.Abs(p - c)
	v3 := cmplx.Abs(p - d)
	return equal(v0, v1, v2, v3)
}

func equal(x ...float64) bool {
	const eps = 1e-12
	for i := 1; i < len(x); i++ {
		if math.Abs(x[i]-x[0]) > eps {
			return false
		}
	}
	return true
}
