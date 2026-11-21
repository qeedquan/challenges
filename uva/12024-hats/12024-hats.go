package main

import "fmt"

func main() {
	assert(solve(2) == "1/2")
	assert(solve(3) == "2/6")
	assert(solve(4) == "9/24")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) string {
	if n < 0 {
		return ""
	}

	N := make([]int, n+3)
	P := make([]int, n+3)

	N[0], N[1], N[2] = 0, 0, 1
	P[0], P[1], P[2] = 1, 1, 2
	for i := 3; i <= n; i++ {
		N[i] = N[i-1] * i
		P[i] = P[i-1] * i
		if i%2 == 0 {
			N[i] += 1
		} else {
			N[i] -= 1
		}
	}
	return fmt.Sprintf("%d/%d", N[n], P[n])
}
