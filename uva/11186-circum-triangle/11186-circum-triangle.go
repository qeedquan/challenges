package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	fmt.Printf("%.0f\n", solve([]float64{10.00, 100.00, 300.00, 310.00, 320.00}, 10))
	fmt.Printf("%.0f\n", solve([]float64{10.00, 100.00, 300.00}, 20))
}

func solve(theta []float64, R float64) float64 {
	N := len(theta)
	if N < 3 {
		return 0
	}

	for i := range theta {
		theta[i] = deg2rad(theta[i])
	}
	sort.Float64s(theta)

	r := 0.0
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			a := float64(j - i - 1)
			b := float64(N) - a - 2
			t := theta[j] - theta[i]
			A := t/2*R*R - R*R*math.Sin(t)/2
			B := R*R*math.Pi - A
			r += a*B + b*A
		}
	}
	return float64(N*(N-1)*(N-2))/6*R*R*math.Pi - r
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
