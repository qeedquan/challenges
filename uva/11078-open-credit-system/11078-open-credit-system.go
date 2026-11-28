package main

import "math"

func main() {
	assert(solve([]int{100, 20}) == 80)
	assert(solve([]int{4, 3, 2, 1}) == 3)
	assert(solve([]int{1, 2, 3, 4}) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int) int {
	if len(a) < 2 {
		return 0
	}

	d := math.MinInt
	s := a[0]
	for i := 1; i < len(a); i++ {
		d = max(d, s-a[i])
		s = max(s, a[i])
	}
	return d
}
