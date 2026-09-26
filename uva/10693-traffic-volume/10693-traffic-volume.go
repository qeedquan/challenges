package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(5, 3))
}

func solve(L, f float64) (float64, float64) {
	v := math.Sqrt(2 * L * f)
	fun := 3600 * v / (L + v*v/2/f)
	return v, fun
}
