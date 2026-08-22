package main

func main() {
	assert(solve(1) == 1)
	assert(solve(3) == 5)
	assert(solve(7) == 25)
	assert(solve(11) == 61)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A001844 (related)
func solve(n int) int {
	m := (n + 1) / 2
	r := (2 + (m-1)*2) * m / 2
	r += (2 + (m-2)*2) * (m - 1) / 2
	return r
}
