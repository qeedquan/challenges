package main

func main() {
	assert(mslcm(10) == 86)
	assert(mslcm(1000) == 823080)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mslcm(n int64) int64 {
	if n < 1 {
		return 0
	}

	c := int64(0)
	for l := int64(1); l <= n; {
		v := n / l
		r := n / v
		c += v * ((l + r) * (r - l + 1) / 2)
		l = r + 1
	}
	return c - 1
}
