/*

I give you this: ['This', 'Is', 'a' 'Example');

You give me back this: 'examplE a iS thiS'

So. I want what I give you back in reverse order, with only the last letter of each item capitalized. If the item is a single letter word and not capitilized when I give it to you, do not capitalize it.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
	"unicode"
	"unicode/utf8"
)

func main() {
	assert(flipper([]string{"This", "Is", "a", "Example"}) == "examplE a iS thiS")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func flipper(s []string) string {
	w := new(bytes.Buffer)
	for i := len(s) - 1; i >= 0; i-- {
		t := strings.ToLower(s[i])
		r, n := utf8.DecodeLastRuneInString(t)

		t = t[:len(t)-n]
		if t == "" {
			r = unicode.ToLower(r)
		} else {
			r = unicode.ToUpper(r)
		}

		fmt.Fprintf(w, "%s%c", t, r)
		if i > 0 {
			fmt.Fprintf(w, " ")
		}
	}
	return w.String()
}
