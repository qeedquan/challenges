/*

back·ro·nym
An acronym deliberately formed from a phrase whose initial letters spell out a particular word or words, either to create a memorable name or as a fanciful explanation of a word's origin.

"Biodiversity Serving Our Nation", or BISON

(from https://en.oxforddictionaries.com/definition/backronym)

Complete the function to create backronyms. Transform the given string (without spaces) to a backronym, using the preloaded dictionary and return a string of words, separated with a single space (but no trailing spaces).

The keys of the preloaded dictionary are uppercase letters A-Z and the values are predetermined words, for example:

dict["P"] == "perfect"

Examples
"dgm" ==> "disturbing gregarious mustache"

"lkj" ==> "literal klingon joke"

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	dict := map[rune]string{
		'd': "disturbing",
		'g': "gregarious",
		'm': "mustache",
		'l': "literal",
		'k': "klingon",
		'j': "joke",
		'P': "perfect",
	}
	fmt.Println(backronym("dgm", dict))
	fmt.Println(backronym("lkj", dict))
}

func backronym(s string, d map[rune]string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		fmt.Fprintf(w, "%s ", d[r])
	}

	t := w.String()
	if t != "" {
		t = t[:len(t)-1]
	}

	return t
}
