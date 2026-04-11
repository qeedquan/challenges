/*

Given a polygon of n points (not necessarily convex), your goal is to say whether there is a circle of a
given a radius R that contains the polygon or not.

Input
The input consists of several input cases. The first line of each input case is the number n (with n < 100)
of vertices in the polygon. Then you are given n lines each containing a couple of integers that define
the coordinates of the vertices. The last line of the input case will be a real number indicating the
radius R of the circle.
The end of the input will be signaled by an input case with n = 0 vertices, that must not be
processed.
You may assume that no vertex will appear twice in any given input case.

Output
If the polygon can be packed in a circle of the given radius you have to print:
The polygon can be packed in the circle.
If the polygon cannot be packed you have to print:
There is no way of packing that polygon.

Sample Input
3
0 0
1 0
0 1
1.0
3
0 0
1 0
0 1
0.1
0

Sample Output
The polygon can be packed in the circle.
There is no way of packing that polygon.

*/

package main

import "math"

type Point struct {
	x, y float64
}

func main() {
	assert(pack([]Point{
		{0, 0},
		{1, 0},
		{0, 1},
	}, 1) == true)

	assert(pack([]Point{
		{0, 0},
		{1, 0},
		{0, 1},
	}, 0.1) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pack(p []Point, r float64) bool {
	n := len(p)
	for i := range n {
	loop:
		for j := range n {
			if i == j {
				continue
			}

			c, ok := circle(p[i], p[j], r)
			if !ok {
				continue
			}

			for k := range n {
				if distance(p[k], c) > r {
					continue loop
				}
			}

			return true
		}
	}
	return false
}

func circle(p1, p2 Point, r float64) (Point, bool) {
	d2 := (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)
	det := r*r/d2 - 0.25

	if det < 0.0 {
		return Point{}, false
	}

	h := math.Sqrt(det)
	c := Point{}
	c.x = (p1.x+p2.x)*0.5 + (p1.y-p2.y)*h
	c.y = (p1.y+p2.y)*0.5 + (p2.x-p1.x)*h
	return c, true
}

func distance(p1, p2 Point) float64 {
	return math.Hypot(p1.x-p2.x, p1.y-p2.y)
}
