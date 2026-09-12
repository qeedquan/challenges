/*

Given two natural numbers n and m, determine how many even natural numbers with exactly n digits are greater than m.

Input
Two natural numbers n and m provided on a single line, separated by a space (1≤n≤12, 1≤m≤10^12).

Output
Output the number of even n-digit numbers that are greater than m.

Examples
Input #1
2 72

Answer #1
13

*/

package main

import "math"

func main() {
	assert(solve(2, 72) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, m int) int {
	a := ipow10(n - 1)
	b := ipow10(n) - 1
	return count(max(a, m+1), b)
}

func count(a, b int) int {
	if a > b {
		return 0
	}

	k := b - a + 1
	r := k / 2
	if k&1 != 0 {
		if a&1 == 0 && b&1 == 0 {
			r += 1
		}
	}
	return r
}

func ipow10(n int) int {
	return int(math.Pow(10, float64(n)))
}
