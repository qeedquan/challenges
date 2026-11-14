/*

Mubashir can talk with monkeys. You can also learn their simple language.

Create a function that takes a string $str and returns the string in monkeys language. You have to figure out their language from test cases.

Examples
monkeyTalk("Mubashir Hassan") ➞ "Ook ook."

monkeyTalk("Hello") ➞ "Ook."

monkeyTalk("Matt") ➞ "Ook."

monkeyTalk("Everyone") ➞ "Eek."

monkeyTalk("Edabit is Amazing") ➞ "Eek eek eek."

Notes
A hint in the comments section.

Hint:
Something to do with vowels.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
	"unicode"
)

func main() {
	assert(monkeytalk("Mubashir Hassan") == "Ook ook.")
	assert(monkeytalk("Edabit is Amazing") == "Eek eek eek.")
	assert(monkeytalk("Matt") == "Ook.")
	assert(monkeytalk("Hello") == "Ook.")
	assert(monkeytalk("you are so beautiful") == "Ook eek ook ook.")
	assert(monkeytalk("Everyone") == "Eek.")
	assert(monkeytalk("Hello Everyone") == "Ook eek.")
	assert(monkeytalk("Everyone Hello") == "Eek ook.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func monkeytalk(s string) string {
	w := new(bytes.Buffer)
	t := strings.Split(s, " ")
	for i, t := range t {
		if len(t) == 0 {
			continue
		}

		c0, c1 := 'O', 'o'
		if isvowel(t[0]) {
			c0, c1 = 'E', 'e'
		}
		if i != 0 {
			c0 = unicode.ToLower(c0)
		}
		fmt.Fprintf(w, "%c%ck ", c0, c1)
	}

	r := w.String()
	if n := len(r); n > 0 {
		r = r[:n-1] + "."
	}
	return r
}

func isvowel(c byte) bool {
	return strings.IndexRune("aieou", unicode.ToLower(rune(c))) >= 0
}
