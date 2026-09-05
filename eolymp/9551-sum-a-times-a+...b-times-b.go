/*

Given two positive integers a and b, find the sum of the squares of all numbers from a to b, i.e., a^2+(a+1)^2+…+b^2.

Input
Two positive integers a and b (1≤a≤b≤1000).

Output
Print the value of the specified sum.

Examples

Input #1
3 7

Answer #1
135

*/

package main

func main() {
	assert(solve(3, 7) == 135)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int) int {
	if a > b {
		a, b = b, a
	}
	return sos(b) - sos(a-1)
}

func sos(n int) int {
	if n < 0 {
		return 0
	}
	return n * (n + 1) * (2*n + 1) / 6
}
