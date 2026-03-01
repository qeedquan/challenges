/*

Given a word (or any sequence of letters) as input, you must interpolate between each letter such that each adjacent pair of letters in the result is also adjacent on a QWERTY keyboard, as if you typed the input by walking on a giant keyboard.
For example, 'yes' might become 'ytres', 'cat' might become 'cxzawert'.

Rules:
This is the keyboard format you should use:

qwertyuiop
 asdfghjkl
  zxcvbnm

Any pair of keys which is touching in this layout is considered adjacent. For instance, 's' and 'e' are ajacent, but 's' and 'r' are not.

The input "word" will consist of any sequence of letters. It will have only letters, so you don't have do deal with special characters.
The input can be in any convenient form: stdin, a string, a list, etc. Letter case does not matter; you can take whatever is more convenient.
The output can be in any convenient form: stdout, a string, a list, etc. Letter case does not matter, and it does not need to be consistent.
Any path across the keyboard is valid, except that you cannot cross the previous letter again before getting to the next letter. For example, 'hi' could become 'hji' or 'hjnbgyui', but not 'hbhui'.
A letter is not ajacent with itself, so 'poll' cannot become 'poll'. Instead it would need to become something like 'polkl'.
No output letters are allowed before or after the word. For example, 'was' cannot become 'trewas' or 'wasdfg'.
This is code golf, the shortest answer in bytes wins.

*/

package main

import (
	"bytes"
	"fmt"
	"regexp"
	"strings"
)

func main() {
	test("puzzles")
	test("programming")
	test("code")
	test("golf")
	test("yes")
	test("hi")
	test("poll")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string) {
	p := kbw(s)
	fmt.Printf("%s -> %s\n", s, p)
	assert(sweep(p, s))
}

func sweep(s, t string) bool {
	for i, j := 0, 0; j < len(t); i++ {
		if i >= len(s) {
			return false
		}
		if s[i] == t[j] {
			j++
		}
	}
	return true
}

func kbw(s string) string {
	const keymap = "qwertyuioplkmnjhbvgfcxdsza"
	re := regexp.MustCompile(strjoin(s, ".*?"))
	return re.FindString(strings.Repeat(keymap, len(s)))
}

func strjoin(s, sep string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		w.WriteRune(r)
		w.WriteString(sep)
	}
	return w.String()
}
