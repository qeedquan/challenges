package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(100, 100, 1, 1, 1))
	fmt.Println(solve(200, 100, 5, 3, 4))
	fmt.Println(solve(201, 132, 48, 1900, 156))
}

func solve(a, b, s, m, n int) (float64, float64) {
	H := float64(n*b) / float64(s)
	V := float64(m*a) / float64(s)
	L := math.Hypot(H, V)
	T := math.Acos((V*V + L*L - H*H) / (2 * V * L))
	return rad2deg(T), L
}

func rad2deg(x float64) float64 {
	return x * 180 / math.Pi
}
