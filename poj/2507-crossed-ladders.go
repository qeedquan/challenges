/*

Description

A narrow street is lined with tall buildings. An x foot long ladder is rested at the base of the building on the right side of the street and leans on the building on the left side. A y foot long ladder is rested at the base of the building on the left side of the street and leans on the building on the right side. The point where the two ladders cross is exactly c feet from the ground. How wide is the street?

http://poj.org/images/2507_1.jpg

Input

Each line of input contains three positive floating point numbers giving the values of x, y, and c.

Output

For each line of input, output one line with a floating point number giving the width of the street in feet, with three decimal digits in the fraction.

Sample Input

30 40 10
12.619429 8.163332 3
10 10 3
10 10 1

Sample Output

26.033
7.000
8.000
9.798

Source

The UofA Local 2000.10.14

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(30, 40, 10, 26.033)
	test(12.619429, 8.163332, 3, 7)
	test(10, 10, 3, 8)
	test(10, 10, 1, 9.798)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y, c, r float64) {
	w := streetwidth(x, y, c)
	fmt.Println(w)
	assert(math.Abs(w-r) < 1e-3)
}

func streetwidth(x, y, c float64) float64 {
	const eps = 1e-12

	l, m, r := 0.0, 0.0, max(x, y)
	for r-l > eps {
		m = l + (r-l)/2
		if judge(x, y, c, m) > 0 {
			l = m
		} else {
			r = m
		}
	}
	return m
}

func judge(x, y, c, w float64) float64 {
	return 1 - c/math.Sqrt(x*x-w*w) - c/math.Sqrt(y*y-w*w)
}
