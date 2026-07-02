/*

Given a string of numbers, you must perform a method in which you will translate this string into text, based on the below image:

https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/1024px-Telephone-keypad2.svg.png

For example if you get "22" return "b", if you get "222" you will return "c". If you get "2222" return "ca".

Further details:

- 0 is a space in the string.
- 1 is used to separate letters with the same number.
- always transform the number to the letter with the maximum value, as long as it does not have a 1 in the middle.
  So, "777777" -->  "sq" and "7717777" --> "qs".
- you cannot return digits.
- Given an empty string, return empty string.
- Return a lowercase string.

## Examples:

"443355555566604466690277733099966688" -->  "hello how are you"
"55282" -->  "kata"
"22266631339277717777" -->  "codewars"
"66885551555" -->  "null"
"833998" -->  "text"
"000" -->  "   "

*/

package main

import "strings"

func main() {
	assert(phoneword("443355555566604466690277733099966688") == "hello how are you")
	assert(phoneword("55282") == "kata")
	assert(phoneword("44460208337777833777") == "im a tester")
	assert(phoneword("22266631339277717777") == "codewars")
	assert(phoneword("66885551555") == "null")
	assert(phoneword("833998") == "text")
	assert(phoneword("000") == "   ")
	assert(phoneword("528882") == "java")
	assert(phoneword("55886444833") == "kumite")
	assert(phoneword("271755533") == "apple")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func phoneword(s string) string {
	tab := [][2]string{
		{"222", "c"},
		{"22", "b"},
		{"2", "a"},
		{"333", "f"},
		{"33", "e"},
		{"3", "d"},
		{"444", "i"},
		{"44", "h"},
		{"4", "g"},
		{"555", "l"},
		{"55", "k"},
		{"5", "j"},
		{"666", "o"},
		{"66", "n"},
		{"6", "m"},
		{"7777", "s"},
		{"777", "r"},
		{"77", "q"},
		{"7", "p"},
		{"888", "v"},
		{"88", "u"},
		{"8", "t"},
		{"9999", "z"},
		{"999", "y"},
		{"99", "x"},
		{"9", "w"},
		{"1", ""},
		{"0", " "},
	}

	for _, w := range tab {
		s = strings.Replace(s, w[0], w[1], -1)
	}
	return s
}
