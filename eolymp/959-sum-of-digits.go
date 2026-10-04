/*

Find the sum of the first and last digits of a four-digit natural number.

Input
One four-digit natural number.

Output
Print the sum of the first and last digits of the number.

Examples

Input #1
1235

Answer #1
6

*/

package main

func main() {
	assert(solve(1235) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n uint) uint {
	return n%10 + (n/1000)%10
}
