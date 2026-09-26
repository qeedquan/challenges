/*

Challenge
Given a positive-length string S, a divisor of S is another (not necessarily distinct) string for which there exists a number a such that when we repeat the divisor a times, we get the string S.

For example, the string abcd is a divisor of the string abcdabcd with a=2.

Your challenge is, given a positive-length string S, output all of S's divisors.

For example, the string aaaa has three divisors: a, aa, and aaaa.

Input/Output
Input/output can be taken in any reasonable format for taking a string and returning the set of divisors of that string.

The input string will only has lowercase characters, and it contains no whitespace or special characters.

The output list should not contains any duplicates. The strings can appear in any order.

Testcase:

Input -> Output
abcdabcd -> abcd, abcdabcd
aaa -> a, aaa
aaaaaaaa -> a, aa, aaaa, aaaaaaaa
abcdef -> abcdef

This is code-golf, so shortest answer (in bytes) wins!

*/

package main

import (
	"fmt"
	"slices"
	"strings"
)

func main() {
	test("abcdabcd", []string{"abcd", "abcdabcd"})
	test("aaa", []string{"a", "aaa"})
	test("aaaaaaaa", []string{"a", "aa", "aaaa", "aaaaaaaa"})
	test("abcdef", []string{"abcdef"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []string) {
	p := strdivisor(s)
	fmt.Println(p)
	assert(slices.Equal(p, r))
}

func strdivisor(s string) []string {
	r := []string{}
	n := len(s)
	for i := 1; i <= n; i++ {
		if n%i != 0 {
			continue
		}

		t := s[:i]
		if s == strings.Repeat(t, n/i) {
			r = append(r, t)
		}
	}
	return r
}
