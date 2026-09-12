/*

We'd like to know the area of an arbitrary shape. The only information of the shape is that it is bounded within the square area of four points: (0, 0), (1, 0), (1, 1) and (0, 1).

Given a function f(x, y) which returns a boolean representing whether the point (x, y) is inside the shape, determine the area of the shape. Your answer is allowed to differ from the true answer by at most 0.01.

Hint: http://bit.ly/1vJJt61

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(area(circular))
	fmt.Println(area(fullshape))
}

func area(in func(float64, float64) bool) float64 {
	const N = 100000

	c := 0.0
	for range N {
		x := rand.Float64()
		y := rand.Float64()
		if in(x, y) {
			c += 1
		}
	}
	return c / N
}

func circular(x, y float64) bool {
	dx := x - 0.5
	dy := y - 0.5
	return dx*dx+dy*dy <= 0.25
}

func fullshape(x, y float64) bool {
	return (0 < x && x < 1) && (0 < y && y < 1)
}
