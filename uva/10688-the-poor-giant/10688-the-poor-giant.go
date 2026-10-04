package main

import "math"

func main() {
	assert(solve(2, 0) == 2)
	assert(solve(3, 0) == 6)
	assert(solve(4, 0) == 13)
	assert(solve(5, 0) == 22)
	assert(solve(10, 20) == 605)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, k int) int {
	return dfs(n, k, make(map[[2]int]int))
}

func dfs(n, k int, m map[[2]int]int) int {
	if n <= 1 {
		return 0
	}

	x := [2]int{n, k}
	if v, f := m[x]; f {
		return v
	}

	v := math.MaxInt
	for i := 1; i <= n; i++ {
		t := n*(k+i) + dfs(i-1, k, m) + dfs(n-i, k+i, m)
		v = min(v, t)
	}
	m[x] = v
	return v
}
