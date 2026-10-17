package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(3, 0.43301))
	fmt.Println(solve(6, 2.59808))
	fmt.Println(solve(9, 6.18182))
	fmt.Println(solve(0, 2.33333))
}

func solve(n int, area float64) (float64, float64) {
	if n < 1 {
		return 0, 0
	}
	triangleArea := area / float64(n)
	angle := 2.0 * math.Pi / float64(n)
	outerRadius := math.Sqrt(2.0 * triangleArea / math.Sin(angle))
	polySide := math.Sqrt((2.0 * outerRadius * outerRadius) * (1.0 - math.Cos(angle)))
	height := 2.0 * triangleArea / polySide

	smallCircleArea := math.Pi * height * height
	largeCircleArea := math.Pi * outerRadius * outerRadius

	return largeCircleArea - area, area - smallCircleArea
}
