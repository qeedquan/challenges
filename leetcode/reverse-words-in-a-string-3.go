/*

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "God Ding"
Output: "doG gniD"

Constraints:

    1 <= s.length <= 5 * 10^4
    s contains printable ASCII characters.
    s does not contain any leading or trailing spaces.
    There is at least one word in s.
    All the words in s are separated by a single space.

*/

package main

import (
	"bytes"
	"unicode"
)

func main() {
	assert(revwords("Let's take LeetCode contest") == "s'teL ekat edoCteeL tsetnoc")
	assert(revwords("God Ding") == "doG gniD")
	assert(revwords("tick") == "kcit")
	assert(revwords("    wasd\t") == "    dsaw\t")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func revwords(s string) string {
	w := new(bytes.Buffer)
	p := -1
	for i, r := range s {
		if unicode.IsSpace(r) {
			if p >= 0 {
				w.WriteString(rev(s[p:i]))
				p = -1
			}
			w.WriteRune(r)
		} else if p < 0 {
			p = i
		}
	}
	if p >= 0 {
		w.WriteString(rev(s[p:len(s)]))
	}
	return w.String()
}

func rev(s string) string {
	w := new(bytes.Buffer)
	r := []rune(s)
	for i := len(r) - 1; i >= 0; i-- {
		w.WriteRune(r[i])
	}
	return w.String()
}
