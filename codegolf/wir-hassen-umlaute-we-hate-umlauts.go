/*

Introduction
As you all know, German has umlauts. They're these things: ¨

However, most keyboards don't have an umlaut key. That's fine, though, because you can write ö, ä, and ü as oe, ae, and ue.

Challenge
Your job is to to replace ö, ä, and ü with oe, ae, and ue (and likewise for their capital versions).
You have to deal with both the combining diacritical mark and single characters. (Thank you @ETHProductions for pointing this out.)
Capitalization of the base letter stays intact.
Capitalization of the e depends on the capitalization of the surrounding letters after replacement. You should write it as e unless it's adjacent to a capital letter on both sides, in which case write it as E. (End of line and space are not capital letters.)
Standard loopholes and I/O rules apply.
This is code-golf, so shortest code in UTF-8 bytes wins!
Example Input and Output
Test cases using precomposed characters

ü = ue
üb = ueb
üB = ueB
Ü = Ue
Üb = Ueb
ÜB = UEB
Test cases using combining diacritics

ö = oe
öb = oeb
öB = oeB
Ö = Oe
Öb = Oeb
ÖB = OEB

*/

package main

import (
	"strings"
	"unicode"
)

func main() {
	assert(combine("ü") == "ue")
	assert(combine("üb") == "ueb")
	assert(combine("üB") == "ueB")
	assert(combine("Ü") == "Ue")
	assert(combine("Üb") == "Ueb")
	assert(combine("ÜB") == "UEB")

	assert(combine("ö") == "oe")
	assert(combine("öb") == "oeb")
	assert(combine("öB") == "oeB")
	assert(combine("Ö") == "Oe")
	assert(combine("Öb") == "Oeb")
	assert(combine("ÖB") == "OEB")

	assert(combine("ä") == "ae")
	assert(combine("Ä") == "Ae")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func combine(s string) string {
	r := strings.NewReplacer(
		"ü", "ue",
		"Ü", "Ue",
		"ö", "oe",
		"Ö", "Oe",
		"ä", "ae",
		"Ä", "Ae",
	)
	s = r.Replace(s)
	p := []rune(s)
	for i := 1; i < len(p)-1; i++ {
		if p[i] == 'e' && unicode.IsUpper(p[i-1]) && unicode.IsUpper(p[i+1]) {
			p[i] = 'E'
		}
	}
	return string(p)
}
