/*

A biquadratic number is a number that is the fourth power of another integer, for example: 3^4 = 3*3*3*3 = 81

Given an integer as input, output the closest biquadratic number.

Here are the first 15 double-squares:

1, 16, 81, 256, 625, 1296, 2401, 4096, 6561, 10000, 14641, 20736, 28561, 38416, 50625
This is code-golf so fewest bytes in each language wins

This is OEIS A000583

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	for i := 0; i <= 10000; i++ {
		fmt.Println(i, biquadratic(i))
	}
}

func biquadratic(n int) int {
	i := sort.Search(n, func(x int) bool {
		return ipow4(x) >= n
	})

	x := ipow4(i)
	y := ipow4(i - 1)
	if abs(x-n) > abs(y-n) {
		return y
	}
	return x
}

// https://oeis.org/A000583
func ipow4(n int) int {
	return n * n * n * n
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
