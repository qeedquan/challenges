/*

Toki Pona is a constructed language with 137ish words, designed to constrain the speaker to expressing ideas in a simple and straightforward manner, reducing ideas to more essential forms.

Often, people attempt to avoid directly expressing numeric quantities in Toki Pona, opting to express them in more practical terms. if one has a very large amount of money ("mani mute mute"), does it matter if it is $3,532,123 or $3,532,124?

However, Toki Pona does have a basic additive number system, (as well as some others that people have proposed but are not widely used) which is capable of expressing exact quantities.

Toki Pona uses the follow words for numbers:

word	value
ala	0
wan	1
tu	2
luka	5
mute	20
ale	100
The quantity expressed by a series of these words is the sum of all of their values.

A quantity must be expressed in as few words as possible, with the words ordered from greatest value to least. for instance, simply summing the values of the words, 6 could be expressed "tu tu tu", "luka wan", "wan luka", "wan wan wan wan wan wan", or some other variation. however, a valid program will only generate "luka wan" for 6.

Challenge
Write a program which takes as input a non-negative integer and outputs this integer expressed in the Toki Pona number system.

Standard code-golf rules apply. Spaces are required.

Examples
input	output
0	ala
1	wan
2	tu
28	mute luka tu wan
137	ale mute luka luka luka tu
1000	ale ale ale ale ale ale ale ale ale ale

*/

package main

import (
	"strings"
)

func main() {
	assert(tokipona(0) == "ala")
	assert(tokipona(1) == "wan")
	assert(tokipona(2) == "tu")
	assert(tokipona(28) == "mute luka tu wan")
	assert(tokipona(137) == "ale mute luka luka luka tu")
	assert(tokipona(1000) == "ale ale ale ale ale ale ale ale ale ale")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tokipona(n int) string {
	if n < 0 {
		return ""
	}

	if n == 0 {
		return "ala"
	}

	r := rep(n/100, "ale ")
	r += rep(n/20%5, "mute ")
	r += rep(n/5%4, "luka ")
	r += rep(n%5/2, "tu ")
	r += rep(n%5%2, "wan")
	r = strings.TrimSpace(r)
	return r
}

func rep(n int, s string) string {
	return strings.Repeat(s, n)
}
