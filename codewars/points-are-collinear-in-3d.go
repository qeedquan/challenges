/*

Write a function that accepts a list of at least three points in 3D and returns a boolean value that tells whether the points are collinear or not.

From Wikipedia: In geometry, collinearity of a set of points is the property of their lying on a single line. A set of points with this property is said to be collinear (sometimes spelled as colinear). In greater generality, the term has been used for aligned objects, that is, things being "in a line" or "in a row".

Data types
The points that you will get are using the Point3d data type which consists of a tuple with three floats:

(x, y, z)
Note:

Don't expect getting one or two or none points in the input, all the inputs contain three points at least.
Some inputs might contain one or more duplicated points.

*/

package main

type vec3 struct {
	x, y, z float64
}

func main() {
	assert(collinear([]vec3{
		{8, -8, 1},
		{4, -12, 5},
		{-10, -26, 19},
		{9, -7, 0},
	}) == true)

	assert(collinear([]vec3{
		{-4.5, -62, 5},
		{9, -50, 8},
		{-27, -82, 0},
	}) == true)

	assert(collinear([]vec3{
		{-4.5, -62, 3},
		{9, -52, 8},
		{-27, -82, 0},
	}) == false)

	assert(collinear([]vec3{
		{6, 7, 1},
		{2, -3, 1},
		{4, -5, 0},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func collinear(p []vec3) bool {
	if len(p) < 3 {
		return true
	}

	zero := vec3{}
	for i := 2; i < len(p); i++ {
		a := sub(p[i-2], p[i-1])
		b := sub(p[i-2], p[i])
		c := cross(a, b)
		if c != zero {
			return false
		}
	}
	return true
}

func sub(a, b vec3) vec3 {
	return vec3{a.x - b.x, a.y - b.y, a.z - b.z}
}

func cross(a, b vec3) vec3 {
	return vec3{
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x,
	}
}
