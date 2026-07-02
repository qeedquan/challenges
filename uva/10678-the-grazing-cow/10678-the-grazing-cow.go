package main

import (
	"fmt"
	"math"
)

func main() {
	test(10, 12, 62.517)
	test(23, 45, 1366.999)
	test(12, 18, 189.670)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(d, l, r float64) {
	v := solve(d, l)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-4)
}

func solve(d, l float64) float64 {
	a := l / 2
	b := math.Sqrt(l*l/4 - d*d/4)
	return math.Pi * a * b
}
