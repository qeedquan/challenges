/*

Cyrillic letters, used in languages like Russian and Ukrainian, have different unicode values than Latin letters. 2 of those cyrillic letters include а and у which, if you copy these 2, are not the same as the latin a and y

Don't believe me?

Latin a:
https://imgur.com/5OK3gh2
https://imgur.com/V5g0JoL

Cyrillic а:
https://imgur.com/xtbNwWV
https://imgur.com/ZiGP37s

Task
Your task is to write a function that returns whether a given string is a Cyrillic letter in the Cyrillic Unicode Block.

The string will always be a single letter.

Hint
Here is a link to Wikipidia's list of the Cyrillic Unicode block for reference

Wayback Machine archive

Examples
Input: "D"
Output: false (or False in Python or your language's equivalent)
Input: "Я"
Output: true (or True in Python or your language's equivalent)

*/

package main

import "unicode"

func main() {
	assert(cyrillic('Д') == true)
	assert(cyrillic('D') == false)
	assert(cyrillic('а') == true)
	assert(cyrillic('a') == false)
	assert(cyrillic('Я') == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cyrillic(r rune) bool {
	return unicode.Is(unicode.Cyrillic, r)
}
