package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(distance(500, 30, "deg"))
	fmt.Println(distance(700, 60, "min"))
	fmt.Println(distance(200, 45, "deg"))
}

func distance(s, a float64, t string) (float64, float64) {
	switch t {
	case "min":
		a /= 60
	case "deg":
	default:
		return -1, -1
	}
	if a > 180 {
		a = 360 - a
	}
	a = deg2rad(a)
	d := 6440 + s

	return a * d, 2 * d * math.Sin(a/2)
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
