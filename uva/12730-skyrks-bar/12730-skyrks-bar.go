package main

import "fmt"

func main() {
	fmt.Printf("%.4f\n", solve(4, 2))
	fmt.Printf("%.4f\n", solve(7, 2))
	fmt.Printf("%.4f\n", solve(10, 3))
}

func solve(n, m int) float64 {
	p := make([]float64, n+1)
	s := make([]float64, n+1)
	for i := 1; i <= n; i++ {
		if i <= m {
			p[i] = 1
		} else {
			p[i] = 1 + s[i-m-1]*2.0/float64(i)
		}
		s[i] = s[i-1] + p[i]
	}
	return p[n]
}
