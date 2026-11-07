/*

It is well known that if the square root of a natural number is not an integer, then it is irrational. The decimal expansion of such square roots is infinite without any repeating pattern at all.

The square root of two is 1.41421356237309504880..., and the digital sum of the first one hundred decimal digits is 475.

For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits for all the irrational square roots.

*/

package main

import (
	"fmt"
	"math"
	"math/big"
	"strings"
)

func main() {
	fmt.Println(solve(2))
	fmt.Println(solve(100))
}

func solve(n int) int {
	r := 0
	for i := 1; i <= n; i++ {
		if !issquare(i) {
			v := sqrtex(i, 100)
			r += digitsum(v)
		}
	}
	return r
}

func issquare(x int) bool {
	s := math.Sqrt(float64(x))
	return int(s)*int(s) == x
}

func sqrtex(x int, prec int) string {
	z := big.NewFloat(float64(x))
	z.SetPrec(4 * uint(prec))
	z.Sqrt(z)

	s := z.Text('f', prec+1)
	s = strings.Replace(s, ".", "", -1)

	return s[:len(s)-2]
}

func digitsum(s string) int {
	r := 0
	for _, c := range s {
		r += int(c - '0')
	}
	return r
}
