/*

Ivan Petrovich teaches physical education at school, but is also interested in mathematics, mainly from a practical point of view.
For example, he wonders how many different formations exist for a group of N people.
Ivan Petrovich found that if N is a prime number, there are only 2 possible formations: one in a column (1×N) and one in a row (N×1).
These trivial formations are possible for any N>1 (for N=1, there is only one formation 1×1, which is neither a row nor a column).
If N is a composite number, there are other non-trivial formations as well.
For example, for 100 people, there are nine possible formations: 1×100, 2×50, 4×25, 5×20, 10×10, 20×5, 25×4, 50×2, and 100×1.

Write a program that finds the number of different formations for a group of N people.

Input
The first line contains one integer N (1≤N≤10^9).

Output
Output one integer: the number of different formations for a group of N people.

Examples
Input #1
1

Answer #1
1

*/

package main

import (
	"math"
)

func main() {
	tab := []int{
		1, 2, 2, 3, 2, 4, 2, 4, 3, 4, 2, 6, 2, 4, 4, 5, 2, 6, 2, 6, 4, 4, 2, 8,
		3, 4, 4, 6, 2, 8, 2, 6, 4, 4, 4, 9, 2, 4, 4, 8, 2, 8, 2, 6, 6, 4, 2, 10,
		3, 6, 4, 6, 2, 8, 4, 8, 4, 4, 2, 12, 2, 4, 6, 7, 4, 8, 2, 6, 4, 8, 2,
		12, 2, 4, 6, 6, 4, 8, 2, 10, 5, 4, 2, 12, 4, 4, 4, 8, 2, 12, 4, 6, 4,
		4, 4, 12, 2, 6, 6, 9, 2, 8, 2, 8,
	}

	assert(solve(1) == 1)
	for i := range tab {
		assert(solve(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A000005
func solve(n int) int {
	if n < 1 {
		return 0
	}

	x := 0
	y := 0
	s := int(math.Sqrt(float64(n)))
	for i := 1; i <= s; i++ {
		if n%i != 0 {
			continue
		}

		x += 1
		if n/i == n/(n/i) {
			y += 1
		}
	}
	return 2*x - y
}
