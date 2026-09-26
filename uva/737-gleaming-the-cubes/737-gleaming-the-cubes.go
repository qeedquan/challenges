package main

import "math"

func main() {
	assert(solve([][4]int{
		{0, 0, 0, 10},
		{9, 1, 1, 5},
	}) == 25)

	assert(solve([][4]int{
		{0, 0, 0, 10},
		{9, 1, 1, 5},
		{8, 2, 2, 3},
	}) == 9)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(r [][4]int) int {
	if len(r) == 0 {
		return 0
	}

	lx, ly, lz := math.MinInt, math.MinInt, math.MinInt
	rx, ry, rz := math.MaxInt, math.MaxInt, math.MaxInt
	for _, r := range r {
		x, y, z, d := r[0], r[1], r[2], r[3]
		lx = max(lx, x)
		ly = max(ly, y)
		lz = max(lz, z)
		rx = min(rx, x+d)
		ry = min(ry, y+d)
		rz = min(rz, z+d)
	}
	return max((rx-lx)*(ry-ly)*(rz-lz), 0)
}
