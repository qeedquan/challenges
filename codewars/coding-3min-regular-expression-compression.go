/*

This is the simple version of Shortest Code series. If you need some challenges, please try the challenge version

Task:
Some people write the regular expression too long, let us compress it.

Input: regex, a regular expression string

Output: a compressed regular expression string. Note, if the string can not be compressed to a shorter string, returns the the original string.

Example:
"/aaaaaaaaaa/" should compress to "/a{10}/"

"/ababababab/" should compress to "/(ab){5}/"

"/abcdabcdabcdabcd/" should compress to "/(abcd){4}/"

"/aa/" should NOT compress to "/a{2}/"

It should return the original string, because The original string is shorter, it cannot be compressed.

"/abab/", "/abcdabcd/"should return the original string too

we love the shortest code ;-)

For the sake of simplicity, we only test a single repeat.

/aaaaabbbbb/ can compress to "/a{5}b{5}/"

but this kind of situation will not appear in the test.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(compress("/aaaaaaaaaa/") == "/a{10}/")
	assert(compress("/ababababab/") == "/(ab){5}/")
	assert(compress("/abcdabcdabcdabcd/") == "/(abcd){4}/")
	assert(compress("/aa/") == "/aa/")
	assert(compress("/abab/") == "/abab/")
	assert(compress("/abcdabcd/") == "/abcdabcd/")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func compress(r string) string {
	n := len(r)
	if n < 2 {
		return r
	}

	s := r[1 : n-1]
	m := len(s)
	for i := 1; i < m; i++ {
		t := strings.Repeat(s[:i], m/i)
		if s == t {
			s = s[:i]
			m = len(s)
			break
		}
	}

	var p string
	if m == 1 {
		p = fmt.Sprintf("%s{%d}", s, n-2)
	} else {
		p = fmt.Sprintf("(%s){%d}", s, (n-2)/m)
	}

	if len(p) < n-2 {
		p = fmt.Sprintf("/%s/", p)
	} else {
		p = r
	}
	return p
}
