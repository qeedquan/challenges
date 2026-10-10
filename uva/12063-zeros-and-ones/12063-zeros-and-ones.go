package main

func main() {
	assert(solve(6, 3) == 1)
	assert(solve(6, 4) == 3)
	assert(solve(6, 2) == 6)
	assert(solve(26, 3) == 1662453)
	assert(solve(64, 2) == 465428353255261088)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, k int64) int64 {
	if n < 1 || k < 1 || n%2 != 0 {
		return 0
	}

	p := make([][][]int64, n+1)
	for i := range p {
		p[i] = make([][]int64, n+1)
		for j := range p[i] {
			p[i][j] = make([]int64, k+1)
		}
	}

	n /= 2
	p[0][1][1%k] = 1
	for i := int64(0); i <= n; i++ {
		for j := int64(0); j <= n; j++ {
			for h := int64(0); h < k; h++ {
				p[i][j+1][((h<<1)+1)%k] += p[i][j][h]
				p[i+1][j][(h<<1)%k] += p[i][j][h]
			}
		}
	}
	return p[n][n][0]
}
