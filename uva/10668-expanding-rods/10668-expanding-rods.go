package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(1000, 100, 0.0001))
	fmt.Println(solve(15000, 10, 0.00006))
	fmt.Println(solve(10, 0, 0.001))
}

func solve(L, C, n float64) float64 {
	const iterations = 100

	LL := (1 + n*C) * L
	lo := 0.0
	hi := math.Pi / 2
	t := 0.0
	R := 0.0
	for i := 0; lo <= hi && i <= iterations; i++ {
		t = lo + (hi-lo)/2
		R = L / (2 * math.Sin(t))
		if R*2*t < LL {
			lo = t
		} else {
			hi = t
		}
	}
	return R - R*math.Cos(t)
}
