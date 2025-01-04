/*

Given an input of a program written in oOo CODE, output the BF code that it represents.

Here is a short description of how oOo CODE works:

First, all non-alphabetic characters are removed (everything not in the range A-Za-z).

For example, take the program PROgRam reVERsES giVeN iNPut sEqUENcE (an example given on the esolangs wiki page that does exactly what you'd expect). After this first step, we now have PROgRamreVERsESgiVeNiNPutsEqUENcE.

Next, divide all remaining characters into groups of 3. We now have PRO,gRa,mre,VER,sES,giV,eNi,NPu,tsE,qUE,NcE. If there is a trailing group of 1 or 2 characters, discard it.

Convert each group of 3 letters into a BF command based on the following table:

ooo  >
ooO  <
oOo  [
oOO  ]
Ooo  -
OoO  +
OOo  .
OOO  ,
That is, if the first letter of a group is lowercase, the second is uppercase, and the third is lowercase, it would translate to the command [.

With our example, this finally becomes the BF program ,[>,]<[.<]+, which does indeed reverse its input.

Since this is code-golf, the shortest code in bytes will win.

Test cases:

<empty string> -> <empty string>
A -> <empty string>
Ab -> <empty string>
Abc -> -
AbcD -> -
AbcDe -> -
AbcDef -> --
1A_b%c*D[]e\\\f! -> --
PROgRamreVERsESgiVeNiNPutsEqUENcE -> ,[>,]<[.<]+

*/

package main

import (
	"bytes"
	"unicode"
)

func main() {
	assert(translate("") == "")
	assert(translate("A") == "")
	assert(translate("Ab") == "")
	assert(translate("Abc") == "-")
	assert(translate("AbcD") == "-")
	assert(translate("AbcDef") == "--")
	assert(translate(`1A_b%c*D[]e\\\f!`) == "--")
	assert(translate("PROgRamreVERsESgiVeNiNPutsEqUENcE") == ",[>,]<[.<]+")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func translate(s string) string {
	chars := []rune{'>', '<', '[', ']', '-', '+', '.', ','}

	w := new(bytes.Buffer)
	b, i := 0, 0
	for _, r := range s {
		switch {
		case 'a' <= r && r <= 'z':
			fallthrough
		case 'A' <= r && r <= 'Z':
			if unicode.IsUpper(r) {
				b |= 1 << (2 - i)
			}
			if i++; i == 3 {
				w.WriteRune(chars[b])
				b, i = 0, 0
			}
		}
	}
	return w.String()
}
