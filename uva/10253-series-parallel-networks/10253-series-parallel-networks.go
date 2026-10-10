package main

func main() {
	tab := []int64{
		1, 2, 4, 10, 24, 66, 180, 522, 1532, 4624, 14136, 43930, 137908, 437502,
		1399068, 4507352, 14611576, 47633486, 156047204, 513477502, 1696305728,
		5623993944, 18706733128, 62408176762, 208769240140, 700129713630,
		2353386723912,
	}

	assert(solve(1) == 1)
	assert(solve(4) == 10)
	assert(solve(15) == 1399068)
	for i := range tab {
		assert(solve(int64(i+1)) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A000084
func solve(n int64) int64 {
	if n < 1 {
		return 0
	}
	if n == 1 {
		return 1
	}

	r := make([]int64, n+2)
	p := make([][]int64, n+2)
	for i := range p {
		p[i] = make([]int64, n+2)
	}

	r[1] = 1
	for i := int64(1); i <= n; i++ {
		p[0][i] = 0
		p[i][1] = 1
	}
	for i := int64(0); i <= n; i++ {
		p[i][0] = 1
	}
	for i := int64(1); i <= n; i++ {
		for j := int64(2); j <= n; j++ {
			for k := int64(0); i*k <= j; k++ {
				p[i][j] += binomial(r[i]+k-1, k) * p[i-1][j-i*k]
			}
		}
		r[i+1] = p[i][i+1]
	}
	return r[n] * 2
}

func binomial(n, m int64) int64 {
	r := int64(1)
	m = min(m, n-m)
	for i := int64(1); i <= m; i++ {
		r = r * (n + 1 - i) / i
	}
	return r
}
