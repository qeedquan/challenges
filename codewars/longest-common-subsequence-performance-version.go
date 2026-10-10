/*

from Wikipedia:
The longest common subsequence (LCS) problem is the problem of finding the longest subsequence common to all sequences in a set of sequences.
It differs from problems of finding common substrings: unlike substrings, subsequences are not required to occupy consecutive positions within the original sequences.

Task
Write a function lcs that accepts two strings and returns their longest common subsequence as a string. Performance matters.

Examples
lcs( "abcdef", "abc" ) => "abc"
lcs( "abcdef", "acf" ) => "acf"
lcs( "132535365", "123456789" ) => "12356"
lcs( "abcdefghijklmnopq", "apcdefghijklmnobq" ) => "acdefghijklmnoq"
Testing
This is a performance version of xDranik's kata of the same name.
This kata, however, has much more full and heavy testing. Intermediate random tests have string arguments of 20 characters; hard random tests 40 characters; extreme 60 characters (characters are chosen out of 36 different ones).

Notes
The subsequences of "abc" are "", "a", "b", "c", "ab", "ac", "bc", "abc".
"" is a valid subsequence in this kata, and a possible return value.
All inputs will be valid.
Two strings may have more than one longest common subsequence. When this occurs, return any of them.

lcs( string0, string1 ) === lcs( string1, string0 )
Wikipedia has an article that may be helpful.

*/

package main

import "slices"

func main() {
	assert(lcs("", "") == "")
	assert(lcs("abc", "") == "")
	assert(lcs("", "abc") == "")
	assert(lcs("a", "b") == "")
	assert(lcs("a", "a") == "a")
	assert(lcs("abc", "ac") == "ac")
	assert(lcs("abcdef", "abc") == "abc")
	assert(lcs("abcdef", "acf") == "acf")
	assert(lcs("anothertest", "notatest") == "nottest")
	assert(lcs("132535365", "123456789") == "12356")
	assert(lcs("nothardlythefinaltest", "zzzfinallyzzz") == "final")
	assert(lcs("abcdefghijklmnopq", "apcdefghijklmnobq") == "acdefghijklmnoq")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://www.geeksforgeeks.org/printing-longest-common-subsequence/
func lcs(s, t string) string {
	m := len(s)
	n := len(t)
	L := make([][]int, m+1)
	for i := range L {
		L[i] = make([]int, n+1)
	}

	for i := range m + 1 {
		for j := range n + 1 {
			switch {
			case i == 0 || j == 0:
				L[i][j] = 0
			case s[i-1] == t[j-1]:
				L[i][j] = L[i-1][j-1] + 1
			default:
				L[i][j] = max(L[i-1][j], L[i][j-1])
			}
		}
	}

	r := []byte{}
	for i, j := m, n; i > 0 && j > 0; {
		switch {
		case s[i-1] == t[j-1]:
			r = append(r, s[i-1])
			i -= 1
			j -= 1
		case L[i-1][j] > L[i][j-1]:
			i -= 1
		default:
			j -= 1
		}
	}

	slices.Reverse(r)
	return string(r)
}
