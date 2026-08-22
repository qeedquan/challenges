/*

Description

You work for an art store that has decided to carry every style and size of drafting triangle in existence. Unfortunately, sorting these has become a problem. The manager has given you the task of organizing them. You have decided to classify them by edge length and angles. To measure each triangle, you set it on a large sheet of very accurate graph paper and record the coordinate of each point. You then run these three points through a computer program to classify the triangles according to:
Scalene no equal sides
Isosceles two equal sides
Equilateral three equal sides
and
Acute all angles under 90
Right one angle equal 90
Obtuse one angle over 90
Of course, sometimes you make mistakes entering the data, so if you input points that do not form a valid triangle, your program should tell you.

Input

One triangle is described per line. Each line has six measurements taken to the nearest 0.001 in the order:
x1 y1 x2 y2 x3 y3
The final line of input will contain only a -1.
None of the test sets contain non-right angles in the range 88-92 degrees, nor do any of the test sets include any non-equal side lengths for one triangle within 0.01 of one another.

Output

You will output one line for each triangle, which will contain two words:
< length classification > < angle classification >
or
Not a Triangle
The final line of your output file will be:
End of Output

Sample Input

10.000 10.000 10.000 20.000 20.000 10.000
0.000 0.000 4.000 0.000 2.000 3.464
-1

Sample Output

Isosceles Right
Equilateral Acute
End of Output

Source

Mid-Atlantic 2003

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	assert(classify(10.000, 10.000, 10.000, 20.000, 20.000, 10.000) == "Isosceles Right")
	assert(classify(0.000, 0.000, 4.000, 0.000, 2.000, 3.464) == "Equilateral Acute")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://www.mathsisfun.com/algebra/trig-solving-sss-triangles.html
func classify(x1, y1, x2, y2, x3, y3 float64) string {
	s := sides(x1, y1, x2, y2, x3, y3)
	t := angles(s)
	return fmt.Sprintf("%s %s", sidetype(s), angletype(t))
}

func sides(x1, y1, x2, y2, x3, y3 float64) [3]float64 {
	s := [3]float64{
		math.Hypot(x2-x1, y2-y1),
		math.Hypot(x3-x2, y3-y2),
		math.Hypot(x1-x3, y1-y3),
	}
	sort.Float64s(s[:])
	return s
}

func angles(s [3]float64) [3]float64 {
	a, b, c := s[0], s[1], s[2]
	C := math.Acos((c*c - a*a - b*b) / (-2 * a * b))
	S := math.Sin(C)
	A := math.Asin(a * (S / c))
	B := math.Asin(b * (S / c))
	return [3]float64{A, B, C}
}

func sidetype(s [3]float64) string {
	const eps = 1e-2
	c := 0
	n := len(s)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if math.Abs(s[i]-s[j]) <= eps {
				c++
			}
		}
	}

	switch c {
	case 0:
		return "Scalene"
	case 1:
		return "Isosceles"
	}
	return "Equilateral"
}

func angletype(t [3]float64) string {
	const eps = 1e-2
	for _, t := range t {
		if math.Abs(t-math.Pi/2) <= eps {
			return "Right"
		}

		if t > math.Pi/2 {
			return "Obtuse"
		}
	}
	return "Acute"
}
