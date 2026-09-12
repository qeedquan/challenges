package main

import "fmt"

type Point struct {
	x, y int
}

func main() {
	fmt.Println(solve(
		Point{10, 10},
		Point{20, 20},
		Point{15, 15},
		Point{25, 25},
	))

	fmt.Println(solve(
		Point{10, 10},
		Point{20, 20},
		Point{20, 20},
		Point{30, 30},
	))
}

func solve(a, b, c, d Point) (int, int, int) {
	i := max(a.x, c.x)
	j := max(a.y, c.y)
	k := min(b.x, d.x)
	l := min(b.y, d.y)
	A := (b.x - a.x) * (b.y - a.y)
	B := (d.x - c.x) * (d.y - c.y)
	C := (i - k) * (j - l)
	if i >= k || j >= l {
		return 0, A + B, 10000 - A - B
	}
	return C, A + B - C - C, 10000 - A - B + C
}
