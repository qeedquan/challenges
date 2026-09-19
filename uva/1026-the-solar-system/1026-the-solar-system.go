package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(10, 5, 10, 10, 5, 10))
	fmt.Println(solve(10, 5, 10, 20, 10, 10))
}

func solve(a1, b1, t1, a2, b2, t2 float64) (float64, float64) {
	const eps = 1e-7

	t3 := math.Sqrt((t1 * t1 * a2 * a2 * a2) / (a1 * a1 * a1))
	t2 = math.Mod(t2, t3)
	c2 := math.Sqrt(a2*a2 - b2*b2)

	area_ellipse := math.Pi * a2 * b2
	area_run := area_ellipse * (t2 / t3)

	lo := 0.0
	hi := 2 * math.Pi
	mid := (lo + hi) / 2
	for hi-lo > eps {
		area := (mid*a2*b2)/2 - (c2*b2*math.Sin(mid))/2
		if area < area_run {
			lo = mid
		} else {
			hi = mid
		}
		mid = (lo + hi) / 2
	}
	return a2 * math.Cos(lo), b2 * math.Sin(lo)
}
