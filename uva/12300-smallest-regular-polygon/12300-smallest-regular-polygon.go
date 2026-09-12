package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.6f\n", solve(0, 0, 1, 1, 4))
	fmt.Printf("%.6f\n", solve(1, 2, 3, 4, 5))
	fmt.Printf("%.6f\n", solve(2, 3, 4, 5, 6))
}

func solve(ax, ay, bx, by float64, n int) float64 {
	d := math.Hypot(ax-bx, ay-by)
	r := d / 2
	s := float64(n)
	if n%2 != 0 {
		m := float64(n-1) / 2
		r = d / (2 * math.Sin(m/s*math.Pi))
	}
	return r * r * math.Sin(2*math.Pi/s) * s / 2
}
