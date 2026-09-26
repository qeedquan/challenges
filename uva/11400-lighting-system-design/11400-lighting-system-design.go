package main

import (
	"math"
	"sort"
)

func main() {
	assert(cost([]Category{
		{100, 500, 10, 20},
		{120, 600, 8, 16},
		{220, 400, 7, 18},
	}) == 778)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cost(a []Category) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i].v < a[j].v
	})

	s := make([]int, n+1)
	p := make([]int, n+1)
	for i := 1; i <= n; i++ {
		s[i] += s[i-1] + a[i-1].l
	}

	p[1] = a[0].k + a[0].c*a[0].l
	for i := 2; i <= n; i++ {
		p[i] = math.MaxInt
		for j := 0; j < i; j++ {
			p[i] = min(p[i], p[j]+(s[i]-s[j])*a[i-1].c+a[i-1].k)
		}
	}
	return p[n]
}

type Category struct {
	v, k, c, l int
}
