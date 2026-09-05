package main

import (
	"math"
)

func main() {
	assert(solve(17) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 13 {
		return 0
	}

	if n == 13 {
		return 1
	}

	for k := 2; k < math.MaxInt; k++ {
		if calc(n, k) != 0 {
			return k
		}
	}
	return -1
}

func calc(n, k int) int {
	link := make([]int, n+1)
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
	if last == 13 {
		return 1
	}
	return 0
}
