package main

func main() {
	assert(solve(3, 0) == 1)
	assert(solve(3, 1) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, k int) int {
	const mod = 1000000007

	if n < 0 || k < 0 {
		return 0
	}

	p := make([][]int, n+2)
	for i := range p {
		p[i] = make([]int, k+2)
	}

	p[1][0] = 1
	for i := 1; i <= n; i++ {
		for j := 0; j <= k; j++ {
			p[i+1][j] = (p[i+1][j] + p[i][j]*(j+1)) % mod
			p[i+1][j+1] = (p[i+1][j+1] + p[i][j]*(i-j)) % mod
		}
	}
	return p[n][k]
}
