package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(7, 6, 4, 8, 6, 4))
	fmt.Println(solve(4, 8, 8, 8, 8, 8))
}

func solve(ra, rb, rc, a, b, c float64) float64 {
	if ra > a || rb > b || rc > c {
		return 0
	}

	var ta, tb, tc, l, r float64
	if ra < a {
		ta = b / 2
		tb = c / 2
		tc = a / 2
		r = a / 2
		l = r - math.Abs(a-ra)
	} else if rb < b {
		ta = a / 2
		tb = c / 2
		tc = b / 2
		r = b / 2
		l = r - math.Abs(b-rb)
	} else if rc < c {
		ta = a / 2
		tb = b / 2
		tc = c / 2
		r = c / 2
		l = r - math.Abs(c-rc)
	} else {
		return 0
	}
	return ta * tb * math.Pi * (1 - l*l/tc/tc)
}
