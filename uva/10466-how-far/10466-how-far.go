package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func main() {
	solve([]Point{
		{20, 5},
		{30, 5},
		{40, 5},
	}, 5)
}

func solve(p []Point, T float64) {
	x, y := 0.0, 0.0
	for _, p := range p {
		r, t := p.x, p.y
		a := 2 * math.Pi * T / t
		x += r * math.Cos(a)
		y += r * math.Sin(a)
		fmt.Printf("% .4f", math.Hypot(x, y))
	}
	fmt.Println()
}
