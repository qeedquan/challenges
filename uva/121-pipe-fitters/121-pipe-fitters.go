package main

import (
	"fmt"
	"math"
)

func main() {
	assert(solve(3, 3) == "9 grid")
	assert(solve(2.9, 10) == "29 skew")
	assert(solve(2.9, 10.5) == "30 skew")
	assert(solve(11, 11) == "126 skew")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b float64) string {
	k1 := int(math.Floor(a) * math.Floor(b))
	k2 := max(skew(a, b), skew(b, a))
	if k2 > k1 {
		return fmt.Sprintf("%d skew", k2)
	}
	return fmt.Sprintf("%d grid", k1)
}

func skew(a, b float64) int {
	if b < 1 {
		return 0
	}

	h := 1 + int((b-1)/math.Sqrt(3)*2)
	r := (h-h/2)*int(a) + h/2*int(a-0.5)
	return r
}
