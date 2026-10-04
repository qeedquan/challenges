/*

Input
An integer n and a pair of integer valued (x, y) coordinates. The coordinates are indexed from 1. For example, n=10 and (1,2), (10, 7).

Output
The number of integer points in an n by n grid that are on the same side of the line from (1,2) to (10, 7) as the coordinate (1,1). Points that are exactly on the line should be counted as well.

Examples
For n=10 and (1,2), (10, 7),

https://i.stack.imgur.com/dkTUR.png

The output should be 41.

For n=8 and (8, 3), (3, 8),

https://i.stack.imgur.com/QKPoj.png

The output should be 49.

*/

package main

import (
	"image"
)

func main() {
	assert(points(10, image.Pt(1, 2), image.Pt(10, 7)) == 41)
	assert(points(8, image.Pt(8, 3), image.Pt(3, 8)) == 49)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func points(n int, p0, p1 image.Point) int {
	if p1.X < p0.X {
		p0, p1 = p1, p0
	}

	c := 0
	for y := 1; y <= n; y++ {
		for x := 1; x <= n; x++ {
			if orientation(p0, p1, image.Pt(x, y)) <= 0 {
				c++
			}
		}
	}
	return c
}

func orientation(a, b, c image.Point) int {
	return (b.X-a.X)*(c.Y-a.Y) - (b.Y-a.Y)*(c.X-a.X)
}
