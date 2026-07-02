/*

While I was traveling in the future, I noticed a funny game among kids circa 2275. When they don't want their great-great-great-great-grand parents to understand what they're saying, they use the BIBABOBU speak. Obviously, I couldn't understand anything either with my pre-cyborg era brain and I felt (or technically: I will feel) really silly. So, I'd need a decoder for my next visit.

BIBABOBU?
While it's been deprecated for a long time, ASCII is still commonly used in the pop culture of 2275 and this language is based upon it.

A string is BIBABOBU-encoded that way:

Convert all characters to their ASCII codes.
Take the 2-digit hexadecimal representation of each code and convert them using the following table:

0: BI  4: BIDI  8: BADI  C: BODI
1: BA  5: BIDA  9: BADA  D: BODA
2: BO  6: BIDO  A: BADO  E: BODO
3: BU  7: BIDU  B: BADU  F: BODU
Example
"Hello!" → 48 65 6C 6C 6F 21 → "BIDIBADI BIDOBIDA BIDOBODI BIDOBODI BIDOBODU BOBA"
However, the corresponding input would be given without any space to mimic the monotonous intonation that kids are using to make this even harder to understand without implants:

"BIDIBADIBIDOBIDABIDOBODIBIDOBODIBIDOBODUBOBA"
Clarifications and rules
Remember that I need a decoder, not an encoder.
Decoded characters are guaranteed to be in the range [ 32...126 ].
The input is guaranteed to contain en even number of BIBABOBU-encoded hexadecimal digits.
You may take input in either full lowercase or full uppercase. Mixed cases are not allowed.
Because bit flips are quite common during a time travel, this is code-golf in order to minimize the risks.
Test cases
NB: Linefeeds are used below for formatting purposes only. You are not supposed to handle them.

Input:
BIDABIDIBIDOBIDABIDUBUBIDUBIDI

Output:
Test

Input:
BIDABIDUBIDOBIDABIDOBODIBIDOBUBIDOBODUBIDOBODABIDOBIDABOBIBIDUBIDIBIDOBODUBOBIBUBOBUBOBUBI
DUBUBIDABOBA

Output:
Welcome to 2275!

Input:
BIDIBADIBIDOBIDABIDOBODIBIDOBODIBIDOBODUBOBODIBOBIBIDABIDIBIDOBADABIDOBODABIDOBIDABOBIBIDA
BIDIBIDUBOBIDOBABIDUBIDOBIDOBIDABIDOBODIBIDOBIDABIDUBOBOBABOBIBIDABADABIDOBODUBIDUBIDABOBI
BIDOBODIBIDOBODUBIDOBODUBIDOBADUBOBIBIDUBUBIDOBODUBOBIBIDOBIDOBIDUBIDABIDOBODOBIDOBODOBIDU
BADABOBA

Output:
Hello, Time Traveler! You look so funny!

Input:
BIDIBABIDOBODOBIDOBIDIBOBIBIDUBADABIDOBODUBIDUBIDABOBIBIDOBIDIBIDOBODUBIDOBODOBOBIDUBIDUBI
DIBOBIBIDUBIDABIDOBODOBIDOBIDIBIDOBIDABIDUBOBIDUBUBIDUBIDIBIDOBABIDOBODOBIDOBIDIBOBIBIDUBI
DUBIDOBADIBIDOBABIDUBIDIBOBIBIDIBADABOBIDUBIDOBODABOBIBIDUBUBIDOBABIDUBADABIDOBADABIDOBODO
BIDOBIDUBOBODIBOBIBIDOBIDIBIDOBODUBOBIBIDUBADABIDOBODUBIDUBIDABUBODUBOBIBIDIBADIBIDOBABOBI
BIDOBADIBIDOBABOBIBIDOBADIBIDOBABOBA

Output:
And you don't understand what I'm saying, do you? Ha ha ha!

*/

package main

import (
	"bytes"
)

func main() {
	assert(decode("BIDIBADIBIDOBIDABIDOBODIBIDOBODIBIDOBODUBOBA") == "Hello!")
	assert(decode("BIDABIDIBIDOBIDABIDUBUBIDUBIDI") == "Test")
	assert(decode("BIDABIDUBIDOBIDABIDOBODIBIDOBUBIDOBODUBIDOBODABIDOBIDABOBIBIDUBIDIBIDOBODUBOBIBUBOBUBOBUBIDUBUBIDABOBA") == "Welcome to 2275!")
	assert(decode("BIDIBADIBIDOBIDABIDOBODIBIDOBODIBIDOBODUBOBODIBOBIBIDABIDIBIDOBADABIDOBODABIDOBIDABOBIBIDABIDIBIDUBOBIDOBABIDUBIDOBIDOBIDABIDOBODIBIDOBIDABIDUBOBOBABOBIBIDABADABIDOBODUBIDUBIDABOBIBIDOBODIBIDOBODUBIDOBODUBIDOBADUBOBIBIDUBUBIDOBODUBOBIBIDOBIDOBIDUBIDABIDOBODOBIDOBODOBIDUBADABOBA") == "Hello, Time Traveler! You look so funny!")
	assert(decode("BIDIBABIDOBODOBIDOBIDIBOBIBIDUBADABIDOBODUBIDUBIDABOBIBIDOBIDIBIDOBODUBIDOBODOBOBIDUBIDUBIDIBOBIBIDUBIDABIDOBODOBIDOBIDIBIDOBIDABIDUBOBIDUBUBIDUBIDIBIDOBABIDOBODOBIDOBIDIBOBIBIDUBIDUBIDOBADIBIDOBABIDUBIDIBOBIBIDIBADABOBIDUBIDOBODABOBIBIDUBUBIDOBABIDUBADABIDOBADABIDOBODOBIDOBIDUBOBODIBOBIBIDOBIDIBIDOBODUBOBIBIDUBADABIDOBODUBIDUBIDABUBODUBOBIBIDIBADIBIDOBABOBIBIDOBADIBIDOBABOBIBIDOBADIBIDOBABOBA") == "And you don't understand what I'm saying, do you? Ha ha ha!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func decode(s string) string {
	m := map[string]int{
		"BI":   0,
		"BA":   1,
		"BO":   2,
		"BU":   3,
		"BIDI": 4,
		"BIDA": 5,
		"BIDO": 6,
		"BIDU": 7,
		"BADI": 8,
		"BADA": 9,
		"BADO": 0xa,
		"BADU": 0xb,
		"BODI": 0xc,
		"BODA": 0xd,
		"BODO": 0xe,
		"BODU": 0xf,
	}

	w := new(bytes.Buffer)
	n := len(s)
	c := 0
	b := 0
	for i := 0; i < n; b ^= 1 {
		k0, k1 := "", ""
		if i+4 <= n {
			k0 = s[i : i+4]
		}
		if i+2 <= n {
			k1 = s[i : i+2]
		}

		v := 0
		if x, ok := m[k0]; ok {
			i, v = i+4, x
		} else if y, ok := m[k1]; ok {
			i, v = i+2, y
		} else {
			return ""
		}

		c = c<<(4*b) | v
		if b == 1 {
			w.WriteByte(byte(c))
			c = 0
		}
	}
	return w.String()
}
