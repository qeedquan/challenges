package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(10))
	fmt.Println(solve(100))
	fmt.Println(solve(1000))
	fmt.Println(solve(10000))
	fmt.Println(solve(100000))
	fmt.Println(solve(1000000))
}

func solve(n float64) float64 {
	x_sq := sos(n*2) - 4*sos(n)
	x := son(n*2) - 2*son(n)
	xm := x / n
	return math.Sqrt((x_sq - 2*xm*x + xm*xm*n) / (n - 1))
}

func son(n float64) float64 {
	return n * (n + 1) / 2
}

func sos(n float64) float64 {
	return n * (n + 1) * (2*n + 1) / 6
}
