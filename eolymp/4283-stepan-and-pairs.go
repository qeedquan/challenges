/*

Stepan is interested in the greatest common divisor of a pair of numbers, namely GCD(x,y).
Given an integer n, Stepan wants to know how many pairs of integers (i,j) exist such that 1≤i,j≤n and i=GCD(i,j).

Input
One integer n (1≤n≤10^6).

Output
Print the number of such pairs.

Examples

Input #1
4

Answer #1
8

*/

package main

import "math"

func main() {
	tab := []int{
		0, 1, 3, 5, 8, 10, 14, 16, 20, 23, 27, 29, 35, 37, 41, 45, 50, 52, 58,
		60, 66, 70, 74, 76, 84, 87, 91, 95, 101, 103, 111, 113, 119, 123, 127,
		131, 140, 142, 146, 150, 158, 160, 168, 170, 176, 182, 186, 188, 198,
		201, 207, 211, 217, 219, 227, 231, 239, 243, 247, 249,
	}

	for i := range tab {
		assert(solve(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A006218
func solve(n int) int {
	if n < 0 {
		return 0
	}

	s := int(math.Sqrt(float64(n)))
	r := 0
	for i := 1; i <= s; i++ {
		r += n / i
	}
	return (2 * r) - (s * s)
}
