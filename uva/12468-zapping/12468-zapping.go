package main

func main() {
	assert(solve(3, 9) == 6)
	assert(solve(0, 99) == 1)
	assert(solve(12, 27) == 15)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int) int {
	return min(abs(a-b), 100-a+b, 100-b+a)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
