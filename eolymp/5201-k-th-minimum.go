/*

Find the k-th number in array A=⟨a1,a2,…,an⟩ sorted in increasing order.

Array A is generated with the polynomial
P(x) = 132x^3 + 77x^2 + 1345x + 1577
a(i) = P(i) mod 1743

Input
Two positive integers n and k (1≤k≤n≤50000).

Output
Print the k-th number in sorted array A.

Examples

Input #1
1 1

Answer #1
1388

Input #2
2 2

Answer #2
1388

*/

package main

import (
	"sort"
)

func main() {
	assert(solve(1, 1) == 1388)
	assert(solve(2, 2) == 1388)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, k int) int {
	p := gen(n)
	return p[k]
}

func gen(n int) []int {
	m := 1743
	p := make([]int, n+1)
	for i := 1; i <= n; i++ {
		p[i-1] = f(i, m)
	}
	sort.Ints(p)
	return p
}

func f(x, m int) int {
	return ((((x*x)%m)*x*132)%m + (((77*x)%m)*x)%m + (1345*x)%m + 1577) % m
}
