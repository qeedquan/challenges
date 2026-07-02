package main

func main() {
	assert(solve(2) == 0)
	assert(solve(100) == 3150)
	assert(solve(200000000) == 12898681201837053)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int64) int64 {
	v := int64(0)
	for r := n; r > 1; {
		m := n / r
		l := n/(m+1) + 1
		v += m * (r - l + 1) * (r + l) / 2
		r = l - 1
	}
	return v - n*(n+1)/2 + 1
}
