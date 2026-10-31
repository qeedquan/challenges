package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func main() {
	fmt.Println(solve(Point{0, 0}, Point{20, 0}, 10, 14, 8))
	fmt.Println(solve(Point{0, 0}, Point{20, 0}, 8, 14, 10))
	fmt.Println(solve(Point{20, 0}, Point{0, 0}, 10, 14, 8))
	fmt.Println(solve(Point{20, 0}, Point{0, 0}, 8, 14, 10))
	fmt.Println(solve(Point{8, 0}, Point{8, 20}, 10, 14, 8))
	fmt.Println(solve(Point{8, 0}, Point{8, 20}, 8, 14, 10))
	fmt.Println(solve(Point{0, 20}, Point{0, 0}, 10, 14, 8))
	fmt.Println(solve(Point{0, 20}, Point{0, 0}, 8, 14, 10))
}

func solve(p1, p2 Point, b, c, d float64) (Point, Point) {
	a := dist(p1, p2)
	x := (sqr(d) - sqr(b) + sqr(a-c)) / (2 * (a - c))
	p3 := scale(sub(p2, p1), 1/a)
	t := math.Atan2(math.Sqrt(d*d-x*x), x)
	p4 := add(scale(rotate(p3, t), d), p1)
	p5 := add(p4, scale(p3, c))
	return p5, p4
}

func add(a, b Point) Point {
	return Point{a.x + b.x, a.y + b.y}
}

func sub(a, b Point) Point {
	return Point{a.x - b.x, a.y - b.y}
}

func scale(a Point, s float64) Point {
	return Point{a.x * s, a.y * s}
}

func dist(a, b Point) float64 {
	return math.Hypot(a.x-b.x, a.y-b.y)
}

func rotate(a Point, t float64) Point {
	return Point{
		a.x*math.Cos(t) - a.y*math.Sin(t),
		a.x*math.Sin(t) + a.y*math.Cos(t),
	}
}

func sqr(x float64) float64 {
	return x * x
}

func (p Point) String() string {
	return fmt.Sprintf("[%.8f, %.8f]", p.x, p.y)
}
