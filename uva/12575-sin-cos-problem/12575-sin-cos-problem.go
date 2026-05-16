package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(1, 1))
	fmt.Println(solve(-1, 1))
	fmt.Println(solve(1, -1))
	fmt.Println(solve(-1, -1))
}

func solve(A, B float64) (float64, float64) {
	t := math.Atan2(A, B)
	if t < 0 {
		t += 2 * math.Pi
	}
	return t, A*math.Sin(t) + B*math.Cos(t)
}
