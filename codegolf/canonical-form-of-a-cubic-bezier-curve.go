/*

On Pomax's Primer on Bézier Curves this "fairly funky image" appears:

https://pomax.github.io/bezierinfo/#canonical

This is related to the fact that every cubic Bézier curve can be put in a "canonical form" by an affine transformation that maps its first three control points to (0,0), (0,1) and (1,1) respectively.
Where the fourth and last control point lies after the transformation then determines the curve's nature – suppose it lies at (x,y), then

If y >= 1 the curve has a single inflection point (green region in the image).
If y <= 1 but y >= (-x^2 +2x + 3)/4 and x <= 1 the curve has two inflection points.
If y <= (-x^2 + 3x)/3 and x <= 0 or y <= 1 and 0 <= x <= 1 or y <= 1 and x >= 1 the curve is a simple arch with no inflection points.
In all other cases the curve has a loop (red region in the image).

Task
Given the coordinates of the transformed curve's fourth point (x,y) in any reasonable format, output the curve's type, which is exactly one of "arch", "single inflection", "double inflection" or "loop".
If (x,y) is on the boundary between two or more regions you may output the type corresponding to any of those regions. You may also use any four distinct values to represent the curve types.

This is code-golf; fewest bytes wins.

Test cases
(x,y) -> type(s)
(2,2) -> single
(-1,2) -> single
(2,0) -> arch
(1,-2) -> arch
(-1,-2) -> arch
(-2,0) -> double
(-3,-1) -> double
(-1,-1) -> loop
(-3,-4) -> loop
(0,1) -> single or double
(-1,0) -> double or loop
(-3,-3) -> double or loop
(0,0) -> arch or loop
(2,1) -> arch or single
(1,1) -> single or double or arch or loop

*/

package main

import "math"

func main() {
	assert(classify(2, 2) == "single")
	assert(classify(-1, 2) == "single")
	assert(classify(2, 0) == "arch")
	assert(classify(1, -2) == "arch")
	assert(classify(-1, -2) == "arch")
	assert(classify(-2, 0) == "double")
	assert(classify(-3, -1) == "double")
	assert(classify(-1, -1) == "loop")
	assert(classify(-3, -4) == "loop")
	assert(classify(0, 1) == "single")
	assert(classify(-1, 0) == "double")
	assert(classify(-3, -3) == "double")
	assert(classify(0, 0) == "arch")
	assert(classify(2, 1) == "single")
	assert(classify(1, 1) == "single")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func classify(x, y float64) string {
	if y >= 1 {
		return "single"
	}

	v := (-x*x + 2*x + 3) / 4
	if y <= 1 && y >= v && x <= 1 {
		return "double"
	}

	u := (-x*x + 3*x) / 3
	v = (math.Sqrt(3*(4*x-x*x)) - x) / 2
	if (y <= u && x <= 0) || (y <= v && (0 <= x && x <= 1)) || (y <= 1 && x >= 1) {
		return "arch"
	}

	return "loop"
}
