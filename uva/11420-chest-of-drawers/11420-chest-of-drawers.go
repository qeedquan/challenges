package main

func main() {
	assert(solve(6, 2) == 16)
	assert(solve(6, 3) == 9)
	assert(solve(6, 4) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, s int) int {
	p := make([][][2]int, n+1)
	for i := range p {
		p[i] = make([][2]int, n+1)
	}

	p[1][1][1] = 1
	p[1][0][0] = 1
	for i := 2; i <= n; i++ {
		for j := 0; j <= i; j++ {
			p[i][j][0] = p[i-1][j][0] + p[i-1][j][1]
			p[i][j][1] = p[i-1][j][0]
			if j > 0 {
				p[i][j][1] += p[i-1][j-1][1]
			}
		}
	}
	return p[n][s][0] + p[n][s][1]
}
