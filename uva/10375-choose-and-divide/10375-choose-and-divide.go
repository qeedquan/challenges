package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(10, 5, 14, 9))
	fmt.Println(solve(93, 45, 84, 59))
	fmt.Println(solve(145, 95, 143, 92))
	fmt.Println(solve(995, 487, 996, 488))
	fmt.Println(solve(2000, 1000, 1999, 999))
	fmt.Println(solve(9998, 4999, 9996, 4998))
}

func solve(p, q, r, s int) float64 {
	if p-q < q {
		q = p - q
	}
	if r-s < s {
		s = r - s
	}

	v := 0.0
	for i := 1; i <= q; i++ {
		v += log(p-q+i) - log(i)
	}
	for i := 1; i <= s; i++ {
		v += -log(r-s+i) + log(i)
	}
	return math.Exp(v)
}

func log(x int) float64 {
	return math.Log(float64(x))
}
