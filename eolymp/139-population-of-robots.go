/*

Population — a group of individuals of the same species occupying a bounded area, freely interbreeding, having a common origin and genetic basis,
and to some extent isolated from other populations of the same species (definition taken from Wikipedia, not directly related to the problem).

Suppose that A robots can produce C robots in one year, and B robots can produce D robots in one year.

Initially, there are N robots. What is the maximum possible number of robots after K years?

Input
The input contains six integers: A,B,C,D,N,K, where 1≤A,B,C,D,N,K≤10.

Output
Output a single integer — the maximum possible number of robots after K years.

Examples

Input #1
3 4 2 3 7 2

Answer #1
21

*/

package main

func main() {
	assert(solve(3, 4, 2, 3, 7, 2) == 21)
}

func assert(x bool) {
	if !x {
		panic("Assertion failed")
	}
}

func solve(a, b, c, d, n, k int) int {
	p := make([]int, k+1)
	p[0] = n
	for i := 1; i <= k; i++ {
		for ka := p[i-1] / a; ka >= 0; ka-- {
			kb := (p[i-1] - ka*a) / b
			p[i] = max(p[i], p[i-1]+ka*c+kb*d)
		}
	}
	return p[k]
}
