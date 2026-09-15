package main

func main() {
	assert(solve(5) == 3)
	assert(solve(8) == 22)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 4 {
		return 0
	}
	return seq(n - 4)
}

// https://oeis.org/A002623
func seq(n int) int {
	return (n + 2) * (n + 4) * (2*n + 3) / 24
}
