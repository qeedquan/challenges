package main

func main() {
	assert(jos(5, 3) == 7)

	N := int64(1000)
	for n := range N {
		for k := range N {
			assert(jos(n, k) == josbf(n, k))
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func jos(n, k int64) int64 {
	v := int64(0)
	l := int64(1)
	for l <= k {
		div := k / l
		r := min(k/div, n)
		a0 := k % l
		d := -div
		tn := r - l + 1
		v += (a0*2 + (tn-1)*d) * tn / 2
		l = r + 1
		if r == n {
			break
		}
	}
	if l <= n {
		v += (n - l + 1) * k
	}
	return v
}

func josbf(n, k int64) int64 {
	r := int64(0)
	for i := int64(1); i <= n; i++ {
		r += k % i
	}
	return r
}
