/*

Consider an (n+1) * (n+1) grid of points places at non-negative integer coordinates.
Given two points in the grid at (a,b) and (c,d), we know that the distance of the first point to the origin at (0,0) is x=sqrt(a^2 + b^2) and the distance of the second point to the origin is y=sqrt(c^2 + d^2).

Given a positive integer n, the task is to find non-negative integers 0≤a,b,c,d≤n so that |x-y| is as small as possible but not equal to zero.

Input
Positive integer n

Output
Two points (a,b) and (c,d) that minimize |sqrt(a^2 + b^2) - sqrt(c^2 + d^2)| under the constraint that |sqrt(a^2 + b^2) - sqrt(c^2 + d^2)| != 0.

Example
If n=7 then (7,2), (4,6) is a valid output.

*/

package main

import (
	"fmt"
	"image"
	"math"
)

func main() {
	fmt.Println(similar(7))
}

func similar(n int) (r0, r1 image.Point) {
	var p, q image.Point
	m := math.MaxFloat64
	for p.X = 0; p.X <= n; p.X++ {
		for p.Y = 0; p.Y <= n; p.Y++ {
			for q.X = 0; q.X <= n; q.X++ {
				for q.Y = 0; q.Y <= n; q.Y++ {
					x := math.Hypot(float64(p.X), float64(p.Y))
					y := math.Hypot(float64(q.X), float64(q.Y))
					d := math.Abs(x - y)
					if d > 0 && d < m {
						m, r0, r1 = d, p, q
					}
				}
			}
		}
	}
	return
}
