package main

func main() {
	assert(solve(2, 1) == 21)
	assert(solve(6, 5) == 31654)
	assert(solve(100, 2) == 5306431377)
	assert(solve(19, 78) == 1942584859)
	assert(solve(1000, 1000) == 4124225148)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(A, B int64) int64 {
	return dfs(A, B, make(map[[2]int64]int64))
}

func dfs(u, v int64, m map[[2]int64]int64) int64 {
	const mod = 9999959999

	if u < 0 || v < 0 {
		return 0
	}
	if u == 0 && v == 0 {
		return 1
	}

	k := [2]int64{u, v}
	if r, f := m[k]; f {
		return r
	}

	r := int64(1)
	if u > 0 {
		r += dfs(u-1, v+1, m)
	}
	if v > 0 {
		r += dfs(u, v-1, m)
	}
	r %= mod

	m[k] = r
	return r
}
