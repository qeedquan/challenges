/*

Everybody knows a little german, right? But remembering the correct articles is a tough job. Write yourself a little helper, that returns the noun with the matching article:

each noun containing less than 2 vowels has the article "das"
each noun containing 2/3 vowels has the article "die"
each noun containing more than 3 vowels has the article "der"

Caution: Vowels are "a,e,i,o,u". Umlaute (ä ö ü) are also being counted!

(This Kata is a joke, there is no such grammar rule!)

*/

package main

import (
	"unicode"
)

func main() {
	assert(derdiedas("OOOpa") == "der OOOpa")
	assert(derdiedas("Suppenhuhn") == "die Suppenhuhn")
	assert(derdiedas("Geheimdienst") == "der Geheimdienst")
	assert(derdiedas("Ofenkartoffel") == "der Ofenkartoffel")
	assert(derdiedas("Fisch") == "das Fisch")
	assert(derdiedas("Knödel") == "die Knödel")
	assert(derdiedas("Leberkaassemmi") == "der Leberkaassemmi")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func derdiedas(input string) string {
	count := 0
	for _, symbol := range input {
		switch unicode.ToLower(symbol) {
		case 'a', 'e', 'i', 'o', 'u', 'ä', 'ö', 'ü':
			count += 1
		}
	}

	switch {
	case count < 2:
		return "das " + input
	case count > 3:
		return "der " + input
	}
	return "die " + input
}
