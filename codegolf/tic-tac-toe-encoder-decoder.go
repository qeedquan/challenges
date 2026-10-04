/*

James Bond is about to start a new mission and you are his computer scientist friend. As Tic Tac Toe is becoming more and more popular you decide that nothing would be more underhanded than a Tic Tac Toe encoder/decoder™.

For each line the decoder will follow the following steps:

Convert from 'O','X' and ' ' [space] to trinary

' ' -> 0

'O' -> 1

'X' -> 2

Convert from trinary to decimal

Convert from decimal to letter

Example: "XO "

210

21

v

The encoder will do the reverse.

As code is much more precise than words, see the reference answer below in which I give an example (very long) implementation of the problem in Python:

Your decoder should be able to decode all the messages encoded with my encoder correctly and my decoder should be able to decode all the messages encoded with your encoder.

This is code-golf, the shortest wins.

Additional informations
0 must be converted to a, the alphabet ends with a whitespace, so 26-> ' ' [whitespace]

"XXX" is the max, it translates to "222" that translates to 26.

As in Tic Tac Toe the max line length is 3.

X -> 2 means X should be replaced by 2

Encoder/Decoder

The encoder goes from plaintext to code.
The decoder goes from code to plaintext.

*/

package main

import (
	"bytes"
	"fmt"
	"strconv"
	"strings"
)

func main() {
	syms := []rune{' ', 'O', 'X'}
	for _, a := range syms {
		for _, b := range syms {
			for _, c := range syms {
				s := fmt.Sprintf("%c%c%c", a, b, c)
				assert(s == decode(encode(s)))
			}
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func encode(s string) rune {
	w := new(bytes.Buffer)
	for _, r := range s {
		switch r {
		case ' ':
			w.WriteByte('0')
		case 'O':
			w.WriteByte('1')
		case 'X':
			w.WriteByte('2')
		}
	}

	v, err := strconv.ParseInt(w.String(), 3, 64)
	if err != nil {
		return -1
	}

	if v == 0 {
		return ' '
	}

	return 'a' + rune(v) - 1
}

func decode(c rune) string {
	if c == ' ' {
		return "   "
	}

	if !('a' <= c && c <= 'z') {
		return ""
	}

	s := strconv.FormatInt(int64(c-'a'+1), 3)
	s = strings.Replace(s, "0", " ", -1)
	s = strings.Replace(s, "1", "O", -1)
	s = strings.Replace(s, "2", "X", -1)
	if n := len(s); n < 3 {
		s = strings.Repeat(" ", 3-n) + s
	}
	return s
}
