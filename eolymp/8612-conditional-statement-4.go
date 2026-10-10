/*

Find the value of y according to condition:

y = x^3 + 2x^2 + 4x - 6    x >= 0
    x^3 - 7x               x < 0

Input
One integer x (−1000≤x≤1000).

Output
Print the value of y according to the conditional statement above.

Examples

Input #1
3

Answer #1
51

Input #2
-2

Answer #2
6

*/

package main

func main() {
	assert(solve(3) == 51)
	assert(solve(-2) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x int) int {
	if x >= 0 {
		return x*x*x + 2*x*x + 4*x - 6
	}
	return x*x*x - 7*x
}
