/*

Description

A cone is located in 3D such that its base of radius r is in the z = 0 plane with the center at (0,0,0). The tip of the cone is located at (0, 0, h). Two points are given on the cone surface in conic coordinates. The conic coordinates of a point p lying on the surface of the cone are two numbers: the first, d, is the distance from the tip of the cone to p and the second, A < 360, is the angle in degrees between the plane y = 0 and the plane through points (0,0,0), (0,0,h) and p, measured counterclockwise from the direction of the x axis.

http://poj.org/images/2508_1.jpg

Given are two points p1 = (d1, A1) and p2 = (d2, A2) in the conic coordinates. What is the (shortest) distance between p1 and p2 measured on the surface of the cone?

Input

The input is a sequence of lines. Each line contains 6 floating point numbers giving values of: r, h, d1, A1, d2, and A2

Output

For each line of input, output the (shortest) distance between points p1 and p2 on the surface of the cone with the fraction rounded to 2 decimal places.

Sample Input

3.0 4.0 2.0 0.0 4.0 0.0
3.0 4.0 2.0 90.0 4.0 0.0
6.0 8.0 2.14 75.2 9.58 114.3
3.0 4.0 5.0 0.0 5.0 90.0

Sample Output

2.00
3.26
7.66
4.54

Source

The UofA Local 2000.10.14

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(3.0, 4.0, 2.0, 0.0, 4.0, 0.0, 2.00)
	test(3.0, 4.0, 2.0, 90.0, 4.0, 0.0, 3.26)
	test(6.0, 8.0, 2.14, 75.2, 9.58, 114.3, 7.66)
	test(3.0, 4.0, 5.0, 0.0, 5.0, 90.0, 4.54)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(r, h, d1, A1, d2, A2, rd float64) {
	d := distance(r, h, d1, A1, d2, A2)
	fmt.Println(d)
	assert(math.Abs(d-rd) < 1e-2)
}

func distance(r, h, d1, A1, d2, A2 float64) float64 {
	t := math.Abs(A1 - A2)
	t = min(t, 360-t)
	t = deg2rad(t) * r / math.Sqrt(r*r+h*h)
	return math.Sqrt(d1*d1 + d2*d2 - 2*d1*d2*math.Cos(t))
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
