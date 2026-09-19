/*

The Arara are an isolated tribe found in the Amazon who count in pairs. For example one to eight is as follows:

1 = anane
2 = adak
3 = adak anane
4 = adak adak
5 = adak adak anane
6 = adak adak adak
7 = adak adak adak anane
8 = adak adak adak adak

Take a given number and return the Arara's equivalent.

e.g.

countArara(3) 'adak anane'

countArara(8) 'adak adak adak adak'
countArara 3 // -> "adak anane"

countArara 8 // -> "adak adak adak adak"

https://en.wikipedia.org/wiki/Arara_people

*/

package main

import (
	"strings"
)

func main() {
	assert(arara(1) == "anane")
	assert(arara(2) == "adak")
	assert(arara(3) == "adak anane")
	assert(arara(4) == "adak adak")
	assert(arara(5) == "adak adak anane")
	assert(arara(6) == "adak adak adak")
	assert(arara(7) == "adak adak adak anane")
	assert(arara(8) == "adak adak adak adak")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func arara(n int) string {
	if n < 0 {
		return ""
	}

	s := strings.Repeat("adak ", n/2)
	if n&1 != 0 {
		s += "anane"
	}
	return strings.TrimSpace(s)
}
