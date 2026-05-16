package main

import "fmt"

func main() {
	fmt.Println(solve(1, 2, 3))
	fmt.Println(solve(6, 6, 14))
}

func solve(A, B, C int) (int, int, int) {
	n := B
	if B == 0 {
		n = A
	}

	for x := -n; x <= n; x++ {
		for y := x + 1; y <= n; y++ {
			z := A - x - y
			if y >= z {
				continue
			}
			if x+y+z == A && x*x+y*y+z*z == C && x*y*z == B {
				return x, y, z
			}
		}
	}
	return -1, -1, -1
}
