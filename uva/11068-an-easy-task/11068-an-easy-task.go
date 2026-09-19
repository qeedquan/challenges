package main

import "fmt"

func main() {
	fmt.Println(solve(1, 2, 1, 1, 1, 1))
	fmt.Println(solve(1, 1, 3, 1, 1, 4))
	fmt.Println(solve(1, 2, 3, 3, 2, 1))
	fmt.Println(solve(10, 2, 3, 14, 7, 5))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, c, d, e, f int) string {
	den := a*e - b*d
	if den == 0 {
		return "No fixed point exists."
	}

	x1 := float64(c*e-b*f) / float64(den)
	x2 := float64(a*f-c*d) / float64(den)
	return fmt.Sprintf("The fixed point is at %.2f %.2f.", x1, x2)
}
