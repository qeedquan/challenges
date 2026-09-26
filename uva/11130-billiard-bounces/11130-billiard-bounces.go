package main

import (
	"fmt"
	"math"
)

func main() {
	test(100, 50, 10, 90, 10)
	test(100, 50, 10, 0, 40)
	test(100, 100, 10, 45, 15)
	test(100, 50, 10, 1, 200)
	test(100, 50, 10, 89, 200)
	test(100, 50, 10, 45, 1000)
	test(100, 100, 10, 30, 200)
}

func test(a, b, v, A, s float64) {
	H, V := solve(a, b, v, A, s)
	fmt.Printf("%.0f %.0f\n", H, V)
}

func solve(a, b, v, A, s float64) (float64, float64) {
	L := s * v / 2
	H := L * math.Cos(A/180*math.Pi)
	V := L * math.Sin(A/180*math.Pi)
	return H / a, V / b
}
