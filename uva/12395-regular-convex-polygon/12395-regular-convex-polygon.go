package main

import (
	"math"
)

func main() {
	assert(solve(-1385.736326, -146.954822, 430.000292, -2041.361203, 1162.736034, 478.316025) == 3)
	assert(solve(0.000000, 4147.000000, -4147.000000, 0.000000, 0.000000, -4147.000000) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x1, y1, x2, y2, x3, y3 float64) int {
	a := math.Hypot(x1-x2, y1-y2)
	b := math.Hypot(x3-x2, y3-y2)
	c := math.Hypot(x1-x3, y1-y3)
	ta := math.Acos((b*b+c*c-a*a)/(2*b*c)) * 2
	tb := math.Acos((a*a+c*c-b*b)/(2*a*c)) * 2
	tc := math.Acos((a*a+b*b-c*c)/(2*a*b)) * 2
	for i := 3; i < math.MaxInt; i++ {
		theta := 2 * math.Pi / float64(i)
		if mod(ta, theta) && mod(tb, theta) && mod(tc, theta) {
			return i
		}
	}
	return -1
}

func mod(a, b float64) bool {
	const eps = 1e-8
	return math.Mod(a, b) < eps || math.Abs(math.Mod(a, b)-b) < eps
}
