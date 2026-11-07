package main

import "fmt"

func main() {
	assert(solve(3, 1, 2) == "0")
	assert(solve(2, 5, 2) == "15/16")
	assert(solve(3, 5, 3) == "50/81")
	assert(solve(4, 6, 2) == "93/1024")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(N, M, K int) string {
	p := make([][]int, M+1)
	for i := range p {
		p[i] = make([]int, K+1)
	}
	p[0][0] = 1

	a, b := 0, 1
	for i := 1; i <= M; i++ {
		for j := 1; j <= min(i, K); j++ {
			p[i][j] = p[i-1][j]*j + p[i-1][j-1]*(N-(j-1))
		}
		b *= N
	}
	a = p[M][K]

	m := gcd(a, b)
	a /= m
	b /= m

	if a%b == 0 {
		return fmt.Sprintf("%d", a/b)
	}
	return fmt.Sprintf("%d/%d", a, b)
}

func gcd(a, b int) int {
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}
