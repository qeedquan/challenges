/*

Two different integers k and n are given. Print the value 2^k+2^n, using bit operations only.

Input
Two different integers k and n (0≤k,n≤30).

Output
Print the number 2^k+2^n.

Examples
Input #1
0 1

Answer #1
3

*/

package main

func main() {
	assert(solve(0, 1) == 3)
	assert(solve(10, 11) == 3072)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(k, n uint) uint {
	return 1<<k | 1<<n
}
