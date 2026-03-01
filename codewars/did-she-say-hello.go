/*

You received a whatsup message from an unknown number. Could it be from that girl/boy with a foreign accent you met yesterday evening?

Write a simple function to check if the string contains the word hallo in different languages.

These are the languages of the possible people you met the night before:

hello - english
ciao - italian
salut - french
hallo - german
hola - spanish
ahoj - czech republic
czesc - polish

Notes

you can assume the input is a string.
to keep this a beginner exercise you don't need to check if the greeting is a subset of word (Hallowen can pass the test)
function should be case insensitive to pass the tests

*/

package main

import (
	"regexp"
)

func main() {
	assert(match("Hallowen") == true)
	assert(match("Wonder") == false)
	assert(match("NiCiao") == true)
	assert(match("Ahoxxj") == false)
	assert(match("czesc hallo ciao") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func match(s string) bool {
	m, _ := regexp.MatchString(`(?i)(hello|ciao|salut|hallo|hola|ahoj|czesc)`, s)
	return m
}
