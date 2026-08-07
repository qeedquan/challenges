/*

"One" could be male ("Jeden"), female ("Jedna") or neuter ("Jedno"), which is the case for "beer" (piwo). But all other numbers are invariant, even if ending with "jeden".

Ah, and by the way, if you don't want to drink alcohol (so no beers are ordered), ask for mineral water instead: "Woda mineralna".

Note: if the number of beers is outside your (limited) Polish knowledge (0-99), raise an error!

*/

package main

import (
	"fmt"
	"unicode"
)

func main() {
	assert(order(0) == "Woda mineralna poprosze")
	assert(order(1) == "Jedno piwo poprosze")
	assert(order(2) == "Dwa piwa poprosze")
	assert(order(3) == "Trzy piwa poprosze")
	assert(order(28) == "Dwadziescia osiem piw poprosze")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func order(beers int) string {
	ones := []string{
		"zero", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec",
	}
	teens := []string{
		"dziesiec", "jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie",
	}
	tens := []string{
		"", "dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat",
	}

	if beers < 0 || beers > 99 {
		return "out of range"
	}
	if beers == 0 {
		return "Woda mineralna poprosze"
	}
	if beers == 1 {
		return "Jedno piwo poprosze"
	}

	number := ""
	if beers < 10 {
		number = ones[beers]
	} else if beers < 20 {
		number = teens[beers-10]
	} else {
		number = tens[beers/10]
		if beers%10 != 0 {
			number += " " + ones[beers%10]
		}
	}
	if number != "" {
		number = fmt.Sprintf("%c%s", unicode.ToUpper(rune(number[0])), number[1:])
	}

	form := "piw"
	mod0 := beers % 10
	mod1 := beers % 100
	if 2 <= mod0 && mod0 <= 4 && !(12 <= mod1 && mod1 <= 14) {
		form = "piwa"
	}
	return fmt.Sprintf("%s %s poprosze", number, form)
}
