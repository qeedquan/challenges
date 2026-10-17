/*

Find the number of odd digits in a positive integer n.

Input
One positive integer n (n<10^18).

Output
Print the number of odd digits in positive integer n.

Examples

Input #1
2354

Answer #1
2

Input #2
606432232464677

Answer #2
4

*/

package main

func main() {
	assert(solve(2354) == 2)
	assert(solve(606432232464677) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n uint64) uint64 {
	r := uint64(0)
	for ; n > 0; n /= 10 {
		r += (n % 10) & 1
	}
	return r
}
