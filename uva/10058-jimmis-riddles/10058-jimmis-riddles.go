package main

import (
	"regexp"
)

func main() {
	assert(match("the dog and a cat know goofy") == "YES I WILL")
	assert(match("jimmy kills tom") == "NO I WON'T")
	assert(match("goofy hate mouse jerry") == "NO I WON'T")
	assert(match("tom hates jerry , jimmy hates tom") == "YES I WILL")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func match(input string) string {
	regex := generate()
	if regex.MatchString(input) {
		return "YES I WILL"
	}
	return "NO I WON'T"
}

func generate() *regexp.Regexp {
	const (
		VERB        = "(hate|love|know|like)s*"
		NOUN        = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)"
		ARTICLE     = "(a|the)"
		ACTOR       = "(" + NOUN + "|" + ARTICLE + " " + NOUN + ")"
		ACTIVE_LIST = "(" + ACTOR + " and )*" + ACTOR
		ACTION      = ACTIVE_LIST + " " + VERB + " " + ACTIVE_LIST
		STATEMENT   = ACTION + "( , " + ACTION + ")*"
	)
	return regexp.MustCompile("^" + STATEMENT + "$")
}
