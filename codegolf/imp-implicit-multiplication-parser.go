/*

Jack likes the C programming language, but hates writing expressions like V=a*b\*h; to multiply values.

He would like to just write V=abh; instead; why should the compiler moan about abh being undefined? Since int a, b, h; are defined, can't it just deduce multiplication? Help him implement a parser that deciphers a single multiplication term, provided the set of variables defined in current scope is known.

For simplicity, no numbers will be included (i.e. 2abh), only single-character variables.

The input is a multiplication term T, fulfilling regexp:

[a-zA-Z_][a-zA-Z_0-9]*
and a variable set Z .

A parsing P of the term T over variable set Z is a string fulfilling the following conditions:

P can be turned back into T by removing all * characters
The string either is a variable name from Z or consists of proper variable names from Z split up by single * characters.
The solution should print all possible ways to parse the input.

Examples:

Vars           a, c, ab, bc
Term           abc
Solution       ab*c, a*bc

Vars           ab, bc
Term           abc
Solution       -

Vars           -
Term           xyz
Solution       -

Vars           xyz
Term           xyz
Solution       xyz

Vars           width, height
Term           widthheight
Solution       width*height

Vars           width, height
Term           widthheightdepth
Solution       -

Vars           aaa, a
Term           aaaa
Solution       aaa*a, a*aaa, a*a*a*a

The input (the list of variables and the term) may be supplied in any way suitable for the language.

The output can be in any sensible form (one result per line or a comma-separated list etc.) - but it should be unambiguous and possible to read.

Empty output is acceptable if there is no possible parsing of a term (in the examples I used '-' for clarity).

This is code-golf, so the shortest code wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	imp("abc", []string{"a", "c", "ab", "bc"})
	imp("abc", []string{"ab", "bc"})
	imp("xyz", []string{""})
	imp("xyz", []string{"xyz"})
	imp("widthheight", []string{"width", "height"})
	imp("widthheightdepth", []string{"width", "height"})
	imp("aaaa", []string{"aaa", "a"})
}

func imp(term string, vars []string) {
	fmt.Println(term, vars)
	recurse(term, vars, []string{})
	fmt.Println()
}

func recurse(term string, vars, result []string) {
	if term == "" {
		if len(result) > 0 {
			fmt.Println(strings.Join(result, "*"))
		}
		return
	}

	for _, vari := range vars {
		if vari != "" && strings.HasPrefix(term, vari) {
			recurse(term[len(vari):], vars, append(result, vari))
		}
	}
}
