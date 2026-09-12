package main

func main() {
	assert(solve(12, 4, 3, 2) == 3)
	assert(solve(9, 4, 2, 7) == 4)
	assert(solve(13, 4, 3, 1) == 4)
	assert(solve(13, 4, 3, 50) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(E, P, K, R int64) int64 {
	if P*K <= R {
		T := (E + P - 1) / P
		if T <= K {
			return T
		}
		return -1
	}

	RT := P*K - R
	U := max((E-P*K)/RT, 0)
	V := U * K
	E -= U * RT
	for E > P*K {
		V += K
		E -= RT
	}
	V += (E + P - 1) / P
	return V
}
