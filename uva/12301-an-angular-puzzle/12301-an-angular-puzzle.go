package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func main() {
	fmt.Printf("%.2f\n", solve(20, 10, 70, 20, 60))
	fmt.Printf("%.2f\n", solve(30, 5, 70, 15, 60))
	fmt.Printf("%.2f\n", solve(60, 30, 30, 30, 30))
	fmt.Printf("%.2f\n", solve(30, 40, 40, 40, 40))
}

func solve(a, b, c, d, e float64) float64 {
	if a+b+c+d+e != 180 {
		return -1
	}

	a = deg2rad(a)
	b = deg2rad(b)
	c = deg2rad(c)
	d = deg2rad(d)
	e = deg2rad(e)
	E := intersection(pt(0, 0), pt(math.Cos(c), math.Sin(c)), pt(1, 0), pt(-math.Cos(d+e), math.Sin(d+e)))
	F := intersection(pt(0, 0), pt(math.Cos(b+c), math.Sin(b+c)), pt(1, 0), pt(-math.Cos(e), math.Sin(e)))
	G := intersection(pt(0, 0), pt(math.Cos(c), math.Sin(c)), pt(1, 0), pt(-math.Cos(e), math.Sin(e)))
	return rad2deg(angle(sub(F, E), sub(G, E)))
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
	return pt(dx/d, dy/d)
}

func sub(a, b Point) Point {
	return pt(a.x-b.x, a.y-b.y)
}

func angle(a, b Point) float64 {
	return math.Acos(dot(a, b) / (length(a) * length(b)))
}

func length(a Point) float64 {
	return math.Hypot(a.x, a.y)
}

func dot(a, b Point) float64 {
	return a.x*b.x + a.y*b.y
}

func pt(x, y float64) Point {
	return Point{x, y}
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}

func rad2deg(x float64) float64 {
	return x * 180 / math.Pi
}
