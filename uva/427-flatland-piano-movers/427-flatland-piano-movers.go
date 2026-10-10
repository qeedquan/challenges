package main

import "math"

func main() {
	assert(solve(600, 200, 300, 500) == 'Y')
	assert(solve(600, 200, 837, 500) == 'Y')
	assert(solve(600, 200, 350, 350) == 'N')

	assert(solve(137, 1200, 600, 500) == 'Y')
	assert(solve(137, 1200, 600, 400) == 'N')
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(H, W, X, Y float64) rune {
	const eps = 1e-12

	if H < W {
		W, H = H, W
	}

	lo := 0.0
	hi := math.Pi / 2
	h1 := 0.0
	for math.Abs(lo-hi) > eps {
		mid1 := (lo + hi) / 2
		mid2 := (mid1 + hi) / 2
		s1 := H*math.Cos(mid1) + W*math.Sin(mid1) - X
		h1 = s1*math.Tan(mid1) + W*math.Cos(mid1)
		s2 := H*math.Cos(mid2) + W*math.Sin(mid2) - X
		h2 := s2*math.Tan(mid2) + W*math.Cos(mid2)
		if h1 < h2 {
			lo = mid1
		} else {
			hi = mid1
		}
	}
	if h1 <= Y {
		return 'Y'
	}
	return 'N'
}
