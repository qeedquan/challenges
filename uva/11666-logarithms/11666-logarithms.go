package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(6))
	fmt.Println(solve(7))
	fmt.Println(solve(300))
}

func solve(n float64) (float64, float64) {
	L := math.Floor(math.Log(n))
	r := 1 - n/math.Exp(L)
	if math.Abs(r) >= 1 {
		L += 1
		r = 1 - n/math.Exp(L)
	}
	return L, r
}
