package main

import "fmt"

func main() {
	assert(solve(10, 2, 3, 3, 2) == "After 3 jumps the flea lands at (11, 9).")
	assert(solve(100, 49, 73, 214, 38) == "After 1 jumps the flea lands at (263, 111).")
	assert(solve(25, 0, 0, 5, 25) == "The flea cannot escape from black squares.")
	assert(solve(407, 1270, 1323, 1, 1) == "After 306 jumps the flea lands at (1576, 1629).")
	assert(solve(18, 72, 6, 18, 6) == "The flea cannot escape from black squares.")
	assert(solve(407, 1270, 1170, 100, 114) == "After 0 jumps the flea lands at (1270, 1170).")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s, x, y, dx, dy int) string {
	if s < 1 || dx < 1 || dy < 1 {
		return "The flea cannot escape from black squares."
	}

	c := 0
	for {
		if c > 2*s {
			return "The flea cannot escape from black squares."
		}

		cx := x / s
		cy := y / s
		rx := x % s
		ry := y % s
		if (cx+cy)%2 == 1 && rx != 0 && ry != 0 {
			return fmt.Sprintf("After %d jumps the flea lands at (%d, %d).", c, x, y)
		}

		x += dx
		y += dy
		c += 1
	}
}
