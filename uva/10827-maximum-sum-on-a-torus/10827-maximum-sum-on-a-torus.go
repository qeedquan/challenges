package main

import "math"

func main() {
	assert(solve([][]int{
		{1, -1, 0, 0, -4},
		{2, 3, -2, -3, 2},
		{4, 1, -1, 5, 0},
		{3, -2, 1, -3, 2},
		{-3, 2, 4, 1, -4},
	}) == 15)

	assert(solve([][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}) == 45)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(m [][]int) int {
	n := len(m)
	p := make([][]int, n*2+1)
	for i := range p {
		p[i] = make([]int, n*2+1)
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			p[i][j] = m[i-1][j-1]
			p[i][j+n], p[i+n][j], p[i+n][j+n] = p[i][j], p[i][j], p[i][j]
		}
	}

	for i := 1; i <= 2*n; i++ {
		for j := 1; j <= 2*n; j++ {
			p[i][j] += (p[i][j-1] + p[i-1][j] - p[i-1][j-1])
		}
	}

	r := math.MinInt
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			for k := i; k < i+n; k++ {
				for l := j; l < j+n; l++ {
					r = max(r, p[k][l]-p[i-1][l]-p[k][j-1]+p[i-1][j-1])
				}
			}
		}
	}
	return r
}
