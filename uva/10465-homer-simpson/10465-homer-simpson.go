package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(3, 5, 54))
	fmt.Println(solve(3, 5, 55))
}

func solve(n, m, t int) (int, int) {
	a2 := 0
	t2 := math.MaxInt
	for i := t / n; i >= 0; i-- {
		ta2 := i + (t-n*i)/m
		tt2 := t - n*i - (t-n*i)/m*m
		if tt2 < t2 || (tt2 == t2 && ta2 > a2) {
			t2 = tt2
			a2 = ta2
		}
	}
	return a2, t2
}
