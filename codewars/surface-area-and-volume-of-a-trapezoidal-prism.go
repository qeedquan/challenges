/*

Write a function that returns the total surface area and volume of a trapezioidal prism as an array [area, volume], rounded to the nearest integer. A trapezoidal prism is shape that has trapezium (trapezoid) cross sections in one direction and rectangular cross sections in the other directions.

a = top width of trapezium cross section, b = base width of trapezium cross section, h = height of cross section (distance from a to b), l = length of prism.

Diagram of a trapeziodal prism:

https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/trapezoidal-prism-1622086836.png

Trapezium cross section:

        a
    __________
   /          \    |
  /            \   |h
 /______________\  |
        b
The tapazium cross section has one line of symmetry:

    ____|____
   /    |    \
  /     |     \
 /______|______\
        |

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(areavolume(3, 4, 5, 6))
	fmt.Println(areavolume(8, 8, 8, 8))
}

func areavolume(a, b, h, l float64) (float64, float64) {
	L := math.Hypot((b-a)/2, h)
	A := math.Round((a+b+L*2)*l + (a+b)*h)
	V := math.Round((a + b) / 2 * h * l)
	return A, V
}
