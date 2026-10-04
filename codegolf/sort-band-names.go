/*

Challenge description
You have a music library with many tracks recorded by many bands, each of which has a name, like Queen, Aerosmith, Sunny Day Real Estate, The Strokes . When an audio player displays your library alphabetically by band name, it usually skips the The part, as many band names start with The, making it easier to navigate through your media collection. In this challenge, given a list (array) of strings, you need to sort it that way (that is, omitting the The word at the beginning of the name). You can either write a method or a full working program.

Sample inputs / outputs
[Queen, Aerosmith, Sunny Day Real Estate, The Strokes] -> [Aerosmith, Queen, The Strokes, Sunny Day Real Estate]
[The Ramones, The Cure, The Pixies, The Roots, The Animals, Enrique Iglesias] -> [The Animals, The Cure, Enrique Iglesias, The Pixies, The Ramones, The Roots]
[The The, The They, Thermodynamics] -> [The The, Thermodynamics, The They]
Notes / Edge cases
Sorting lexicographically is case insensitive, so The Police, The police and the police are all equivalent,

Your algorithm should only omit the first the word, so bands named The The or The The Band are sorted normally by the second the,

A band named The (a three letter word) is sorted normally (no skipping),

Order of two bands having the same name, one of which starts with the (like The Police and Police) is undefined,

You can assume that if a band's name consists of more than one word, they are separated by a single space character. You don't need to handle leading or trailing whitespaces,

All input strings match [A-Za-z0-9 ]*, that is they will consist only of lower- and uppercase letters of English alphabet, digits and space characters,

Remember that this is a code-golf challenge, so make your code as short as possible!

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
	"strings"
)

func main() {
	test(
		[]string{"Queen", "Aerosmith", "Sunny Day Real Estate", "The Strokes"},
		[]string{"Aerosmith", "Queen", "The Strokes", "Sunny Day Real Estate"},
	)

	test(
		[]string{"The Ramones", "The Cure", "The Pixies", "The Roots", "The Animals", "Enrique Iglesias"},
		[]string{"The Animals", "The Cure", "Enrique Iglesias", "The Pixies", "The Ramones", "The Roots"},
	)

	test(
		[]string{"The The", "The They", "Thermodynamics"},
		[]string{"The The", "Thermodynamics", "The They"},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, r []string) {
	bandsort(s)
	fmt.Println(s)
	assert(reflect.DeepEqual(s, r))
}

func bandsort(s []string) []string {
	sort.Slice(s, func(i, j int) bool {
		a := strings.ToLower(s[i])
		b := strings.ToLower(s[j])

		a = strings.TrimPrefix(a, "the ")
		b = strings.TrimPrefix(b, "the ")

		return a < b
	})
	return s
}
