package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

type Segment struct {
	p1, p2 Point
}

type Gravity struct {
	p    Point
	mass float64
}

func main() {
	fmt.Println(solve([]Point{
		{0, 1},
		{1, 1},
		{0, 0},
		{1, 0},
	}))

	fmt.Println(solve([]Point{
		{1, 2},
		{1, 0},
		{0, 0},
	}))

	fmt.Println(solve([]Point{
		{-4, -4},
		{-6, -3},
		{-4, -10},
		{-7, -12},
		{-9, -8},
		{-3, -6},
		{-8, -3},
	}))
}

func solve(p []Point) Point {
	n := convex_hull(p)
	if n == 0 {
		return Point{}
	}

	g := make([]Gravity, n)
	for i := 1; i < n-1; i++ {
		g[i-1] = triangulate(p[0], p[i], p[i+1])
	}
	for i := 1; i < n-2; i++ {
		g[0] = add_gravity(g[0], g[i])
	}
	return g[0].p
}

func minimum_angle(o int, p []Point) int {
	m := 0
	if o == 0 {
		m = 1
	}

	for i := range p {
		if i == o {
			continue
		}
		if (p[i].x-p[o].x)*(p[m].y-p[o].y) > (p[i].y-p[o].y)*(p[m].x-p[o].x) {
			m = i
		}
	}
	return m
}

func convex_hull(p []Point) int {
	m := 0
	for i := 1; i < len(p); i++ {
		c := p[i].y - p[m].y
		if c < 0 {
			m = i
		}
		if c == 0 && p[i].x < p[m].x {
			m = i
		}
	}
	p[0], p[m] = p[m], p[0]

	m = 1
	for {
		i := minimum_angle(m-1, p)
		if i == 0 {
			break
		}
		p[i], p[m], m = p[m], p[i], m+1
	}
	return m
}

func modulus(p Point) float64 {
	return math.Hypot(p.x, p.y)
}

func psub(p1, p2 Point) Point {
	return Point{
		p1.x - p2.x,
		p1.y - p2.y,
	}
}

func dist(p1, p2 Point) float64 {
	return modulus(psub(p1, p2))
}

func coordy(s Segment, x float64) (float64, bool) {
	if s.p2.x == s.p1.x {
		return 0, false
	}
	return s.p1.y + (x-s.p1.x)*(s.p2.y-s.p1.y)/(s.p2.x-s.p1.x), true
}

func cut(s1, s2 Segment) (Point, bool) {
	var (
		p  Point
		ok = true
	)

	if s1.p1.x == s1.p2.x {
		p.x = s1.p1.x
		p.y, ok = coordy(s2, p.x)
		return p, ok
	}

	if s2.p1.x == s2.p2.x {
		p.x = s2.p1.x
		p.y, ok = coordy(s1, p.x)
		return p, ok
	}

	A := (s1.p2.y - s1.p1.y) / (s1.p2.x - s1.p1.x)
	B := (s2.p2.y - s2.p1.y) / (s2.p2.x - s2.p1.x)
	if A == B {
		return p, false
	}

	p.x = (s2.p1.y - s1.p1.y + A*s1.p1.x - B*s2.p1.x) / (A - B)
	p.y = s1.p1.y + A*(p.x-s1.p1.x)
	return p, ok
}

func triangulate(p1, p2, p3 Point) Gravity {
	var (
		g      Gravity
		s1, s2 Segment
		ok     = true
	)

	s := (dist(p1, p2) + dist(p2, p3) + dist(p1, p3)) / 2.0

	s1.p1 = p1
	s1.p2.x = (p2.x + p3.x) / 2.0
	s1.p2.y = (p2.y + p3.y) / 2.0

	s2.p1 = p2
	s2.p2.x = (p1.x + p3.x) / 2.0
	s2.p2.y = (p1.y + p3.y) / 2.0

	g.p, ok = cut(s1, s2)
	if !ok {
		panic("singularity")
	}

	g.mass = math.Sqrt(s * (s - dist(p1, p2)) * (s - dist(p2, p3)) * (s - dist(p1, p3)))
	return g
}

func add_gravity(g1, g2 Gravity) Gravity {
	g := Gravity{}
	g.mass = g1.mass + g2.mass
	g.p.x = (g1.mass*g1.p.x + g2.mass*g2.p.x) / g.mass
	g.p.y = (g1.mass*g1.p.y + g2.mass*g2.p.y) / g.mass
	return g
}

func (p Point) String() string {
	return fmt.Sprintf("[%.3f, %.3f]", p.x, p.y)
}
