/*

A palindrome partition is the partitioning of a string such that each separate substring is a palindrome.

For example, the string ABACABA can be partitioned in several different ways. A few are: {A, B, A, C, A, B, A} or {A, BACAB, A} or {ABACABA} or {ABA, C, ABA} among many other solutions.

You are given a string s. Return the minimum possible number of substrings in a palindrome partition of s.

Input
Input starts with an integer T (≤ 40), denoting the number of test cases.

Each case begins with a non-empty string s of uppercase letters with length no more than 1000.

Output
For each case of input you have to print the case number and the desired result.

Sample
Input	Output
3
AAAA
ABCDEFGH
QWERTYTREWQWERT

Case 1: 1
Case 2: 8
Case 3: 5

*/

package main

func main() {
	assert(solve("AAAA") == 1)
	assert(solve("ABCDEFGH") == 8)
	assert(solve("QWERTYTREWQWERT") == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	}

	p := make([][]bool, n)
	for i := 0; i < n; i++ {
		p[i] = make([]bool, n)
		for j := 0; j <= i; j++ {
			p[i][j] = true
		}
	}

	for l := 2; l <= n; l++ {
		for i := 0; i+l-1 < n; i++ {
			j := i + l - 1
			p[i][j] = p[i+1][j-1] && (s[i] == s[j])
		}
	}

	r := make([]int, n)
	for i := range r {
		r[i] = n
	}

	for j := 0; j < n; j++ {
		for i := j; i >= 0; i-- {
			if p[i][j] {
				v := 0
				if i > 0 {
					v = r[i-1]
				}
				r[j] = min(r[j], v+1)
			}
		}
	}
	return r[n-1]
}
