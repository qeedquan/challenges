package main

import (
	"math"
)

func main() {
	tab := []int64{
		0, 1, 3, 8, 21, 55, 144, 377, 987, 2584, 6765, 17711, 46368, 121393,
		317811, 832040, 2178309, 5702887, 14930352, 39088169, 102334155, 267914296,
		701408733, 1836311903, 4807526976, 12586269025, 32951280099, 86267571272,
		225851433717, 591286729879, 1548008755920,
	}

	assert(solve(2) == 3)
	assert(solve(3) == 8)
	assert(solve(20) == 102334155)
	for i := range int64(25) {
		assert(solve(i) == solvebf(i))
	}

	for i := range tab {
		assert(solve(int64(i)) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A001906
func solve(n int64) int64 {
	x := 2 * float64(n) * math.Asinh(0.5)
	y := math.Sqrt(5.0 / 4)
	r := math.Round(math.Sinh(x) / y)
	return int64(r)
}

func solvebf(n int64) int64 {
	if n < 0 {
		return 0
	}

	p := [][3]int64{{0, 0, 0}, {1, 1, 0}}
	for i := int64(2); i <= n; i++ {
		p = append(p, [3]int64{})
		p[i][0] = p[i-1][0] + p[i-1][1] + p[i-1][2]
		p[i][1] = p[i-1][0] + p[i-1][1] + p[i-1][2]
		p[i][2] = p[i-1][0] + p[i-1][2]
	}
	return p[n][0] + p[n][2]
}
