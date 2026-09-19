/*

Task
Your challenge is to write a function named getSlope/get_slope/GetSlope that calculates the slope of the line through two points.

Input
Each point that the function takes in is an array 2 elements long. The first number is the x coordinate and the second number is the y coordinate. If the line through the two points is vertical or if the same point is given twice, the function should return null/None.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(slope(vec2{-3, 4}, vec2{5, 9}))
}

func slope(p1, p2 vec2) float64 {
	if p1.x == p2.x {
		return math.Inf(1)
	}
	return (p2.y - p1.y) / (p2.x - p1.x)
}

type vec2 struct {
	x, y float64
}
