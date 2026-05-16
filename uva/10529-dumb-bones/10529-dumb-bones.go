package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.2f\n", solve(10, 0.25, 0.25))
	fmt.Printf("%.2f\n", solve(10, 0.1, 0.4))
	fmt.Printf("%.2f\n", solve(10, 0.0, 0.5))
}

func solve(n int, pl, pr float64) float64 {
	p := make([]float64, n+1)
	p[1] = 1 / (1 - pl - pr)
	for i := 2; i <= n; i++ {
		p[i] = math.MaxFloat64
		for j := 0; j <= i; j++ {
			l := j
			r := max(i-j-1, 0)
			p[i] = min(p[i], p[l]+p[r]+(1+p[l]*pl+p[r]*pr)/(1-pl-pr))
		}
	}
	return p[n]
}
