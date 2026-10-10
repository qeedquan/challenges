package main

func main() {
	assert(solve(0, 30, 0, 30) == 1350)
	assert(solve(5, 35, 5, 35) == 1350)
	assert(solve(0, 20, 0, 20) == 1620)
	assert(solve(7, 27, 7, 27) == 1620)
	assert(solve(0, 10, 0, 10) == 1890)
	assert(solve(9, 19, 9, 19) == 1890)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(init, c1, c2, c3 int) int {
	r := 1080
	r += (init - c1 + offset(init-c1)) * 9
	r += (c2 - c1 + offset(c2-c1)) * 9
	r += (c2 - c3 + offset(c2-c3)) * 9
	return r
}

func offset(x int) int {
	if x > 0 {
		return 0
	}
	return 40
}
