package main

import (
	"math"
)

func main() {
	assert(solve(3) == 2)
	assert(solve(4) == 5)
	assert(solve(5) == 2)
	assert(solve(6) == 4)
	assert(solve(7) == 3)
	assert(solve(8) == 11)
	assert(solve(9) == 2)
	assert(solve(10) == 3)
	assert(solve(11) == 8)
	assert(solve(12) == 16)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A187788
func solve(n int) int {
	if n < 1 {
		return 0
	}

	for c := 2; c < math.MaxInt; c++ {
		if calc(n, c) != 0 {
			return c
		}
	}
	return -1
}

func calc(n, k int) int {
	link := make([]int, n+2)
	for i := 2; i < n; i++ {
		link[i] = i + 1
	}
	link[n] = 2

	head := 2
	prev := n
	last := 0
	for i := 1; i < n; i++ {
		for j := 1; j < k; j++ {
			prev = head
			head = link[head]
		}
		last = head
		link[prev] = link[head]
		head = link[head]
	}

	if last == 2 {
		return 1
	}
	return 0
}
