/*

How sexy is your name? Write a program that calculates how sexy one's name is according to the criteria below.

There is a preloaded dictionary of letter scores called SCORES(Python & JavaScript) / $SCORES (Ruby). Add up the letters (case-insensitive) in your name to get your sexy score. Ignore other characters.

    SCORES = {'A': 100, 'B': 14, 'C': 9, 'D': 28, 'E': 145, 'F': 12, 'G': 3,
              'H': 10, 'I': 200, 'J': 100, 'K': 114, 'L': 100, 'M': 25,
              'N': 450, 'O': 80, 'P': 2, 'Q': 12, 'R': 400, 'S': 113, 'T': 405,
              'U': 11, 'V': 10, 'W': 10, 'X': 3, 'Y': 210, 'Z': 23}
The program must return how sexy one's name is according to the "Sexy score ranking" chart.

       score <= 60:   'NOT TOO SEXY'
 61 <= score <= 300:  'PRETTY SEXY'
301 <= score <= 599:  'VERY SEXY'
       score >= 600:  'THE ULTIMATE SEXIEST'

*/

package main

import "unicode"

func main() {
	assert(sexiness("GUV") == "NOT TOO SEXY")
	assert(sexiness("PHUG") == "NOT TOO SEXY")
	assert(sexiness("FFFFF") == "NOT TOO SEXY")
	assert(sexiness("") == "NOT TOO SEXY")
	assert(sexiness("PHUG") == "NOT TOO SEXY")

	assert(sexiness("BOB") == "PRETTY SEXY")
	assert(sexiness("JLJ") == "PRETTY SEXY")
	assert(sexiness("HHHHHU") == "PRETTY SEXY")
	assert(sexiness("BOB") == "PRETTY SEXY")
	assert(sexiness("WWWWWU") == "PRETTY SEXY")

	assert(sexiness("YOU") == "VERY SEXY")
	assert(sexiness("FABIO") == "VERY SEXY")
	assert(sexiness("ARUUUUUUUUU") == "VERY SEXY")

	assert(sexiness("ROBBY") == "THE ULTIMATE SEXIEST")
	assert(sexiness("SAMANTHA") == "THE ULTIMATE SEXIEST")
	assert(sexiness("DONALD TRUMP") == "THE ULTIMATE SEXIEST")
	assert(sexiness("BILL GATES") == "THE ULTIMATE SEXIEST")
	assert(sexiness("SCARLETT JOHANSSON") == "THE ULTIMATE SEXIEST")
	assert(sexiness("CODEWARS") == "THE ULTIMATE SEXIEST")
	assert(sexiness("PAMELA ANDERSON") == "THE ULTIMATE SEXIEST")

	assert(sexiness("you") == "VERY SEXY")
	assert(sexiness("Codewars") == "THE ULTIMATE SEXIEST")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sexiness(name string) string {
	scores := map[rune]int{
		'A': 100, 'B': 14, 'C': 9, 'D': 28, 'E': 145, 'F': 12, 'G': 3,
		'H': 10, 'I': 200, 'J': 100, 'K': 114, 'L': 100, 'M': 25,
		'N': 450, 'O': 80, 'P': 2, 'Q': 12, 'R': 400, 'S': 113, 'T': 405,
		'U': 11, 'V': 10, 'W': 10, 'X': 3, 'Y': 210, 'Z': 23,
	}

	value := 0
	for _, char := range name {
		char = unicode.ToUpper(char)
		value += scores[char]
	}

	switch {
	case value <= 60:
		return "NOT TOO SEXY"
	case value <= 300:
		return "PRETTY SEXY"
	case value <= 599:
		return "VERY SEXY"
	}
	return "THE ULTIMATE SEXIEST"
}
