package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(20, 5, 6))
	fmt.Println(solve(20, 10, 12))
}

// https://en.wikipedia.org/wiki/Brahmagupta%27s_formula
func solve(p, a, b float64) any {
	if a > p-a || b > p-b {
		return "Eta Shombhob Na."
	}
	c := p/2 - a
	d := p/2 - b
	return math.Sqrt(a*b*c*d) * 2 / (a + b + c + d)
}
