/*

Is point A on the segment BC?

Input
The input contains the coordinates of points A, B, and C. Each coordinate is an integer with absolute value at most 100.

Output
Output 1 if point A lies on the segment BC, and 0 otherwise.

Examples

Input #1
1 1 -1 0 5 3

Answer #1
1

*/

package main

type Point struct {
	x, y int
}

func main() {
	assert(solve(Point{1, 1}, Point{-1, 0}, Point{5, 3}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, c Point) int {
	if between(b, c, a) {
		return 1
	}
	return 0
}

// https://stackoverflow.com/questions/328107/how-can-you-determine-a-point-is-between-two-other-points-on-a-line-segment
// checks if point C is between line segment AB
func between(a, b, c Point) bool {
	w := (c.y-a.y)*(b.x-a.x) - (c.x-a.x)*(b.y-a.y)
	if abs(w) != 0 {
		return false
	}

	d := (c.x-a.x)*(b.x-a.x) + (c.y-a.y)*(b.y-a.y)
	if d < 0 {
		return false
	}

	l := (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y)
	if d > l {
		return false
	}

	return true
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
