/*

A token for one metro trip costs 4 UAH. If more trips are planned, then you can purchase a ticket,
which price for 10 trips is 30 UAH, for 50 - 125 UAH, and for 100 - 200 UAH.
What is the minimum sum you need to spend to pay for at least m metro rides?

Input
One positive integer m (1≤m≤1000).

Output
Print the required minimum sum.

Examples
Input #1
25

Answer #1
80

*/

package main

import (
	"math"
)

func main() {
	assert(solve(25) == 80)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 0 {
		return 0
	}

	p := make([]int, n+101)
	p[1] = 4
	for i := 2; i <= n+100; i++ {
		p[i] = p[i-1] + 4
		if i >= 10 {
			p[i] = min(p[i], p[i-10]+30)
		}
		if i >= 50 {
			p[i] = min(p[i], p[i-50]+125)
		}
		if i >= 100 {
			p[i] = min(p[i], p[i-100]+200)
		}
	}

	r := math.MaxInt
	for i := n; i <= n+100; i++ {
		r = min(r, p[i])
	}
	return r
}
