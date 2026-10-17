/*

Write the shortest function to generate the American Soundex code for a surname only containing the uppercase letters A-Z. Your function must produce output consistent with all the linked page's examples (given below), although it need not and should not remove prefixes. Hyphens in the output are optional. Have fun!

Note: You may not use the soundex() function included in PHP or equivalents in other programming languages.

The examples:

WASHINGTON W-252
LEE L-000
GUTIERREZ G-362
PFISTER P-236
JACKSON J-250
TYMCZAK T-522
VANDEUSEN V-532
ASHCRAFT A-261

*/

package main

import (
	"fmt"
	"unicode"
)

func main() {
	assert(soundex("WASHINGTON") == "W-252")
	assert(soundex("LEE") == "L-000")
	assert(soundex("GUTIERREZ") == "G-362")
	assert(soundex("PFISTER") == "P-236")
	assert(soundex("JACKSON") == "J-250")
	assert(soundex("TYMCZAK") == "T-522")
	assert(soundex("VANDEUSEN") == "V-532")
	assert(soundex("ASHCRAFT") == "A-261")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://www.archives.gov/research/census/soundex
func soundex(s string) string {
	m := map[rune]rune{
		'C': '2',
		'G': '2',
		'J': '2',
		'K': '2',
		'Q': '2',
		'S': '2',
		'X': '2',
		'Z': '2',
		'D': '3',
		'T': '3',
		'L': '4',
		'M': '5',
		'N': '5',
		'R': '6',
		'B': '1',
		'F': '1',
		'P': '1',
		'V': '1',
	}

	p := []rune{}
	l := rune(-1)
	r0 := rune(0)
	for i, r := range s {
		r = unicode.ToUpper(r)
		if i == 0 {
			r0 = r
		}
		if r == 'H' || r == 'W' {
			continue
		}
		r = m[r]

		if l != r && r != 0 {
			p = append(p, r)
		}
		l = r
	}

	t := string(p) + "000"
	i := 0
	if m[r0] != 0 {
		i = 1
	}
	return fmt.Sprintf("%c-%s", r0, t[i:i+3])
}
