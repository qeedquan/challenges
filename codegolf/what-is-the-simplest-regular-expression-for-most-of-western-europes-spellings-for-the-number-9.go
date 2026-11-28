/*

Regex Golf
The following is a list of regular expressions for almost all of the ways to spell the number 9 in the languages of Western Europe coupled with a few misspellings thereof.

If we or union all of the regular expression together with the | operator, the regex is 528 bytes when encoded using ASCII.

[DZ]+[AEIOUY]*[AEIOUY]*V[AEIOUY]*
[DZ]+[AEIOUY]*[AEIOUY]*V[AEIOUY]*[AEIOUY]*
[DZ]+[AEIOUY]*[AEIOUY]*W
[DZ]+[AEIOUY]*[AEIOUY]*W[AEIOUY]*
D[AEIOUY]*[SG]+
D[AEIOUY]*[SG]+[AEIOUY]*
D[AEIOUY]*[VT]+
D[AEIOUY]*[VT]+[AEIOUY]*
D[AEIOUY]*[VT]+[AEIOUY]*N[AEIOUY]*[AEIOUY]*
D[AEIOUY]*[VT]+[AEIOUY]*N[AEIOUY]*[AEIOUY]*S
D[AEIOUY]*[VT]+[AEIOUY]*[AEIOUY]*
D[AEIOUY]*[VT]+[AEIOUY]*[AEIOUY]*T
H[AEIOUY]*[KSX]+
H[AEIOUY]*KS[AEIOUY]*
K[AEIOUY]*L[AEIOUY]*N
K[AEIOUY]*L[AEIOUY]*[NCK]+
N[AEIOUY]*CT
N[AEIOUY]*N
N[AEIOUY]*V
N[AEIOUY]*X
[AEIOUY]*N
[AEIOUY]*N[AEIOUY]*
[AEIOUY]*T

Scoring Function
The regex with the smallest number of | characters wins.

If two regular expressions have the same number of pipes |, then the regular expression stored in the least number of bytes wins.

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	fmt.Println(renine.MatchString("NINE"))
	fmt.Println(renine.MatchString("NEIN"))
	fmt.Println(renine.MatchString("9"))
	fmt.Println(renine.MatchString("NINN"))
	fmt.Println(renine.MatchString("NI"))
}

var (
	renine *regexp.Regexp
)

func init() {
	patterns := []string{
		"[DZ]+[AEIOUY]*[AEIOUY]*V[AEIOUY]*",
		"[DZ]+[AEIOUY]*[AEIOUY]*V[AEIOUY]*[AEIOUY]*",
		"[DZ]+[AEIOUY]*[AEIOUY]*W",
		"[DZ]+[AEIOUY]*[AEIOUY]*W[AEIOUY]*",
		"D[AEIOUY]*[SG]+",
		"D[AEIOUY]*[SG]+[AEIOUY]*",
		"D[AEIOUY]*[VT]+",
		"D[AEIOUY]*[VT]+[AEIOUY]*",
		"D[AEIOUY]*[VT]+[AEIOUY]*N[AEIOUY]*[AEIOUY]*",
		"D[AEIOUY]*[VT]+[AEIOUY]*N[AEIOUY]*[AEIOUY]*S",
		"D[AEIOUY]*[VT]+[AEIOUY]*[AEIOUY]*",
		"D[AEIOUY]*[VT]+[AEIOUY]*[AEIOUY]*T",
		"H[AEIOUY]*[KSX]+",
		"H[AEIOUY]*KS[AEIOUY]*",
		"K[AEIOUY]*L[AEIOUY]*N",
		"K[AEIOUY]*L[AEIOUY]*[NCK]+",
		"N[AEIOUY]*CT",
		"N[AEIOUY]*N",
		"N[AEIOUY]*V",
		"N[AEIOUY]*X",
		"[AEIOUY]*N",
		"[AEIOUY]*N[AEIOUY]*",
		"[AEIOUY]*T",
	}

	regex := ""
	for i, pattern := range patterns {
		regex += pattern
		if i+1 < len(patterns) {
			regex += "|"
		}
	}

	renine = regexp.MustCompile(regex)
}
