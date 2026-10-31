package main

import "image"

func main() {
	assert(solve([]image.Point{
		{0, 0},
		{3, 0},
		{3, 3},
		{0, 3},
	}) == "No")

	assert(solve([]image.Point{
		{0, 0},
		{3, 0},
		{1, 1},
		{0, 3},
	}) == "Yes")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(p []image.Point) string {
	n := len(p)
	i := 0
	if sign(p, 0) >= 0 {
		for ; i < n; i++ {
			if sign(p, i) < 0 {
				break
			}
		}
	} else {
		for ; i < n; i++ {
			if sign(p, i) > 0 {
				break
			}
		}
	}

	if i != n {
		return "Yes"
	}
	return "No"
}

func sign(p []image.Point, i int) int {
	n := len(p)
	if i >= n {
		return 0
	}

	j := (i + 1) % n
	k := (i + 2) % n
	return wedge(p[i], p[j], p[k])
}

func wedge(o, a, b image.Point) int {
	return (a.X-o.X)*(b.Y-o.Y) - (a.Y-o.Y)*(b.X-o.X)
}
