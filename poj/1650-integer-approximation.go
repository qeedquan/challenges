/*

Description

The FORTH programming language does not support floating-point arithmetic at all. Its author, Chuck Moore, maintains that floating-point calculations are too slow and most of the time can be emulated by integers with proper scaling. For example, to calculate the area of the circle with the radius R he suggests to use formula like R * R * 355 / 113, which is in fact surprisingly accurate. The value of 355 / 113 ≈ 3.141593 is approximating the value of PI with the absolute error of only about 2*10-7. You are to find the best integer approximation of a given floating-point number A within a given integer limit L. That is, to find such two integers N and D (1 <= N, D <= L) that the value of absolute error |A - N / D| is minimal.
Input

The first line of input contains a floating-point number A (0.1 <= A < 10) with the precision of up to 15 decimal digits. The second line contains the integer limit L. (1 <= L <= 100000).
Output

Output file must contain two integers, N and D, separated by space.
Sample Input

3.14159265358979
10000
Sample Output

355 113
Source

Northeastern Europe 2001, Far-Eastern Subregion

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(3.14159265358979, 10000, 355, 113)
	test(100, 10000, 100, 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x float64, n int, ra, rb int) {
	a, b := approximate(x, n)
	fmt.Println(a, b)
	assert(a == ra && b == rb)
}

func approximate(x float64, n int) (int, int) {
	i, f := math.Modf(x)
	a, b := farey(f, n)
	a += int(i) * b
	return a, b
}

// https://www.johndcook.com/blog/2010/10/20/best-rational-approximation/
func farey(x float64, n int) (int, int) {
	a, b := 0, 1
	c, d := 1, 1
	for b <= n && d <= n {
		m := float64(a+c) / float64(b+d)
		switch {
		case x == m:
			switch {
			case b+d <= n:
				return a + c, b + d
			case d > b:
				return c, d
			default:
				return a, b
			}
		case x > m:
			a, b = a+c, b+d
		default:
			c, d = a+c, b+d
		}
	}

	if b > n {
		return c, d
	}
	return a, b
}
