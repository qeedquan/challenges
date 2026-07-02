package main

import (
	"math"
)

func main() {
	assert(candles(2, 26, 8) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func candles(d, r, t int) int {
	for c := range math.MaxInt {
		x := age(r, 6)
		y := age(t, 3)
		if x-y == d {
			return c
		}
		r -= 1
		t += 1
	}
	return -1
}

func age(c, o int) int {
	c = (c + o) << 1
	for x := range math.MaxInt {
		d := (x * x) + x - c
		if d == 0 {
			return x
		}
		if d > 0 {
			break
		}
	}
	return -1
}
