package main

import (
	"fmt"
	"math"
)

func main() {
	test(50, 12, 0.1476651)
	test(100, 3, 0.0000000)
	test(100, 12, 0.0019960)
	test(32, 7, 0.0500009)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, m int, r float64) {
	p := solve(n, m)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-7)
}

func solve(n, m int) float64 {
	p := make([][]float64, n+1)
	for i := range p {
		p[i] = make([]float64, m+1)
	}

	p[0][0] = 1
	for i := 1; i <= n; i++ {
		for j := 0; j <= m; j++ {
			if m == 0 {
				m = 1
			}
			if m != j {
				p[i][j] += p[i-1][j] * float64(m-j) / float64(m)
			}
			if j >= 1 {
				p[i][j] += p[i-1][j-1] * float64(j) / float64(m)
			}
		}
	}
	return 1 - p[n][m]
}
