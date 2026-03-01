/*

There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.


Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.

*/

package main

func main() {
	assert(strangeprinter("aaabbb") == 2)
	assert(strangeprinter("aba") == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func strangeprinter(s string) int {
	if s == "" {
		return 0
	}

	n := len(s)
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, n)
		for j := range p[i] {
			p[i][j] = n
		}
	}

	for i := 0; i < n; i++ {
		p[i][i] = 1
	}

	for j := 0; j < n; j++ {
		for i := j; i >= 0; i-- {
			for k := i; k < j; k++ {
				p[i][j] = min(p[i][j], p[i][k]+p[k+1][j]-truth(s[k] == s[j]))
			}
		}
	}

	return p[0][n-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
