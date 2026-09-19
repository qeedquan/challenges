/*

Challenge
Code an ASCII cookie of a kind according to the input.

Input
The cookie kind. This is one of the three strings: "Plain", "Chocolate", or "Nuts". May be function arguments, stdin (or closest equivalent), or file arguments.

Output
An ASCII cookie. See below.
Must be

     ___
    /   \
    |   |
    \___/
for Plain input,

     ___
    /. .\
    | . |
    \___/
for Chocolate input, and finally

     ___
    /^  \
    |^ ^|
    \___/
for Nut input.

Other information
This is my first challenge, it's as simple as can be. Constructive feedback is greatly appreciated.
Use any means to do so.
Trailing spaces are fine.
This is a code golf challenge, so shortest entry at the end of 9 days (Wednesday, the 12th of August 2015) wins.
Thank you!
The winner is Jakube using Pyth with 41 bytes. Thank you to all who participated. I will now task myself with coming up with more complicated challenges.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	cookie("plain")
	cookie("chocolate")
	cookie("nut")
}

func cookie(s string) {
	switch strings.ToLower(s) {
	case "chocolate":
		fmt.Println(CHOCOLATE)
	case "nut":
		fmt.Println(NUT)
	default:
		fmt.Println(PLAIN)
	}
}

const PLAIN = `
     ___
    /   \
    |   |
    \___/
`

const CHOCOLATE = `
     ___
    /. .\
    | . |
    \___/
`

const NUT = `
     ___
    /^  \
    |^ ^|
    \___/
`
