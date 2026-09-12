package main

import "math"

func main() {
	assert(solve(1960) == 3)
	assert(solve(1981) == 8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	n = ((n - 1960) / 10) + 2
	m := math.Pow(2, float64(n))
	i := 1
	for ; m > 0; i++ {
		m -= math.Log10(float64(i)) / math.Log10(2)
	}
	return i - 2
}
