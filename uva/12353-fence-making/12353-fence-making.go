package main

import "math"

func main() {
	assert(solve(9682, 9719, 18, 29, 71757646) == 15404518)
	assert(solve(5746, 5958, 19, 24, 1942485264) == 1918408970)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(rmin, rmax, dmin, dmax, s int64) int64 {
	ret := int64(0)
	for r := rmin; r <= rmax; r++ {
		for d := dmin; d <= dmax; d++ {
			area := float64(4*s*(d+r)) - 2*math.Pi*float64(r*r)
			total := float64(8*(r+d)*(r+d)) - 2*math.Pi*float64(r*r)
			ret += int64(math.Floor(area/total) * 2)
		}
	}
	return ret
}
