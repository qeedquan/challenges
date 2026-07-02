/*

In this exercise, you will have to create a function named tiyFizzBuzz. This function will take on a string parameter and will return that string with some characters replaced, depending on the value:

If a letter is a upper case consonants, replace that character with "Iron".
If a letter is a lower case consonants or a non-alpha character, do nothing to that character
If a letter is a upper case vowel, replace that character with "Iron Yard".
If a letter is a lower case vowel, replace that character with "Yard".
Ready?

*/

package main

import (
	"bytes"
	"strings"
)

func main() {
	assert(tiyfizzbuzz("H") == "Iron")
	assert(tiyfizzbuzz("b") == "b")
	assert(tiyfizzbuzz("a") == "Yard")
	assert(tiyfizzbuzz("Hello WORLD!") == "IronYardllYard IronIron YardIronIronIron!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tiyfizzbuzz(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		switch {
		case strings.IndexRune("QWRTYPSDFGHJKLZXCBNMV", r) >= 0:
			w.WriteString("Iron")
		case strings.IndexRune("AEOUI", r) >= 0:
			w.WriteString("Iron Yard")
		case strings.IndexRune("aeoui", r) >= 0:
			w.WriteString("Yard")
		default:
			w.WriteRune(r)
		}
	}
	return w.String()
}
