package main

func main() {
	assert(solve(2, 100) == 14)
	assert(solve(10, 786599) == 21)
	assert(solve(4, 786599) == "More than 63 trials needed.")
	assert(solve(60, 1844674407370955161) == 61)
	assert(solve(63, 9223372036854775807) == 63)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(k, n uint64) any {
	p := make([][64]uint64, k+1)
	for i := uint64(1); i <= k; i++ {
		for j := 1; j < 64; j++ {
			if j == 1 {
				p[i][j] = 1
			} else {
				p[i][j] = p[i-1][j-1] + p[i][j-1] + 1
			}
		}
	}

	i := 1
	for ; i < 64; i++ {
		if p[k][i] >= n {
			break
		}
	}

	if i > 63 {
		return "More than 63 trials needed."
	}
	return i
}
