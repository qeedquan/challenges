/*

This series of katas will introduce you to basics of doing geometry with computers.

Point objects have x, y attributes. Triangle objects have attributes a, b, c describing their corners, each of them is a Point.

Write a function calculating perimeter of a Triangle defined this way.

*/

package main

import (
	"fmt"
	"math"
)

type vec2 struct {
	x, y float64
}

func main() {
	test(vec2{3, 4}, vec2{6, 2}, vec2{5, 2}, 7.434)
	test(vec2{32, 44}, vec2{62, 2}, vec2{51, 22}, 103.5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c vec2, r float64) {
	p := perimeter(a, b, c)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-2)
}

func perimeter(a, b, c vec2) float64 {
	return distance(a, b) + distance(a, c) + distance(b, c)
}

func distance(a, b vec2) float64 {
	return math.Hypot(a.x-b.x, a.y-b.y)
}
