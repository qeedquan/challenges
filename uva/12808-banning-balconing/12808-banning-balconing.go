package main

import "math"

func main() {
	assert(solve(7000, 3000, 5000, 1500) == "FLOOR")
	assert(solve(5500, 2000, 8000, 4000) == "POOL")
	assert(solve(6250, 1000, 3000, 750) == "EDGE")
	assert(solve(3000, 300, 10000, 600) == "POOL")
	assert(solve(3000, 500, 10000, 600) == "EDGE")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(L, D, H, V float64) string {
	L /= 1000
	D /= 1000
	H /= 1000
	V /= 1000
	t := math.Sqrt(H * 2 / 9.8)
	d := V * t
	if math.Abs(d-D) < 0.5 || math.Abs(d-(D+L)) < 0.5 {
		return "EDGE"
	}
	if d < D || d > D+L {
		return "FLOOR"
	}
	return "POOL"
}
