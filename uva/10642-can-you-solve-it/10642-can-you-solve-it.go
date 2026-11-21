package main

func main() {
	assert(solve(0, 0, 0, 1) == 1)
	assert(solve(0, 0, 1, 0) == 2)
	assert(solve(0, 0, 0, 2) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x1, y1, x2, y2 int64) int64 {
	return abs(L(x1, y1) - L(x2, y2))
}

func L(x, y int64) int64 {
	r := y * (y + 1) / 2
	r += (2*(2+y) + x - 1) * x / 2
	return r
}

func abs(x int64) int64 {
	if x < 0 {
		x = -x
	}
	return x
}
