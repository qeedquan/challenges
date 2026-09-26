/*

Find the total surface area of a right square pyramid, given that the lateral edge b forms an angle α with the base plane.

Input
The input consists of a single line containing two integers separated by a space: the lateral edge b (0<b≤100) and its angle α with the base plane in degrees (0<α≤90).

Output
Print a single number — the required surface area. Output the result with an accuracy of three decimal places.

Examples
Input #1
4 45

Answer #1
43.713

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(4, 45))
}

func solve(b, a float64) float64 {
	a = deg2rad(a)
	c := math.Sqrt2 * b * math.Cos(a)
	h := b * math.Sin(a)
	s1 := c * c
	s2 := 2 * c * math.Sqrt((h*h + (c * c / 4)))
	return s1 + s2
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
