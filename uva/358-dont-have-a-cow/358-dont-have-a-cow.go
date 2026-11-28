package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(100, 0.33))
}

func solve(R, P float64) string {
	const eps = 1e-12

	lo := 0.0
	hi := math.Pi
	A := R * R * math.Pi
	ret := 0.0
	for math.Abs(lo-hi) > eps {
		mid := lo + (hi-lo)/2
		ret = math.Hypot(R*math.Cos(mid)-R, R*math.Sin(mid))
		theta := (math.Pi - mid) / 2
		area := (ret*ret*theta/2 + (R*R*mid/2 - R*R*math.Sin(mid)/2)) * 2
		if area < A*P {
			lo = mid
		} else {
			hi = mid
		}
	}
	return fmt.Sprintf("R = %.0f, P = %.2f, Rope = %.2f", R, P, ret)
}
