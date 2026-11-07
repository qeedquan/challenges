package main

import (
	"fmt"
	"math"
	"math/cmplx"
)

func main() {
	solve(3+4i, 2)
	solve(5-4i, 3)
}

// https://en.wikipedia.org/wiki/De_Moivre%27s_formula
// https://math.libretexts.org/Courses/Rio_Hondo/Math_175%3A_Plane_Trigonometry/06%3A_The_Polar_System/6.05%3A_De_Moivre's_and_the_nth_Root_Theorem
func solve(z complex128, n int) {
	m := float64(n)
	r := math.Pow(cmplx.Abs(z), 1/m)
	t := cmplx.Phase(z) / m
	for k := range n {
		p := 2 * math.Pi * float64(k) / m
		x := r * math.Cos(t+p)
		y := r * math.Sin(t+p)
		fmt.Printf("%.3f%+.3fi\n", x, y)
	}
	fmt.Println()
}
