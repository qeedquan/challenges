/*

For the given three-digit number n find the sum of the three-digit numbers formed by all possible permutations of the digits of the number n, including the identical one.

Input
Three-digit positive integer n.

Output
Print the required sum.

Examples

Input #1
123

Answer #1
1332

*/

package main

func main() {
	assert(solve(123) == 1332)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	a := (n / 100) % 10
	b := (n / 10) % 10
	c := n % 10
	return a*100 + b*10 + c +
		a*100 + c*10 + b +
		b*100 + c*10 + a +
		b*100 + a*10 + c +
		c*100 + a*10 + b +
		c*100 + b*10 + a
}
