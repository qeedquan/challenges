package main

import "math"

func main() {
	assert(solve(5, 5, 2, 3, 1, 2, 3, 5, 0) == 36)
	assert(solve(300, 600, 900, 300, 550, 0, 0, 550, 900) == 970000)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(L, W, H, x1, y1, z1, x2, y2, z2 int) int {
	if z1 != 0 && z1 != H {
		if y1 != 0 && y1 != W {
			L, H = H, L
			x1, z1 = z1, x1
			x2, z2 = z2, x2
		} else {
			W, H = H, W
			y1, z1 = z1, y1
			y2, z2 = z2, y2
		}
	}
	if z1 == H {
		z1 = 0
		z2 = H - z2
	}
	return unfold(L, W, H, x1, y1, x2, y2, z2, 0, 0)
}

func unfold(L, W, H, x1, y1, x2, y2, z2, rx, ry int) int {
	if z2 == 0 {
		return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)
	}

	r := math.MaxInt
	if rx >= 0 && rx < 2 {
		r = min(r, unfold(H, W, L, x1+H, y1, H-z2, y2, x2, rx+1, ry))
	}
	if rx <= 0 && rx > -2 {
		r = min(r, unfold(H, W, L, x1-L, y1, z2, y2, L-x2, rx-1, ry))
	}
	if ry >= 0 && ry < 2 {
		r = min(r, unfold(L, H, W, x1, y1-W, x2, z2, W-y2, rx, ry+1))
	}
	if ry <= 0 && ry > -2 {
		r = min(r, unfold(L, H, W, x1, y1+H, x2, H-z2, y2, rx, ry-1))
	}
	return r
}
