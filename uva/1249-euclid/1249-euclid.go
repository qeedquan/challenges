package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func main() {
	fmt.Println(solve(
		Point{0, 0},
		Point{5, 0},
		Point{0, 5},
		Point{3, 2},
		Point{7, 2},
		Point{0, 4},
	))

	fmt.Println(solve(
		Point{1.3, 2.6},
		Point{12.1, 4.5},
		Point{8.1, 13.7},
		Point{2.2, 0.1},
		Point{9.8, 6.6},
		Point{1.9, 6.7},
	))
}

func solve(A, B, C, D, E, F Point) (G, H Point) {
	areaDEF := math.Abs(wedge(D, E, F) / 2)
	areaABC := math.Abs(wedge(A, B, C) / 2)
	distAB := distance(A, B)
	distAC := distance(A, C)
	sintheta := areaABC * 2 / (distAB * distAC)
	distAH := areaDEF / (sintheta * distAB)
	H.x = A.x + (C.x-A.x)*distAH/distAC
	H.y = A.y + (C.y-A.y)*distAH/distAC
	G.x = H.x + (B.x - A.x)
	G.y = H.y + (B.y - A.y)
	return
}

func wedge(o, a, b Point) float64 {
	return ((a.x - o.x) * (b.y - o.y)) - ((a.y - o.y) * (b.x - o.x))
}

func distance(a, b Point) float64 {
	return math.Hypot(a.x-b.x, a.y-b.y)
}
