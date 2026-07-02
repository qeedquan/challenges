package main

import "sort"

func main() {
	assert(solve(2, 20, 5, []int{10, 15}, []int{10, 15}) == 50)
	assert(solve(2, 20, 5, []int{10, 10}, []int{10, 10}) == 0)
}

func assert(x bool) {
	if !x {
		panic("Assertion failed")
	}
}

func solve(n, d, r int, a, b []int) int {
	sort.Ints(a)
	sort.Ints(b)
	sum := 0
	for i := range n {
		if a[i]+b[n-i-1] > d {
			sum += (a[i] + b[n-i-1] - d) * r
		}
	}
	return sum
}
