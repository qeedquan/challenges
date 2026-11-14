package main

func main() {
	assert(solve(5, 10) == 1140)
	assert(solve(4, 1) == 42)
	assert(solve(6, 13) == 3770)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, v int) int {
	p := make([][]int, n+1)
	for i := range p {
		p[i] = make([]int, n+1)
	}

	p[n][1] = v
	for i := n; i >= 1; i-- {
		for j := 1; j <= n; j++ {
			if j == 1 && i == n {
				continue
			}

			if i >= j {
				l, r := 0, 0
				for k := i + 1; k <= n; k++ {
					l = max(p[k][1]+p[k][j], l)
				}
				for k := 1; k < j; k++ {
					r = max(p[i][k]+p[n][k], r)
				}
				p[i][j] = l + r
			} else {
				for k := i; k < j; k++ {
					p[i][j] = max(p[i][k]+p[k+1][j], p[i][j])
				}
			}
		}
	}
	return p[1][n]
}
