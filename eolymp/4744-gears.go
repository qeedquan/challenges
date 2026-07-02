/*

Consider two interconnected gears. One gear has N teeth, and the other has K teeth.

Your task is to determine the minimum number of rotations per tooth needed for both gears to return to their starting positions.

Input
The input consists of a single line containing two integers, N and K (1≤N,K≤10^7).

Output
Output the minimum number of teeth rotations required.
It is guaranteed that this number will not exceed 10^9.

Examples

Input #1
3 4

Answer #1
12

*/

package main

func main() {
	assert(solve(3, 4) == 12)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, k int) int {
	x := n
	for y := k; y != 0; x, y = y, x {
		x %= y
	}
	return (n / x) * k
}
