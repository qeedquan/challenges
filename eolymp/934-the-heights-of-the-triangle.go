/*

Obtain the heights of a triangle with sides a, b, c.

Input
A single line contains three positive integers a, b, c — the triangle's sides. All values do not exceed 100.

Output
Print the heights dropped onto the corresponding sides: ha, hb, hc.
The results must be printed with 2 digits after the decimal point.

Examples

Input #1
3 4 5

Answer #1
4.00 3.00 2.40

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(3, 4, 5))
}

/*

https://im.kendallhunt.com/MS_ACC/students/1/1/8/index.html
base = 2*area / height =>
height = 2*area / base
Which height we calculate depends on which side we pick as a base (it leads to different results)

*/

func solve(a, b, c float64) (ha, hb, hc float64) {
	A := heron(a, b, c)
	ha = 2 * A / a
	hb = 2 * A / b
	hc = 2 * A / c
	return
}

func heron(a, b, c float64) float64 {
	s := (a + b + c) / 2
	return math.Sqrt(s * (s - a) * (s - b) * (s - c))
}
