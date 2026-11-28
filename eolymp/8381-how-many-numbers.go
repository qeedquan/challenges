/*

At the faculty of mathematics, Orhan was faced with the following problem: find the number of positive integers from 1 to 10^n, in which all digits are different.

Since Orhan also goes to computer science classes at FizMat Lyceum, he easily wrote a program that calculates the answer. And can you do it?

Input
One integer n (1≤n≤18).

Output
Print the number of required positive integers.

Examples

Input #1
1

Answer #1
9

Input #2
2

Answer #2
90

*/

package main

func main() {
	assert(solve(1) == 9)
	assert(solve(2) == 90)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	return count(min(n, 10))
}

func count(n int) int {
	if n < 1 {
		return 0
	}
	if n == 1 {
		return 9
	}

	n = min(n, 10)
	r := 1
	s := 9
	for i := 1; i <= n; i++ {
		if i > 2 {
			s -= 1
		}
		r *= s
	}
	return r + count(n-1)
}
