package main

func main() {
	assert(solve(3, 8) == 33)
	assert(solve(5, 18) == 80)
	assert(solve(1, 50) == 330)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(m, n int64) int64 {
	return calc(n, 1, 1) - calc(m-1, 1, 1)
}

func calc(n, d, l int64) int64 {
	if n < 1 {
		return 0
	}

	m := n % 10
	return n/10*45*d + m*l + m*(m-1)/2*d + calc(n/10, d*10, l+m*d)
}
