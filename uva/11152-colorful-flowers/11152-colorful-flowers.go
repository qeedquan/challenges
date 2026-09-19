package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func main() {
	fmt.Println(solve(3, 4, 5))
}

func solve(a, b, c float64) (float64, float64, float64) {
	inner := incircle(a, b, c)
	outer := circumcircle(a, b, c)

	area_inner := inner * inner * math.Pi
	area_triangle := area(a, b, c) - area_inner
	area_outer := outer*outer*math.Pi - area_inner - area_triangle

	return area_outer, area_triangle, area_inner
}

func incircle(ab, bc, ca float64) float64 {
	return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca))
}

func circumcircle(ab, bc, ca float64) float64 {
	return (ab * bc * ca) / (4.0 * area(ab, bc, ca))
}

func area(a, b, c float64) float64 {
	s := (a + b + c) / 2
	return math.Sqrt(s * (s - a) * (s - b) * (s - c))
}

func perimeter(a, b, c float64) float64 {
	return a + b + c
}

func dist(a, b Point) float64 {
	return math.Hypot(a.x-b.x, a.y-b.y)
}
