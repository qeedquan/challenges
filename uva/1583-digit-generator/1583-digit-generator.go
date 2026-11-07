package main

func main() {
	assert(solve(256) == 245)
	assert(solve(216) == 198)
	assert(solve(121) == 0)
	assert(solve(2005) == 1979)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A096234 (related)
func solve(n int) int {
	if n == 0 {
		return 0
	}
	for i := range n {
		if i+digsum(i) == n {
			return i
		}
	}
	return 0
}

func digsum(n int) int {
	r := 0
	for ; n > 0; n /= 10 {
		r += n % 10
	}
	return r
}
