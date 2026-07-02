package main

func main() {
	assert(solve(817, 0) == "1")
	assert(solve(2, 2) == "4")
	assert(solve(0, -1) == "2")
	assert(solve(18, 92) == "TOO COMPLICATED")
	assert(solve(-7, 7) == "4")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int64) string {
	if b == 0 {
		return "1"
	}

	if 2*a*b == 0 {
		return "2"
	}

	if a*b*(a*a-b*b) != 0 {
		return "TOO COMPLICATED"
	}

	c := a*a - b*b
	ab := 2 * a * b
	if c*c-ab*ab <= 1<<30 {
		return "4"
	}
	return "TOO COMPLICATED"
}
