package main

import (
	"sort"
)

func main() {
	assert(solve([]int{3, 2, 1}) == 4)
	assert(solve([]int{8, 1, 2, 4}) == 17)
	assert(solve([]int{1, 8, 9, 7, 6}) == 41)
	assert(solve([]int{8, 4, 5, 3, 2, 7}) == 34)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://isolvedaproblem.blogspot.com/2012/02/silly-sort.html
func solve(a []int) int {
	n := len(a)
	v := make(map[int]bool)
	b := make([]int, n)
	for i := range n {
		b[i] = a[i]
	}
	sort.Ints(b)

	p := make(map[int]int)
	for i := range n {
		p[b[i]] = i
	}

	r := 0
	for i := range n {
		if v[i] {
			continue
		}

		if p[a[i]] == i {
			v[i] = true
			continue
		}

		m := a[i]
		x := 0
		s := 0
		j := i
		for v[j] == false {
			s += a[j]
			x += 1
			if a[j] < m {
				m = a[j]
			}
			v[j], j = true, p[a[j]]
		}
		s -= m
		r += s + m*(x-1)

		if 2*(b[0]+m) < (m-b[0])*(x-1) {
			r -= (m-b[0])*(x-1) - 2*(b[0]+m)
		}
	}
	return r
}
