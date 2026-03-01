/*

The walker

The walker starts from point O, walks along OA, AB and BC. When he is in C (C will be in the upper half-plane), what is the distance CO? What is the angle tOC in positive degrees, minutes, seconds?

Angle tOA is alpha (here 45 degrees), angle hAB is beta (here 30 degrees), angle uBC is gamma(here 60 degrees).

Task
function solve(a, b, c, alpha, beta, gamma) with parameters

a, b, c: positive integers in units of distance (stand for OA, AB, BC)
alpha, beta, gamma: positive integers in degrees (positive angles are anticlockwise)
returns an array:

first element: distance CO (rounded to the nearest integer)
then angle tOC with the third following elements:
second element of the array: number of degrees in angle tOC (truncated positive integer)
third element of the array: number of minutes in angle tOC (truncated positive integer)
fourth element of the array: number of seconds in angle tOC (truncated positive integer)
Example:
print(solve(12, 20, 18, 45, 30, 60)) -> [15, 135, 49, 18]
- CO is 14.661... rounded to 15
- angle tOC is 135.821...
so
- degrees = 135
- minutes = 49.308...
- seconds = 18.518...

hence [15, 135, 49, 18]
Note
If you need the constant pi you can use pi = 3.14159265358979323846

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(12, 20, 18, 45, 30, 60))
	fmt.Println(solve(15, 15, 19, 50, 29, 55))
	fmt.Println(solve(14, 25, 17, 41, 35, 59))
}

func solve(a, b, c, α, β, γ float64) (float64, float64, float64, float64) {
	α, β, γ = deg2rad(α), deg2rad(β), deg2rad(γ)
	x := a*math.Cos(α) - b*math.Sin(β) - c*math.Cos(γ)
	y := a*math.Sin(α) + b*math.Cos(β) - c*math.Sin(γ)

	L := math.Round(math.Hypot(x, y))
	A := math.Pi/2 + math.Atan(-x/y)
	T := (A * 360 * 60 * 60) / (2 * math.Pi)
	D := T / 3600
	M := math.Mod(T/60, 60)
	S := math.Mod(T, 60)
	return L, math.Floor(D), math.Floor(M), math.Floor(S)
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
