/*

Your mission is to write the shortest valid regular expression that no string can match, empty string included.

Submissions must have this form ("literal notation"):

/pattern/optional-flags
Shortest regexp wins. The regexp size is counted in characters. (including slashes and flags)

Please explain how your regexp works (if it's not trivial)

Thanks, and have fun!

*/

package main

import (
	"regexp"
)

func main() {
	for i := 0; i <= 4; i++ {
		search(i, "")
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func search(n int, s string) {
	if n <= 0 {
		assert(match(s) == false)
		return
	}

	for c := 32; c < 127; c++ {
		search(n-1, s+string(c))
	}
}

/*

@Sven Hohenstein

A word boundary (\b) surrounded by 'word' characters (\w - one of [_a-zA-Z0-9]). It is unmatchable since one of the characters preceding or following a word boundary must be a non-'word' character.

By the way: this is similar to the unmatchable expression

/\W\b\W/
where \W means non-'word' character.

*/

func match(s string) bool {
	return re.MatchString(s)
}

var re = regexp.MustCompile(`\w\b\w`)
