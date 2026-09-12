/*

Given a text, for example:

const inputText = "Michael, how are you? - Cool, how is John Williamns and Michael Jordan? I don't know but Michael Johnson is fine. Michael do you still score points with LeBron James, Michael Green AKA Star and Michael Wood?";

get an array of last names of people named Michael. The result should be:
["Jordan", "Johnson", "Green", "Wood"]

Notes:

First name will always be Michael with upper case 'M'.
There will always be a space character between 'Michael' and last name.
Last name will always be one word, starting with an upper-case letter and continuing with lower-case letters.
There will always be at least one 'Micheal' with a valid last name in the input text.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
	"unicode"
)

func main() {
	fmt.Println(extract("Michael, how are you? - Cool, how is John Williamns and Michael Jordan? I don't know but Michael Johnson is fine. Michael do you still score points with LeBron James, Michael Green AKA Star and Michael Wood?"))
}

func extract(sentence string) []string {
	result := []string{}
	words := strings.Split(sentence, " ")
	for index := 0; index < len(words)-1; index++ {
		switch {
		case words[index] != "Michael":
			continue
		case len(words[index+1]) == 0:
			continue
		case !unicode.IsUpper(rune(words[index+1][0])):
			continue
		default:
			result = append(result, filter(words[index+1]))
			index += 1
		}
	}
	return result
}

func filter(word string) string {
	output := new(bytes.Buffer)
	for _, symbol := range word {
		if unicode.IsLetter(symbol) {
			output.WriteRune(symbol)
		}
	}
	return output.String()
}
