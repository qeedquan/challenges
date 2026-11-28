package main

import "math"

func main() {
	assert(solve(1, 200) == 118)
	assert(solve(99, 100) == 99)
	assert(solve(99, 101) == 99)
	assert(solve(97, 103) == 100)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int) int {
	lo := a
	hi := b
	ret := -1
	tot := f(b) - f(a-1)
	for lo <= hi {
		mid := lo + (hi-lo)/2
		val := f(mid) - f(a-1)
		if val <= tot/2 {
			lo = mid + 1
			ret = mid
		} else {
			hi = mid - 1
		}
	}
	return ret
}

func f(n int) int {
	r := 0
	t := 10
	for i := 1; i < math.MaxInt; i++ {
		if n >= t {
			r += 9 * (t / 10) * i
		} else {
			r += (n - t/10 + 1) * i
			return r
		}
		t *= 10
	}
	return 0
}
