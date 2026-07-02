package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(8))
	fmt.Println(solve(15))
	fmt.Println(solve(35))
}

func solve(s int) (int, int, int) {
	if s < 1 {
		return 0, 0, 0
	}

	x := 0
	n := isqrt(2 * s)
	for ; n > 0; n-- {
		if (2*s+n-n*n)%(2*n) == 0 {
			x = (2*s + n - n*n) / (2 * n)
			break
		}
	}
	return s, x, x + n - 1
}

func isqrt(x int) int {
	return int(math.Sqrt(float64(x)))
}
