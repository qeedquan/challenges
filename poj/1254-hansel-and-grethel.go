/*

Description

On a warm summer afternoon, Hansel and Grethel are walking together in the fields. It is getting late and, to be honest, they are lost. Grethel is a little scared, still vividly remembering the last time they got lost in the forest. That time, an evil witch had locked them inside a house built of gingerbread and sugar! But Hansel can reassure her: this time they are well prepared. Hansel has taken a map and a compass with him!
Hansel picks two clearly outstanding features in the landscape, and uses the compass to measure the direction towards both objects. Grethel locates the objects on the map, and writes down the corresponding map coordinates. Based on this information, they will be able to accurately determine their own position on the map.

http://poj.org/images/1254_1.jpg

The coordinates of two marker objects, and the direction (angle from the North) towards these objects are known. Write a program which uses this data to calculate the coordinates of Hansel and Grethel’s current location.

Input

The first line of the input contains one positive number: the number of situations in which a position must be determined. Following are two lines per situation, describing the two marker objects. Each marker object is described by a line containing three integer numbers:
␂ the x-coordinate of the object on the map (0 <= x <= 100);
the x-axis runs West-to-East on the map, with increasing values towards the East.
␂ the y-coordinate of the object on the map (0 <= y <= 100);
the y-axis runs South-to-North on the map, with increasing values towards the North.
␂ the direction d of the object in degrees (0 <= d <= 360);
with 0 degree = North, 90 degree = East, 180 degree = South, and so on.
To keep the position calculations accurate, Hansel makes sure that the directions of the two
objects are not exactly equal, and do not differ by exactly 180 degree.
Output

One line per situation, containing the result of the position calculation: two numbers, separated by a space, each having exactly 4 digits after the decimal point.
These numbers represent the x and y coordinates of the position of Hansel and Grethel (0 <= x,y <= 100).
Round the numbers as usual: up if the next digit would be >= 5, down otherwise.

Sample Input

2
30 50 90
20 40 180
30 40 96
20 20 150

Sample Output

20.0000 50.0000
7.0610 42.4110

Source

Northwestern Europe 2002


*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(30, 50, 90, 20, 40, 180, 20, 50)
	test(30, 40, 96, 20, 20, 150, 7.0610, 42.4110)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x1, y1, d1, x2, y2, d2 int, rx, ry float64) {
	const eps = 1e-4
	x, y := position(x1, y1, d1, x2, y2, d2)
	fmt.Println(x, y)
	assert(math.Abs(x-rx) < eps)
	assert(math.Abs(y-ry) < eps)
}

func position(x1, y1, d1, x2, y2, d2 int) (float64, float64) {
	a1, b1, c1 := orientation(x1, y1, d1)
	a2, b2, c2 := orientation(x2, y2, d2)
	return intersect(a1, b1, c1, a2, b2, c2)
}

func orientation(x, y, d int) (float64, float64, float64) {
	if d == 0 || d == 180 {
		return 1, 0, float64(-x)
	}
	a := math.Tan((90 - float64(d)) / 180 * math.Pi)
	b := -1.0
	c := float64(y) - a*float64(x)
	return a, b, c
}

func intersect(a1, b1, c1, a2, b2, c2 float64) (float64, float64) {
	if a1*b2-a2*b1 == 0 {
		return 0, 0
	}
	x := (c2*b1 - c1*b2) / (a1*b2 - a2*b1)
	y := (c2*a1 - c1*a2) / (a2*b1 - a1*b2)
	return x, y
}
