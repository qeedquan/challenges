package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func main() {
	fmt.Println(solve(
		Point{0, 0},
		Point{10, 0},
		Point{3, 4},
	))
}

func solve(a, b, c Point) (Point, float64) {
	o := circle(midpoint(a, b), midpoint(b, c), midpoint(c, a))
	return o, distance(o, midpoint(a, b))
}

func circle(a, b, c Point) Point {
	mab := midpoint(a, b)
	mbc := midpoint(b, c)
	lab := sub(b, a)
	lbc := sub(c, b)
	lab.x, lab.y = lab.y, lab.x
	lbc.x, lbc.y = lbc.y, lbc.x
	lab.x = -lab.x
	lbc.x = -lbc.x
	return intersection(mab, lab, mbc, lbc)
}

func intersection(p, l1, q, l2 Point) Point {
	a1 := l1.y
	b1 := -l1.x
	c1 := a1*p.x + b1*p.y
	a2 := l2.y
	b2 := -l2.x
	c2 := a2*q.x + b2*q.y
	d := a1*b2 - a2*b1
	dx := b2*c1 - b1*c2
	dy := a1*c2 - a2*c1
	return Point{dx / d, dy / d}
}

func distance(a, b Point) float64 {
	return math.Hypot(a.x-b.x, a.y-b.y)
}

func midpoint(a, b Point) Point {
	return scale(add(a, b), 0.5)
}

func add(a, b Point) Point {
	return Point{a.x + b.x, a.y + b.y}
}

func sub(a, b Point) Point {
	return Point{a.x - b.x, a.y - b.y}
}

func scale(p Point, s float64) Point {
	return Point{p.x * s, p.y * s}
}
