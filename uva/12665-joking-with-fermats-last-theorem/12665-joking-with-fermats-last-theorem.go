package main

func main() {
	assert(solve(1, 10) == 0)
	assert(solve(1, 20) == 2)
	assert(solve(123, 456789) == 16)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(L, R int) int {
	V := 0
	N := min(1005, R)
	for A := L; A <= N; A++ {
		for B := L; B <= N; B++ {
			T := (A*A*A + B*B*B)
			C := T / 10
			if T%10 == 3 && (L <= C && C <= R) {
				V += 1
			}
		}
	}
	return V
}
