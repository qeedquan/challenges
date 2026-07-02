package main

import "fmt"

func main() {
	fmt.Println(solve(1, 1, 2, 2, [][2]float64{{1.5, 1.5}}))
	fmt.Println(solve(2, 2, 1, 1, [][2]float64{{1.5, 1.5}, {2.5, 2.5}}))
}

func solve(x1, y1, x2, y2 float64, p [][2]float64) string {
	for _, p := range p {
		x, y := p[0], p[1]
		if 4*((x1-x)*(x1-x)+(y1-y)*(y1-y)) <= (x2-x)*(x2-x)+(y2-y)*(y2-y) {
			return fmt.Sprintf("The gopher can escape through the hole at (%.3f,%.3f).", x, y)
		}
	}
	return "The gopher cannot escape."
}
