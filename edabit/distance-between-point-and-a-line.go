/*

Given the formula for a straight line y = ax + b and the x, y coordinates of a point, find the distance between that point and the line. Round the result to two decimal points.

Examples
dist("y=(-3/4)x-5/4", 5, 2) ➞ 5.6

dist("y=(5+1/3)x-2.3", 1, 4) ➞ 0.18

dist("y=2.2x-(3+1/5)", 3, -2) ➞ 2.23

*/

package main

import (
	"fmt"
	"math"
)

type Line struct {
	m, b float64
}

type Vec2 struct {
	x, y float64
}

func main() {
	test(Line{2.2, -(3 + 1.0/5)}, Vec2{3, -2}, 2.23)
	test(Line{-3.0 / 4, -5.0 / 4}, Vec2{5, 2}, 5.6)
	test(Line{5 + 1.0/3, -2.3}, Vec2{1, 4}, 0.18)
	test(Line{math.Sqrt2, math.Sqrt2}, Vec2{2, 2}, 1.29)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(l Line, p Vec2, r float64) {
	d := distance(l, p)
	fmt.Printf("%.2f\n", d)
	assert(math.Abs(d-r) < 1e-2)
}

// https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
func distance(l Line, p Vec2) float64 {
	return math.Abs(l.b+l.m*p.x-p.y) / math.Sqrt(1+l.m*l.m)
}
