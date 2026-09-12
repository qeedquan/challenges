/*

Four integers are given. Find the maximum among them.

Input
Four integers a,b,c,d, each not exceeding 1000 in absolute value.

Output
Print the maximum among four numbers.

Examples

Input #1
1 2 3 4

Answer #1
4

*/

package main

func main() {
	assert(solve(1, 2, 3, 4) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, c, d int) int {
	return max(a, b, c, d)
}
