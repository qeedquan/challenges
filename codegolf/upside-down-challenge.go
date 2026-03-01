/*

Turn the characters abcdefghijklmnopqrstuvwxyz!?., upside down and don't modify the other characters. Then, reverse the text to achieve the upside down affect. If text is already upside down, turn it right side up. Don't modify capitals.

Use this as a reference:

abcdefghijklmnopqrstuvwxyz!?.,
ɐqɔpǝɟƃɥıɾʞןɯuodbɹsʇnʌʍxʎz¡¿˙'
Rules
Newlines must be supported
You only have to convert the above character set.
Don't forget you need to reverse the characters.
This question is symmetrical unlike Small Caps Converter.
Test cases
42 is the meaning of life -> ǝɟıן ɟo ƃuıuɐǝɯ ǝɥʇ sı 24
halp why is my keyboard typing upside down??? :( -> (: ¿¿¿uʍop ǝpısdn ƃuıdʎʇ pɹɐoqʎǝʞ ʎɯ sı ʎɥʍ dןɐɥ
lol -> ןoן
uoɥʇʎpʎzɐɹc -> ɔrazydython

Look at my username!

*/

package main

import (
	"slices"
)

func main() {
	assert(flip("42 is the meaning of life") == "ǝɟıן ɟo ƃuıuɐǝɯ ǝɥʇ sı 24")
	assert(flip("halp why is my keyboard typing upside down??? :(") == "(: ¿¿¿uʍop ǝpısdn ƃuıdʎʇ pɹɐoqʎǝʞ ʎɯ sı ʎɥʍ dןɐɥ")
	assert(flip("lol") == "ןoן")
	assert(flip("uoɥʇʎpʎzɐɹc") == "ɔrazydython")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func flip(s string) string {
	sym0 := []rune("abcdefghijklmnopqrstuvwxyz!?.,")
	sym1 := []rune("ɐqɔpǝɟƃɥıɾʞןɯuodbɹsʇnʌʍxʎz¡¿˙'")

	t := []rune{}
	for _, r := range s {
		i := slices.Index(sym0, r)
		j := slices.Index(sym1, r)
		switch {
		case i >= 0:
			t = append(t, sym1[i])
		case j >= 0:
			t = append(t, sym0[j])
		default:
			t = append(t, r)
		}
	}
	slices.Reverse(t)
	return string(t)
}
