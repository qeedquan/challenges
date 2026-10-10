/*

The people of Mohammadpur have decided to paint each of their houses red, green, or blue. They've also decided that no two neighboring houses will be painted the same color. The neighbors of house i are houses i-1 and i+1. The first and last houses are not neighbors.

You will be given the information of houses. Each house will contain three integers "R G B" (quotes for clarity only), where R, G and B are the costs of painting the corresponding house red, green, and blue, respectively. Return the minimal total cost required to perform the work.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case begins with a blank line and an integer n (1 ≤ n ≤ 20) denoting the number of houses. Each of the next n lines will contain 3 integers "R G B". These integers will lie in the range [1, 1000].

Output
For each case of input you have to print the case number and the minimal cost.

Sample
Input	Output
2

4
13 23 12
77 36 64
44 89 76
31 78 45

3
26 40 83
49 60 57
13 89 99

Case 1: 137
Case 2: 96

*/

package main

import (
	"math"
)

func main() {
	assert(solve([][3]int{
		{13, 23, 12},
		{77, 36, 64},
		{44, 89, 76},
		{31, 78, 45},
	}) == 137)

	assert(solve([][3]int{
		{26, 40, 83},
		{49, 60, 57},
		{13, 89, 99},
	}) == 96)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a [][3]int) int {
	n := len(a)
	c := make([][5]int, n+5)
	for i := 1; i <= n; i++ {
		for j := 1; j <= 3; j++ {
			c[i][j] = a[i-1][j-1]
		}
	}

	p := make([][5]int, n+5)
	for i := range p {
		for j := range p[i] {
			p[i][j] = math.MaxInt / 2
		}
	}
	for i := 1; i <= 3; i++ {
		p[0][i] = 0
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= 3; j++ {
			for k := 1; k <= 3; k++ {
				if j != k {
					p[i][j] = min(p[i][j], c[i][j]+p[i-1][k])
				}
			}
		}
	}
	r := math.MaxInt
	for i := 1; i <= 3; i++ {
		r = min(r, p[n][i])
	}

	return r
}
