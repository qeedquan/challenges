package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(1, 10, 5, 2.0))
	fmt.Println(solve(1, 5, 10.0, 2))
	fmt.Println(solve(2, 10, 11, 2))
	fmt.Println(solve(3, 5, 1, 6))
	fmt.Println(solve(4, 5.0, -1, 6))
}

func solve(n int, x1, x2, x3 float64) (float64, float64) {
	var u, v, a, s, t float64
	switch n {
	case 1:
		u, v, t = x1, x2, x3
		a = (v - u) / t
		s = (u + v) * t / 2
		return s, a

	case 2:
		u, v, a = x1, x2, x3
		t = (v - u) / a
		s = (u + v) * t / 2
		return s, t

	case 3:
		u, a, s = x1, x2, x3
		v = math.Sqrt(u*u + 2*a*s)
		t = (v - u) / a
		return v, t

	default:
		v, a, s = x1, x2, x3
		u = math.Sqrt(v*v - 2*a*s)
		t = (v - u) / a
		return u, t
	}
}
