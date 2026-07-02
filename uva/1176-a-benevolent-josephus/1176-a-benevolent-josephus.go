package main

func main() {
	assert(solve(5) == 8)
	assert(solve(10) == 13)
	assert(solve(7) == 14)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 1 {
		return 0
	}

	J := make([]int, n+1)
	D := make([]int, n+1)
	for i := 2; i <= n; i++ {
		J[i] = (J[i-1] + 2) % i
	}
	for i := 1; i <= n; i++ {
		J[i] = J[i] + 1
		if J[i] == i {
			D[i] = 2 * i
		} else {
			D[i] = i - J[i] + D[J[i]]
		}
	}
	return D[n]
}
