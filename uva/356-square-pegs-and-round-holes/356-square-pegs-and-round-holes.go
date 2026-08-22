package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(3))
	fmt.Println(solve(4))
	for i := range 1000 {
		r1, r2 := solve(i)
		r3, r4 := solvebf(i)
		assert(r1 == r3)
		assert(r2 == r4)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A136486
// https://oeis.org/A017113
func solve(n int) (int, int) {
	if n < 1 {
		return 0, 0
	}

	n -= 1
	r := 0.0
	for k := 1; k <= n; k++ {
		x := float64(n) + 0.5
		y := float64(k)
		r += math.Floor(math.Sqrt(x*x - y*y))
	}
	return 4 * int(r), 8*n + 4
}

func solvebf(n int) (int, int) {
	t1 := 0
	t2 := 0
	r := float64(n) - 0.5
	for i := range n {
		for j := range n {
			r1 := math.Sqrt(float64(i*i + j*j))
			r2 := math.Sqrt(float64(i*i + j*j + 2*i + 2*j + 2))
			if r1 <= r && r2 <= r {
				t1++
			}
			if r1 <= r && r2 > r {
				t2++
			}
		}
	}
	return t1 * 4, t2 * 4
}
