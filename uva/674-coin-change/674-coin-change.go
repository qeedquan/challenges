package main

func main() {
	tab := []int{
		1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 6, 6, 6, 6, 6, 9, 9, 9, 9,
		9, 13, 13, 13, 13, 13, 18, 18, 18, 18, 18, 24, 24, 24, 24, 24, 31, 31,
		31, 31, 31, 39, 39, 39, 39, 39, 50, 50, 50, 50, 50, 62, 62, 62, 62, 62,
		77, 77, 77,
	}

	assert(solve(11) == 4)
	assert(solve(26) == 13)

	for i := range tab {
		assert(solve(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A001300
func solve(n int) int {
	if n < 0 {
		return 0
	}

	c := []int{1, 5, 10, 25, 50}
	p := make([]int, n+1)
	p[0] = 1
	for i := range c {
		for j := c[i]; j < len(p); j++ {
			p[j] += p[j-c[i]]
		}
	}
	return p[n]
}
