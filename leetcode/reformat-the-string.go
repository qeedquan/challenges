/*

You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.

Hint:
Count the number of letters and digits in the string. if cntLetters - cntDigits has any of the values [-1, 0, 1] we have an answer, otherwise we don't have any answer.
Build the string anyway as you wish. Keep in mind that you need to start with the type that have more characters if cntLetters ≠ cntDigits.

*/

package main

import (
	"bytes"
	"unicode"
)

func main() {
	assert(reformat("a0b1c2") == "a0b1c2")
	assert(reformat("leetcode") == "")
	assert(reformat("1229857369") == "")
	assert(reformat("a0b1c23") == "0a1b2c3")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reformat(s string) string {
	var l, d []rune
	for _, r := range s {
		if !unicode.IsDigit(r) {
			l = append(l, r)
		} else {
			d = append(d, r)
		}
	}

	f, n, m := 0, len(l), len(d)
	if abs(n-m) > 1 {
		return ""
	}
	if n < m {
		f = 1
	}

	w := new(bytes.Buffer)
	for i, j := 0, 0; i < n || j < m; f ^= 1 {
		switch f {
		case 0:
			w.WriteRune(l[i])
			i++
		case 1:
			w.WriteRune(d[j])
			j++
		}
	}
	return w.String()
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
