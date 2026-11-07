/*

Find the value of y according to condition:

y = 3x^3 + 4x^2 + 5x + 6, x >= 13
    3x^3 - 2x^2 - 3x - 4, x < 13

Input
One integer x (−1000≤x≤1000).

Output
Print the value of y according to the conditional statement above.

Examples
Input #1
8

Answer #1
1380

Input #2
-11

Answer #2
-4206

*/

package main

func main() {
	assert(solve(8) == 1380)
	assert(solve(-11) == -4206)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x int) int {
	if x >= 13 {
		return 3*x*x*x + 4*x*x + 5*x + 6
	}
	return 3*x*x*x - 2*x*x - 3*x - 4
}
