/*

Find the number of trailing zeroes for the following function:

binomial(n, r) * p^q

where n, r, p, q are given as Input.

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case contains four integers: n, r, p, q (1 ≤ n, r, p, q ≤ 106, r ≤ n).

Output
For each test case, print the case number and the number of trailing zeroes.

Sample
Input	Output
2
10 4 1 1
100 5 40 5

Case 1: 1
Case 2: 6

Notes
For case 1, n = 10, r = 4, p = 1, q = 1, then the result is 210 and number of trailing zeroes is 1.

*/

package main

func main() {
	assert(solve(10, 4, 1, 1) == 1)
	assert(solve(100, 5, 40, 5) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, r, p, q int) int {
	f := n - r
	i := ilog(n, 2)
	j := ilog(n, 5)
	k := ilog(r, 2)
	l := ilog(r, 5)
	m := ilog(f, 2)
	o := ilog(f, 5)
	x := factor(p, 2)
	y := factor(p, 5)
	return min(i-k-m+(x*q), j-l-o+(y*q))
}

func ilog(n, x int) int {
	if x == 0 {
		return 0
	}

	c := 0
	for ; n > 0; n /= x {
		c += n / x
	}
	return c
}

func factor(n, x int) int {
	if x == 0 {
		return 0
	}

	c := 0
	for ; n%x == 0; n /= x {
		c += 1
	}
	return c
}
