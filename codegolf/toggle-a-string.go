/*

The challenge involve simply toggling a string within another string.

Explanation
If the toggle string is a substring of the main string, remove all instances of the toggle string from the main string; otherwise, append the toggle string at the end of the main string.

Rules
All string are composed of printable ASCII characters
The function should take two parameters: the main string and the toggle string.
The main string can be empty.
The toggle string cannot be empty.
The result should be a string, which can be empty.
The shortest answer wins.
Examples
function toggle(main_string, toggle_string){ ... }

toggle('this string has 6 words ', 'now')
=> 'this string has 6 words now'

toggle('this string has 5 words now', ' now')
=> 'this string has 5 words'
Tests cases
'','a'          => 'a'
'a','a'         => ''

'b','a'         => 'ba'
'ab','a'        => 'b'

'aba','a'       => 'b'
'ababa', 'aba'  => 'ba'

*/

package main

import (
	"strings"
)

func main() {
	assert(toggle("this string has 6 words ", "now") == "this string has 6 words now")
	assert(toggle("this string has 5 words now", " now") == "this string has 5 words")

	assert(toggle("", "a") == "a")
	assert(toggle("a", "a") == "")

	assert(toggle("b", "a") == "ba")
	assert(toggle("ab", "a") == "b")

	assert(toggle("aba", "a") == "b")
	assert(toggle("ababa", "aba") == "ba")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func toggle(s, t string) string {
	if strings.Index(s, t) >= 0 {
		s = strings.Replace(s, t, "", -1)
	} else {
		s += t
	}
	return s
}
