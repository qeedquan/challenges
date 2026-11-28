package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(10, 5, 5))
	fmt.Println(solve(10, 4, 8))
}

func solve(l, w, r float64) float64 {
	if w > l {
		w, l = l, w
	}

	var area float64
	switch {
	case r <= w:
		area = r * r * math.Pi * 3 / 4.0
	case r <= l:
		area = r*r*math.Pi*3/4.0 + (r-w)*(r-w)*math.Pi/4.0
	case r <= l+w:
		area = r*r*math.Pi*3/4.0 + (r-w)*(r-w)*math.Pi/4.0 + (r-l)*(r-l)*math.Pi/4.0
	default:
		a := math.Atan2(l, w)
		la := math.Hypot(w, l)
		lb := r - w
		lc := r - l
		b := math.Acos((la*la+lb*lb-lc*lc)/(2*la*lb)) + a
		c := math.Acos((la*la+lc*lc-lb*lb)/(2*la*lc)) + (math.Pi / 2) - a

		area = r * r * math.Pi * 3 / 4.0
		area += (r - w) * (r - w) * (math.Pi - b) / 2
		area += (r - l) * (r - l) * (math.Pi - c) / 2
		area += lb * la * math.Sin(b-a) / 2
		area -= w * l / 2
	}
	return area
}
