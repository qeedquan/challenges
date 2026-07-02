package main

func main() {
	assert(solve(9, 0, 3) == 4)
	assert(solve(5, 5, 2) == 9)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(e, f, c int) int {
	if c == 0 {
		return 0
	}

	r := 0
	s := e + f
	for s/c > 0 {
		r = r + s/c
		s = s/c + s%c
	}
	return r
}
