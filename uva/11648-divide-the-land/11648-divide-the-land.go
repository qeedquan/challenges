package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(15, 12, 9, 10))
	fmt.Println(solve(12, 6, 5, 5))
}

func solve(b, a, left, right float64) (float64, float64) {
	c := math.Sqrt((a*a + b*b) / 2.0)
	ltop := (c - a) / (b - a) * left
	lbot := left - ltop
	rtop := (c - a) / (b - a) * right
	rbot := right - rtop
	return lbot, rbot
}
