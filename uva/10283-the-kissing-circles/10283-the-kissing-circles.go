package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(10, 3))
	fmt.Println(solve(10, 4))
	fmt.Println(solve(10, 5))
	fmt.Println(solve(10, 6))
}

func solve(R, N float64) (x, y, z float64) {
	t := (math.Pi - 2*math.Pi/N) / 2
	if N <= 2 {
		x = R / N
	} else {
		x = R / (1 + 1/math.Cos(t))
		y = (R - x) * (R - x) * math.Sin(2*math.Pi/N) * N / 2
		y -= x * x * math.Pi * (t * 2 * N / math.Pi / 2)
	}
	z = R*R*math.Pi - y - x*x*math.Pi*N
	return
}
