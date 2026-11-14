package main

import (
	"fmt"
	"math"
)

func main() {
	assert(solve(1) == 7)
	assert(solve(2) == 8)
	assert(solve(10) == 20)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x uint64) uint64 {
	const scale = math.Ln10 / math.Ln2

	if x == 0 {
		return 0
	}

	l := 0.0
	n := len(fmt.Sprint(x)) + 1
	a := float64(x)
	for {
		l = math.Log(a)/math.Ln2 + float64(n)*scale
		r := math.Log(a+1)/math.Ln2 + float64(n)*scale
		if math.Floor(l) < math.Floor(r) {
			break
		}
		n += 1
	}
	return uint64(math.Ceil(l))
}
