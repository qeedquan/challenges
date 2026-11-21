/*

Objective
Given a string consisting of printable ASCII characters (!0x21 ― ~0x7E), treat it as an element in the free idempotent monoid (as defined below) over the printable ASCII characters, and output the same element represented in the fewest characters as possible.

Free idempotent monoid
Recall that the free monoid over a set is essentially the collection of lists over the set, endowed with concatenation.

The free idempotent monoid is the quotient object of the free monoid that identifies the lists up to idempotency.
In lay terms, if the list has two or more contiguous sub-lists that compare equal, the sub-lists can be replaced by one sub-list, while retaining overall equivalence of the list.

Proof of uniqueness
We want to show that, for two strings x and y that belong to the same equivalence class, if x and y both have the fewest characters in the class, x and y actually are the same string.

It's obvious that x and y consist of the same set of characters. If x and y both have length zero, we are done. Otherwise, let α be the first character in x, and let β be the first character in y.
Since every member of the class x belongs has α as the first character, and likewise for y and β, it follows that α=β.

If x and y both have length one, we are done. Otherwise, let α′ be the second character in x, and let β′ be the second character in y. It's obvious that α′≠α and β′≠β.
Now, every member of the the class x belongs has α′ as the first character when the longest prefix consisting of α is stripped off, and likewise for y and β′, it follows that α′=β′.

If x and y both have length two, we are done.
Otherwise, let α′′ be the third character in x, and let β′′ be the third character in y.
It's obvious that the strings αα′α′′ and ββ′β′′ are irreducible.
Now, every member of the the class x belongs has α′′ as the first character when the longest prefix being equivalent to the string αα′ is stripped off, and likewise for y and β′′, it follows that α′′=β′′.

The proof is recursive until exhausting all characters in x and y.

Examples
Here, the strings are double-quoted.

Input -> Output

"" -> ""
"x" -> "x"
"xx" -> "x"
"xy" -> "xy"
"!!?" -> "!?"
"+/+/" -> "+/"
"1+1+1" -> "1+1"
"1+2+1" -> "1+2+1"
"~~~" -> "~"
"TheThem" -> "Them"
"thethem" -> "them"
"cOUgh" -> "cOUgh"
"XIXAXA" -> "XIXA"
"IXIXAXA" -> "IXA"
"Xx" -> "Xx"
"198034034" -> "198034"
"...!...!" -> ".!"
"...!...?" -> ".!.?"
"Ook!Ook?" -> "Ook!Ook?"
"<o><oo>" -> "<o>"

Worked example
For suppose the inputted string is QUAQUAUAL. The substring QUA contiguously appears twice, enabling the input to be reduced to QUAUAL. Then again, it has the substring UA contiguously appearing twice, enabling the input to be reduced to QUAL. Then, we identify there is no substring contiguously appearing multiple times, resulting in outputting QUAL.

*/

package main

import (
	"strings"
)

func main() {
	assert(reduce("") == "")
	assert(reduce("x") == "x")
	assert(reduce("xx") == "x")
	assert(reduce("xy") == "xy")
	assert(reduce("!!?") == "!?")
	assert(reduce("+/+/") == "+/")
	assert(reduce("1+1+1") == "1+1")
	assert(reduce("1+2+1") == "1+2+1")
	assert(reduce("~~~") == "~")
	assert(reduce("TheThem") == "Them")
	assert(reduce("thethem") == "them")
	assert(reduce("cOUgh") == "cOUgh")
	assert(reduce("XIXAXA") == "XIXA")
	assert(reduce("IXIXAXA") == "IXA")
	assert(reduce("Xx") == "Xx")
	assert(reduce("198034034") == "198034")
	assert(reduce("...!...!") == ".!")
	assert(reduce("...!...?") == ".!.?")
	assert(reduce("Ook!Ook?") == "Ook!Ook?")
	assert(reduce("<o><oo>") == "<o>")
	assert(reduce("QUAQUAUAL") == "QUAL")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @xnor solution
func reduce(s string) string {
	n := len(s)
	for i := range n * n * n {
		i0 := min((i/n)%n, len(s))
		i1 := min(i%n, len(s))
		i1 = max(i1, i0)

		t := s[i0:i1]
		s = strings.Replace(s, t+t, t, -1)
	}
	return s
}
