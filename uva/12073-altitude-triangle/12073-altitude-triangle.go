package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func main() {
	fmt.Println(solve(Point{682, 1369}, Point{3981, 1233}, Point{4333, 4583}))
	fmt.Println(solve(Point{4131, 734}, Point{1249, 4705}, Point{2815, 475}))
	fmt.Println(solve(Point{2815, 475}, Point{4131, 734}, Point{1249, 4705}))
}

func solve(p1, p2, p3 Point) (jax, jay, jbx, jby, jcx, jcy float64) {
	a := dist(p2, p3)
	b := dist(p1, p3)
	c := dist(p1, p2)
	jax = (-a*p1.x + b*p2.x + c*p3.x) / (-a + b + c)
	jay = (-a*p1.y + b*p2.y + c*p3.y) / (-a + b + c)
	jbx = (a*p1.x - b*p2.x + c*p3.x) / (a - b + c)
	jby = (a*p1.y - b*p2.y + c*p3.y) / (a - b + c)
	jcx = (a*p1.x + b*p2.x - c*p3.x) / (a + b - c)
	jcy = (a*p1.y + b*p2.y - c*p3.y) / (a + b - c)
	return
}

func dist(a, b Point) float64 {
	return math.Hypot(a.x-b.x, a.y-b.y)
}
