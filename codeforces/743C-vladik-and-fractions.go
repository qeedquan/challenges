/*

Vladik and Chloe decided to determine who of them is better at math. Vladik claimed that for any positive integer 2/n he can represent fraction  as a sum of three distinct positive fractions in form 1/m.

Help Vladik with that, i.e for a given n find three distinct positive integers x, y and z such that 2/n = 1/x + 1/y + 1/z. Because Chloe can't check Vladik's answer if the numbers are large, he asks you to print numbers not exceeding 10^9.

If there is no such answer, print -1.

Input
The single line contains single integer n (1 ≤ n ≤ 10^4).

Output
If the answer exists, print 3 distinct numbers x, y and z (1 ≤ x, y, z ≤ 10^9, x ≠ y, x ≠ z, y ≠ z). Otherwise print -1.

If there are multiple answers, print any of them.

Examples

input
3
output
2 7 42

input
7
output
7 8 56

*/

package main

import (
	"math/big"
)

func main() {
	for i := int64(0); i <= 1000000; i++ {
		test(i)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int64) {
	x, y, z := represent(n)
	if x < 0 {
		return
	}

	A := big.NewRat(2, n)
	B := big.NewRat(1, x)
	C := big.NewRat(1, y)
	D := big.NewRat(1, z)

	B.Add(B, C)
	B.Add(B, D)

	assert(x != y && x != z && y != z)
	assert(A.Cmp(B) == 0)
}

func represent(n int64) (int64, int64, int64) {
	if n < 2 {
		return -1, -1, -1
	}
	return n, n + 1, n * (n + 1)
}
