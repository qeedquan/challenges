package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(1, 0.5))
	fmt.Println(solve(1, 0.3))
	fmt.Println(solve(2, 0.6))
	fmt.Println(solve(24, 0.25))
}

func solve(n int, t float64) float64 {
	f := math.Pow(2, float64(n))
	for i := n - 1; i >= 0; i-- {
		prize := math.Pow(2, float64(i))
		eq := prize / f
		if eq <= t {
			f = (t + 1) / 2 * f
		} else {
			f = (eq-t)/(1-t)*prize + (1-eq)/(1-t)*(eq+1)/2*f
		}
	}
	return f
}
