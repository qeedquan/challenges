package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(5, 10))
	fmt.Println(solve(3, 4))
}

func solve(b, a float64) float64 {
	e := math.Sqrt(1 - (b*b)/(a*a))
	r := 1.0
	p := 1.0
	ep := 1.0
	for i := float64(1); i < 10000; i += 2 {
		ep *= e * e
		p *= (i * i) / ((i + 1) * (i + 1))
		r -= p * ep / i
	}
	r *= 2 * math.Pi * a
	return r
}
