/*

The problem
In this kata, you're going write a function called pointInPoly to test if a point is inside a polygon.

Points will be represented as [x,y] arrays.

The polygon will be an array of points which are the polygon's vertices. The last point in the array connects back to the first point.

You can assume:

The polygon will be a valid simple polygon. That is, it will have at least three points, none of its edges will cross each other, and exactly two edges will meet at each vertex.

In the tests, the point will never fall exactly on an edge of the polygon.

Testing
To help you visualize your test cases, the showAndTest(poly,point,inside) function is preloaded. It draws the polygon and point and then calls Test.expect automatically.

So if you call:

showAndTest([[-5, -5], [5, -5], [0, 5]], [0,0], true)

then you'll see:

The drawing window is 14x14 units wide and centered at the origin.

*/

package main

import "image"

func main() {
	assert(pointInPolygon([]image.Point{
		{-5, -5},
		{5, -5},
		{0, 5},
		{0, 0},
	}, image.Point{0, 0}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://stackoverflow.com/questions/1119627/how-to-test-if-a-point-is-inside-of-a-convex-polygon-in-2d-integer-coordinates
// https://math.stackexchange.com/questions/274712/calculate-on-which-side-of-a-straight-line-is-a-given-point-located
func pointInPolygon(polygon []image.Point, point image.Point) bool {
	if len(polygon) < 3 {
		return false
	}

	pos := 0
	neg := 0
	x := point.X
	y := point.Y
	for i := range polygon {
		if polygon[i] == point {
			break
		}

		x1 := polygon[i].X
		y1 := polygon[i].Y

		i2 := (i + 1) % len(polygon)
		x2 := polygon[i2].X
		y2 := polygon[i2].Y

		d := (x-x1)*(y2-y1) - (y-y1)*(x2-x1)
		if d > 0 {
			pos++
		} else if d < 0 {
			neg++
		}

		if pos > 0 && neg > 0 {
			return false
		}
	}
	return true
}
