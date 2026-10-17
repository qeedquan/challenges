/*

Challenge description
On a Cartesian plane, a triangle can be described as a set of three points, each point being one of the triangle's vertices. For instance, coordinates (2, 1), (6, 8), (-7, 3) correspond to the following triangle:

https://i.stack.imgur.com/tOxFT.png

As you can see, it does not contain the origin of the plane, i.e. the point (0, 0), unlike the triangle (-5, 3), (2, 7), (3, -8):

https://i.stack.imgur.com/jOW8U.png

Your job is to write a program, that given exactly six integers describing coordinates of a triangle, determines whether or not it contains the origin of the Cartesian plane.
The objective is to make your code as short as possible, since this is a code-golf challenge.

Input

Six integers corresponding to three coordinates of a triangle, for example:

1 4 -9 0 3 -4 -> (1, 4), (-9, 0), (3, -4)

You can also accept a list of integers, a list of two-tuples... - whatever is most convenient or makes your code shorter.

Output
A truthy value if the triangle contains the origin (1, True), falsy value otherwise (0, False). You don't need to validate the input.

Sample inputs / outputs
(18, -36), (36, 19), (-15, 9) -> True
(-23, 31), (-27, 40), (32, 22) -> False
(-40, -34), (35, 20), (47, 27) -> False
(0, 6), (-36, -42), (12, -34) -> True
(-24, 6), (36, 6), (-14, -25) -> True
Triangle images courtesy of Wolfram Alpha

*/

package main

import "image"

func main() {
	assert(hasorigin(image.Pt(18, -36), image.Pt(36, 19), image.Pt(-15, 9)) == true)
	assert(hasorigin(image.Pt(-23, 31), image.Pt(-27, 40), image.Pt(32, 22)) == false)
	assert(hasorigin(image.Pt(-40, -34), image.Pt(35, 20), image.Pt(47, 27)) == false)
	assert(hasorigin(image.Pt(0, 6), image.Pt(-36, -42), image.Pt(12, -34)) == true)
	assert(hasorigin(image.Pt(-24, 6), image.Pt(36, 6), image.Pt(-14, -25)) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hasorigin(a, b, c image.Point) bool {
	p := image.Point{}
	b1 := sign(p, a, b) < 0
	b2 := sign(p, b, c) < 0
	b3 := sign(p, c, a) < 0
	return b1 == b2 && b2 == b3
}

func sign(a, b, c image.Point) int {
	return (a.X-c.X)*(b.Y-c.Y) - (b.X-c.X)*(a.Y-c.Y)
}
