/*

Given a natural number N.

Write a program that calculates how many natural numbers, not exceeding N, are not divisible by any of the numbers 2, 3, or 5.

Input
A single line containing the number N (1≤N≤1000000000).

Output
Output the number found.

Examples

Input #1
10

Answer #1
2

*/

package main

func main() {
	assert(solve(10) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	return n - n/2 - n/3 - n/5 + n/6 + n/10 + n/15 - n/30
}
