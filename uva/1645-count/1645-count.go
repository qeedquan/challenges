package main

func main() {
	tab := []int{
		1, 1, 2, 3, 5, 6, 10, 11, 16, 19, 26, 27, 40, 41, 53, 61, 77, 78, 104,
		105, 134, 147, 175, 176, 227, 233, 275, 294, 350, 351, 438, 439, 516,
		545, 624, 640, 774, 775, 881, 924, 1069, 1070, 1265, 1266, 1444, 1521,
		1698, 1699,
	}

	assert(solve(1) == 1)
	assert(solve(2) == 1)
	assert(solve(3) == 2)
	assert(solve(40) == 924)
	assert(solve(50) == 1998)
	assert(solve(600) == 315478277)
	assert(solve(700) == 825219749)

	for i := range tab {
		assert(solve(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A003238
func solve(n int) int {
	const mod = 1000000007

	if n < 0 {
		return 0
	}

	p := make([]int, n+2)
	p[1] = 1
	for i := 1; i <= n; i++ {
		for j := 1; i*j <= n; j++ {
			p[i*j+1] = (p[i*j+1] + p[i]) % mod
		}
	}
	return p[n]
}
