/*

Given two forces (F1 and F2 ) and the angle F2 makes with F1 find the resultant force R and the angle it makes with F1.

input

Three values :

F1
F2 making an angle θ with F1
angle θ

output
An array consisting of two values :

R (the resultant force)
angle R makes with F1 (φ)

notes

Units for each of the following are given as under :

F1 = Newton
F2 = Newton
angle θ = degree
R = Newton
φ = degreeq

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(20, 10, 120))
	fmt.Println(solve(110, 45, 45))
}

func solve(f1, f2, t float64) [2]float64 {
	r := deg2rad(t)
	f2x := f2 * math.Cos(r)
	f2y := f2 * math.Sin(r)
	rx := f1 + f2x
	ry := f2y
	return [2]float64{
		math.Hypot(rx, ry),
		rad2deg(math.Atan2(ry, rx)),
	}
}

func rad2deg(x float64) float64 {
	return x * 180 / math.Pi
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
