/*

In how many ways can you tile a 3×n rectangle with 2×1 dominoes? Below is a sample tiling of a 3×12 rectangle.

https://static.e-olymp.com/content/eb/eb1f59e1a236e586e215416266f75eef921f6cc0.jpg

Input
The input consists of several test cases, ending with a line containing −1. Each line contains a single integer n (0≤n≤30).

Output
For each test case, output the number of possible tilings on a separate line.

Examples

Input #1
2
8
12
-1

Answer #1
3
153
2131

*/

package main

import (
	"math"
)

var (
	SQRT3 = math.Sqrt(3)
)

func main() {
	assert(solve(2) == 3)
	assert(solve(8) == 153)
	assert(solve(12) == 2131)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://oeis.org/A001835
https://oeis.org/A079935

https://stackoverflow.com/questions/4803805/in-how-many-ways-can-you-tile-a-3xn-rectangle-with-2x1-dominoes

*/

func solve(n int) int {
	if n < 0 || n&1 != 0 {
		return 0
	}
	p := float64(n) / 2
	a := (1 + SQRT3) / (2 * SQRT3)
	c := (1 - SQRT3) / (2 * SQRT3)
	b := math.Pow(2+SQRT3, p)
	d := math.Pow(2-SQRT3, p)
	r := math.Round(a*b + c*d)
	return int(r)
}
