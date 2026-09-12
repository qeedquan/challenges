package main

import (
	"math"
)

func main() {
	assert(solve(1) == 2)
	assert(solve(5) == 7)
	assert(solve(100000) == 166084)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 0 {
		return 0
	}

	t := make([]float64, n*10+10)
	t[0] = math.Log10(3)
	for i := range len(t) - 1 {
		j := float64(i)
		z := 2*math.Log10(2*j+1) - math.Log10(2*j+2) - math.Log10(2*j+3) - math.Log10(4)
		t[i+1] = t[i] + z
	}

	l := 0
	r := len(t) - 1
	for r-l > 1 {
		m := (l + r) / 2
		if t[m] > float64(-n) {
			l = m
		} else {
			r = m
		}
	}
	return r
}
