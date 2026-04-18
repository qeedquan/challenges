/*

Braille Patterns in Unicode contains 8 dots(⣿) and occupy area U+2800-U+28FF. Given a Braille Pattern character, where the bottom two dots are not used(aka. U+2800-U+283F), shift it down by one dot.

Test cases:

⠀ => ⠀ (U+2800 -> U+2800)
⠅ => ⡂
⠕ => ⡢
⠿ => ⣶
Shortest code wins.

*/

package main

func main() {
	assert(shift('⠀') == '⠀')
	assert(shift('⠅') == '⡂')
	assert(shift('⠕') == '⡢')
	assert(shift('⠿') == '⣶')
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func shift(r rune) rune {
	return r + r&63 + 14*(r&36)%192
}
