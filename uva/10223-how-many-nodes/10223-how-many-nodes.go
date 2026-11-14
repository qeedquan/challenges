package main

import (
	"math"
)

func main() {
	assert(solve(5) == 3)
	assert(solve(14) == 4)
	assert(solve(42) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int64) int64 {
	if n < 1 {
		return -1
	}

	x := search(ilog2(n)+1, func(i int64) bool {
		return catalan(i) >= n
	})

	if catalan(x) != n {
		return -1
	}
	return x
}

func search(n int64, f func(int64) bool) int64 {
	i, j := int64(0), n
	for i < j {
		h := int64(uint64(i+j) >> 1)
		if !f(h) {
			i = h + 1
		} else {
			j = h
		}
	}
	return i
}

// https://oeis.org/A000108
func catalan(n int64) int64 {
	if n < 0 {
		return 0
	}
	return binomial(2*n, n) / (n + 1)
}

func binomial(n, k int64) int64 {
	if k < 0 || k > n {
		return 0
	}
	if k == 0 || k == n {
		return 1
	}

	k = min(k, n-k)
	c := int64(1)
	for i := int64(0); i < k; i++ {
		c = c * (n - i) / (i + 1)
	}
	return c
}

func ilog2(n int64) int64 {
	return int64(math.Log2(float64(n)))
}
