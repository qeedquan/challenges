package main

import "math"

func main() {
	assert(steps(45, 48) == 3)
	assert(steps(45, 49) == 3)
	assert(steps(45, 50) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func steps(x, y int) int {
	d := y - x
	if d <= 0 {
		return 0
	}

	k := int(math.Sqrt(float64(d)))
	if k*k >= d {
		return (2 * k) - 1
	}
	if k*(k+1) >= d {
		return 2 * k
	}
	return (2 * k) + 1
}
