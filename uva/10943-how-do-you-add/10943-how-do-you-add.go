package main

func main() {
	assert(solve(20, 2) == 21)
	assert(solve(20, 2) == 21)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, k int) int {
	c := make([][]int, n+k+1)
	for i := range c {
		c[i] = make([]int, n+1)
	}

	c[0][0] = 1
	for i := 1; i <= n+k; i++ {
		c[i][0] = 1
		for j := 1; j <= n; j++ {
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % 1000000
		}
	}
	return c[n+k-1][k-1]
}
