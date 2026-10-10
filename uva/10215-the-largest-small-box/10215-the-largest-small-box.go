package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(1, 1))
	fmt.Println(solve(2, 2))
	fmt.Println(solve(3, 3))
}

func solve(l, w float64) (float64, float64, float64) {
	const eps = 1e-8
	m := (l + w - math.Sqrt(w*w-w*l+l*l)) / 6.0
	l = min(l, w)
	return m + eps, 0, l/2 + eps
}
