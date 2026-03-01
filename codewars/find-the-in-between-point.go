/*

For this kata, you are given three points (x1,y1,z1), (x2,y2,z2), and (x3,y3,z3) that lie on a straight line in 3-dimensional space. You have to figure out which point lies in between the other two.

Your function should return 1, 2, or 3 to indicate which point is the in-between one.

*/

package main

type vec2 struct {
	x, y float64
}

func main() {
	a, b, c := vec2{1, 1}, vec2{2, 2}, vec2{3, 3}
	assert(midpoint(a, b, c) == 2)
	assert(midpoint(c, a, b) == 3)
	assert(midpoint(b, c, a) == 1)

	a, b, c = vec2{0, 0}, vec2{0.7, 0}, vec2{2, 0}
	assert(midpoint(a, b, c) == 2)
	assert(midpoint(b, c, a) == 1)
	assert(midpoint(c, a, b) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

A simple brute force solution is to generate all permutation of the ordering of the points (3! = 6).

Since it is guaranteed that the 3 points are on the same line, this means that their direction vectors for every pair of points would be the same (disregarding the sign of the direction),
only the length of the direction vectors would be different.

The ordering we want is (p0 p1 p2) where p0 is the leftmost point, p1 is the middle, and p2 is the rightmost point.
The permutation with the maximum distance(p0, p2) and distance(p0, p1) <= distance(p0, p2) would be the correct one.

*/

func midpoint(a, b, c vec2) int {
	p := [][3]vec2{
		{a, b, c},
		{a, c, b},
		{b, a, c},
		{b, c, a},
		{c, a, b},
		{c, b, a},
	}
	l := []int{2, 3, 1, 3, 1, 2}

	m, n := 0.0, 0
	for i, p := range p {
		d1 := length2(sub(p[1], p[0]))
		d2 := length2(sub(p[2], p[0]))
		if d1 <= d2 && d2 > m {
			m, n = d2, i
		}
	}
	return l[n]
}

func sub(a, b vec2) vec2 {
	return vec2{a.x - b.x, a.y - b.y}
}

func length2(v vec2) float64 {
	return v.x*v.x + v.y*v.y
}
