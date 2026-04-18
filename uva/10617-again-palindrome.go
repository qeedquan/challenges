/*

A palindorme is a sequence of one or more characters that reads the same from the left as it does from
the right. For example, Z, TOT and MADAM are palindromes, but ADAM is not.
Given a sequence S of N capital latin letters. How many ways can one score out a few symbols
(maybe 0) that the rest of sequence become a palidrome. Varints that are only different by an order of
scoring out should be considered the same.

Input
The input file contains several test cases (less than 15). The first line contains an integer T that
indicates how many test cases are to follow.
Each of the T lines contains a sequence S (1 ≤ N ≤ 60). So actually each of these lines is a test case.

Output
For each test case output in a single line an integer — the number of ways.

Sample Input
3
BAOBAB
AAAA
ABA

Sample Output
22
15
5

*/

package main

func main() {
	assert(solve("BAOBAB") == 22)
	assert(solve("AAAA") == 15)
	assert(solve("ABA") == 5)
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

	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, n)
	}

	for i := range n {
		p[i][i] = 1
	}

	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				p[i][j] = p[i][j-1] + p[i+1][j] + 1
			} else {
				p[i][j] = p[i][j-1] + p[i+1][j] - p[i+1][j-1]
			}
		}
	}
	return p[0][n-1]
}
