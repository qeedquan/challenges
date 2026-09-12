/*

Integer n is given. Print the previous even number for n.

Input
One integer n.

Output
Print the even number before n.

Examples
Input #1
7

Answer #1
6

Input #2
6

Answer #2
4

*/

package main

func main() {
	assert(solve(7) == 6)
	assert(solve(6) == 4)
	assert(solve(5) == 4)
	assert(solve(4) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	return n - 1 - ((n & 1) ^ 1)
}
