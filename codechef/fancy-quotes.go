/*

"I don't have any fancy quotes." - vijju123

Chef was reading some quotes by great people. Now, he is interested in classifying all the fancy quotes he knows.
He thinks that all fancy quotes which contain the word "not" are Real Fancy; quotes that do not contain it are regularly fancy.

You are given some quotes. For each quote, you need to tell Chef if it is Real Fancy or just regularly fancy.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S denoting a quote.

Output

For each test case, print a single line containing the string "Real Fancy" or "regularly fancy" (without quotes).

Constraints
1≤T≤50
1≤|S|≤100
each character of S is either a lowercase English letter or a space

*/

package main

import (
	"regexp"
)

func main() {
	assert(fancy("i do not have any fancy quotes") == "Real Fancy")
	assert(fancy("when nothing goes right go left") == "regularly fancy")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fancy(s string) string {
	matched, err := regexp.MatchString("\\bnot\\b", s)
	if matched && err == nil {
		return "Real Fancy"
	}
	return "regularly fancy"
}
