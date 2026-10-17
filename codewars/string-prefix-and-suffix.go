/*

In this Kata, you will be given a string and your task will be to return the length of the longest prefix that is also a suffix. A prefix is the start of a string while the suffix is the end of a string. For instance, the prefixes of the string "abcd" are ["a","ab","abc"]. The suffixes are ["bcd", "cd", "d"]. You should not overlap the prefix and suffix.

for example:
solve("abcd") = 0, because no prefix == suffix.
solve("abcda") = 1, because the longest prefix which == suffix is "a".
solve("abcdabc") = 3. Longest prefix which == suffix is "abc".
solve("aaaa") = 2. Longest prefix which == suffix is "aa". You should not overlap the prefix and suffix
solve("aa") = 1. You should not overlap the prefix and suffix.
solve("a") = 0. You should not overlap the prefix and suffix.
All strings will be lowercase and string lengths are 1 <= length <= 500

More examples in test cases. Good luck!

*/

package main

import "strings"

func main() {
	assert(solve("abcd") == 0)
	assert(solve("abcda") == 1)
	assert(solve("abcdabc") == 3)
	assert(solve("aaaa") == 2)
	assert(solve("aa") == 1)
	assert(solve("a") == 0)
	assert(solve("acbacc") == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	for i := len(s) / 2; i > 0; i-- {
		if strings.HasSuffix(s, s[:i]) {
			return i
		}
	}
	return 0
}
