package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(3, 4, 5))
	fmt.Println(solve(10, 11, 12))
}

func solve(a, b, c float64) (float64, float64) {
	S := area(a, b, c)
	ra := 2 * S / (-a + b + c)
	rb := 2 * S / (a - b + c)
	rc := 2 * S / (a + b - c)
	A := angle(b, c, a)
	B := angle(a, c, b)
	C := angle(a, b, c)
	r1 := S + (a*ra+b*rb+c*rc)/2
	r2 := A*ra*ra + B*rb*rb + C*rc*rc
	return r1, r2 / 4
}

func area(a, b, c float64) float64 {
	p := (a + b + c) / 2
	return math.Sqrt(p * (p - a) * (p - b) * (p - c))
}

func angle(a, b, c float64) float64 {
	return math.Acos((c*c - a*a - b*b) / (2 * a * b))
}
