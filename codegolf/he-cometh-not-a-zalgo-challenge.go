/*

Write a program or function that, given a string, will strip it of zalgo, if any exists.

Zalgo
For this post, zalgo is defined as any character from the following Unicode ranges:

Combining Diacritical Marks (0300–036F)
Combining Diacritical Marks Extended (1AB0–1AFF)
Combining Diacritical Marks Supplement (1DC0–1DFF)
Combining Diacritical Marks for Symbols (20D0–20FF)
Combining Half Marks (FE20–FE2F)
https://en.wikipedia.org/wiki/Combining_character#Unicode_ranges

Input
May be passed via command line arguments, STDIN, or any other standard method of input supported by your language
Will be a string that may or may not contain zalgo or other non-ASCII characters
Output
Output should be a string that does not contain any zalgo.

Test Cases
Input -> Output

HE̸͚ͦ ̓C͉Õ̗͕M͙͌͆E̋̃ͥT̠͕͌H̤̯͛ -> HE COMETH
C͉̊od̓e͔͝ ̆G̀̑ͧo͜l͔̯͊f͉͍ -> Code Golf
aaaͧͩa͕̰ȃ̘͕aa̚͢͝aa͗̿͢ -> aaaaaaaaa
ññ        -> ñn
⚡⃤       -> ⚡

Scoring
As this is code-golf, shortest answer in bytes wins.

*/

package main

import (
	"bytes"
)

func main() {
	assert(unzalgo("HE̸͚ͦ ̓C͉Õ̗͕M͙͌͆E̋̃ͥT̠͕͌H̤̯͛") == "HE COMETH")
	assert(unzalgo("C͉̊od̓e͔͝ ̆G̀̑ͧo͜l͔̯͊f͉͍") == "Code Golf")
	assert(unzalgo("aaaͧͩa͕̰ȃ̘͕aa̚͢͝aa͗̿͢") == "aaaaaaaaa")
	assert(unzalgo("ññ") == "ñn")
	assert(unzalgo("⚡⃤") == "⚡")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func unzalgo(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		switch {
		case 0x300 <= r && r <= 0x36f,
			0x1ab0 <= r && r <= 0x1aff,
			0x1dc0 <= r && r <= 0x1dff,
			0x20d0 <= r && r <= 0x20ff,
			0xfe20 <= r && r <= 0xfe2f:
			continue
		}
		w.WriteRune(r)
	}
	return w.String()
}
