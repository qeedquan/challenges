package main

import "fmt"

func main() {
	fmt.Println(solve(4, 4, 5, 5))
	fmt.Println(solve(9, 0, 10, 0))
}

func solve(x1, y1, x2, y2 int) (int, int, int, int) {
	vx := y1 - y2
	vy := x2 - x1
	s := max(max(x1, x2), max(y1, y2))
	if vx < 0 || (vx == 0 && vy < 0) {
		vx = -vx
		vy = -vy
	}
	if vx >= 0 && vy >= 0 {
		return 0, 0, vx, vy
	}
	return 0, s, vx, s + vy
}
