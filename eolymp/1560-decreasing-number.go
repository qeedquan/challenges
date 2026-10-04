/*

You can perform the following operations on a positive integer:

If the number is divisible by 3, divide it by 3;

If the number is divisible by 2, divide it by 2;

Subtract 1.

Given a positive integer n, find the minimum number of operations required to obtain 1 from n.

Input
Each line contains a single positive integer n (1≤n≤10^6).

Output
For each n, print the minimum number of operations required to obtain 1 on a separate line.

Examples

Input #1
1
5
10

Answer #1
0
3
3

*/

package main

import (
	"math"
)

func main() {
	assert(solve(1) == 0)
	assert(solve(5) == 3)
	assert(solve(10) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A056796 (related)
func solve(n int) int {
	if n < 0 {
		return 0
	}

	p := make([]int, n+2)
	for i := range p {
		p[i] = math.MaxInt
	}

	p[n] = 0
	p[1] = 0
	for i := n - 1; i >= 1; i-- {
		d1 := p[i+1] + 1
		d2 := math.MaxInt
		d3 := math.MaxInt
		if i*3 <= n {
			d2 = p[i*3] + 1
		}
		if i*2 <= n {
			d3 = p[i*2] + 1
		}
		p[i] = min(d1, d2, d3)
	}
	return p[1]
}
