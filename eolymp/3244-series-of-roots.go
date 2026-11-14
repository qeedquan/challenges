/*

Consider the sum

S = Sum[x=l to r] floor(sqrt(x))

Given integers l and r, compute the value of S.

Input
The first line contains one integer t (1≤t≤100 000) — the number of test cases. Each of the following t lines contains two integers l and r (1≤l≤r≤10^18).

Output
For each test case, output the value of S in a separate line.

Examples
Input #1
4
1 2
1 5
2 4
9 10

Answer #1
2
7
4
6

*/

package main

import (
	"math"
)

func main() {
	tab := []int{
		0, 1, 2, 3, 5, 7, 9, 11, 13, 16, 19, 22, 25, 28, 31, 34, 38, 42, 46,
		50, 54, 58, 62, 66, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120,
		125, 131, 137, 143, 149, 155, 161, 167, 173, 179, 185, 191, 197, 203,
		210, 217, 224, 231, 238, 245, 252, 259, 266, 273, 280,
	}

	for i := range tab {
		assert(seq(i) == tab[i])
	}

	assert(solve(1, 2) == 2)
	assert(solve(1, 5) == 7)
	assert(solve(2, 4) == 4)
	assert(solve(9, 10) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int) int {
	return seq(b) - seq(a-1)
}

// https://math.stackexchange.com/questions/1247092/sum-of-floor-of-square-root-s-sum-k-1n-lfloor-sqrtk-rfloor
// https://oeis.org/A022554
func seq(n int) int {
	if n < 1 {
		return 0
	}

	m := int(math.Sqrt(float64(n)))
	return n*m - m*(m+1)*(2*m+1)/6 + m
}
