package main

import (
	"image"
)

func main() {
	assert(dimension(20) == [4]image.Point{
		{-45, 30},
		{55, 30},
		{55, -30},
		{-45, -30},
	})

	assert(dimension(100) == [4]image.Point{
		{-225, 150},
		{275, 150},
		{275, -150},
		{-225, -150},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func dimension(r float64) [4]image.Point {
	w := 1.5 * r
	l := 5 * r
	l1 := .45 * l
	l2 := .55 * l
	return [4]image.Point{
		{int(-l1), int(w)},
		{int(l2), int(w)},
		{int(l2), int(-w)},
		{int(-l1), int(-w)},
	}
}
