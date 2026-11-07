/*

Write a function that takes an arbitrary number of strings and interlaces them (combines them by alternating characters from each string).

For example combineStrings('abc', '123') should return 'a1b2c3'.

If the strings are different lengths the function should interlace them until each string runs out, continuing to add characters from the remaining strings.

For example combineStrings('abcd', '123') should return 'a1b2c3d'.

The function should take any number of arguments and combine them.

For example combineStrings('abc', '123', '£$%') should return 'a1£b2$c3%'.

Note: if only one argument is passed return only that string. If no arguments are passed return an empty string.

*/

package main

import (
	"bytes"
	"unicode/utf8"
)

func main() {
	assert(combine("abc", "123") == "a1b2c3")
	assert(combine("abcd", "123") == "a1b2c3d")
	assert(combine("abc", "123", "£$%") == "a1£b2$c3%")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func combine(strings ...string) string {
	output := new(bytes.Buffer)
	for {
		done := true
		for index := range strings {
			if len(strings[index]) == 0 {
				continue
			}

			symbol, width := utf8.DecodeRuneInString(strings[index][:])
			strings[index] = strings[index][width:]

			output.WriteRune(symbol)
			done = false
		}
		if done {
			break
		}
	}
	return output.String()
}
