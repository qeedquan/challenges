package main

func main() {
	tab := []int{
		1, 1, 2, 6, 6, 3, 9, 9, 9, 27, 27, 36, 27, 27, 45, 45, 63, 63, 54, 45,
		54, 63, 72, 99, 81, 72, 81, 108, 90, 126, 117, 135, 108, 144, 144, 144,
		171, 153, 108, 189, 189, 144, 189, 180, 216, 207, 216, 225, 234, 225,
		216, 198, 279, 279, 261, 279, 333, 270, 288,
	}

	assert(solve(5) == 3)
	assert(solve(60) == 288)
	assert(solve(100) == 648)

	for i := range len(tab) {
		assert(solve(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A004152
func solve(n int) int {
	if n < 0 {
		return 0
	}

	r := make([]int, n+2)
	p := make([][]int, n+2)
	for i := range p {
		p[i] = make([]int, (n+2)*(n+2))
	}

	p[0][0] = 1
	p[1][0] = 1
	r[0] = 1
	r[1] = 1
	l := 0
	for i := 2; i <= n; i++ {
		for j := 0; j <= l; j++ {
			p[i][j] += p[i-1][j] * i
			if p[i][j] >= 10 {
				p[i][j+1] += p[i][j] / 10
				p[i][j] %= 10
				if j+1 > l {
					l = j + 1
				}
			}
			r[i] += p[i][j]
		}
	}
	return r[n]
}
