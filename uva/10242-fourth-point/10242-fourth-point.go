package main

import "fmt"

func main() {
	fmt.Println(solve(0.000, 0.000, 0.000, 1.000, 0.000, 1.000, 1.000, 1.000))
	fmt.Println(solve(1.000, 0.000, 3.500, 3.500, 3.500, 3.500, 0.000, 1.000))
	fmt.Println(solve(1.866, 0.000, 3.127, 3.543, 3.127, 3.543, 1.412, 3.145))
}

func solve(x1, y1, x2, y2, x3, y3, x4, y4 float64) (float64, float64) {
	if x1 == x3 && y1 == y3 {
		return (x2 + x4) - x1, (y2 + y4) - y1
	}
	if x1 == x4 && y1 == y4 {
		return (x2 + x3) - x1, (y2 + y3) - y1
	}
	if x2 == x3 && y2 == y3 {
		return (x1 + x4) - x2, (y1 + y4) - y2
	}
	return (x1 + x3) - x2, (y1 + y3) - y2
}
