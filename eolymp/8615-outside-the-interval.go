/*

Determine whether the number x is outside the interval [a;b]. The number x is outside the interval [a;b] if x<a or x>b.

Input
Three integers x,a,b (a≤b), each not exceeding 10^9 in absolute value.

Output
Print "OUT" if x is outside the interval [a;b]. Otherwise, print "IN".

Examples

Input #1
7 2 7

Answer #1
IN

Input #2
-5 1 1

Answer #2
OUT

*/

package main

func main() {
	assert(solve(7, 2, 7) == "IN")
	assert(solve(-5, 1, 1) == "OUT")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x, a, b int) string {
	if x < a || x > b {
		return "OUT"
	}
	return "IN"
}
