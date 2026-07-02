/*

Write a program that, given two numbers a and n, outputs the representation of the number a in n-bit binary two's complement code.

Input
Single line contains two numbers a and n (2≤n≤16, -2^(n−1) ≤ a ≤ 2^(n−1) − 1).

Output
Print a string of n digits representing the number a in n-bit binary two's complement code, where the first digit is the most significant (sign) bit.

Examples
Input #1
5 8

Answer #1
00000101
Input #2
-5 8

Answer #2
11111011

*/

package main

import "fmt"

func main() {
	assert(solve(5, 8) == "00000101")
	assert(solve(-5, 8) == "11111011")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a int, n uint) string {
	x := uint(a) & (1<<n - 1)
	return fmt.Sprintf("%0*b", n, x)
}
