/*

The variable star designation is an identifier for a variable star (a star that fluctuates in brightness). It consists of either a 1-2 letter code or (when the letter code is no longer sufficient) a 'V' followed by a number. This code is followed by the genitive of the star constellation the star is found in (eg. "RR Coronae Borealis", in short "RR CrB"), and each constellation has their own independent numbering.

The series of variable star designations inside one constellation is as follows:

start with the letter R and continue alphabetically through Z.
Continue with RR...RZ, then use SS...SZ, TT...TZ and so on until ZZ.
Use AA...AZ, BB...BZ, CC...CZ and so on until reaching QZ, always omitting J in both the first and second positions.
After QZ (the 334th designation) abandon the Latin script and start naming stars with V335, V336, and so on (V followed by the full numeric index).
Note: The second letter is never alphabetically before the first, ie. BA for example is an invalid designation. Single letters before R are unused. J never appears in the designation.

Your Task
Parse a variable star designation and return its index in the series of variable star designations!

The input is a string of just the variable star designation (omitting the constellation reference that is usually included in a full variable star designation). It can be assumed to be a valid variable star designation; validation is not part of this challenge.

Output is a number representing at what index in the series the designation is. The index is 1-based.

Test cases:

QV => 330
U => 4
V5000 => 5000
AB => 56
This is code-golf, so the shortest code wins. Standard rules and loopholes apply.

*/

package main

import (
	"strconv"
	"strings"
)

func main() {
	assert(vsd("QV") == 330)
	assert(vsd("V5000") == 5000)
	assert(vsd("U") == 4)
	assert(vsd("AB") == 56)
	assert(vsd("QZ") == 334)
	assert(vsd("R") == 1)
	assert(vsd("S") == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func vsd(s string) int {
	if strings.HasPrefix(s, "V") {
		return atoi(s[1:])
	}

	v := find1(s)
	if v < 0 {
		v = find2(s)
	}
	return v
}

func atoi(s string) int {
	n, err := strconv.Atoi(s)
	if err != nil {
		return -1
	}
	return n
}

func find1(s string) int {
	if len(s) != 1 || !('R' <= s[0] && s[0] <= 'Z') {
		return -1
	}
	return int(s[0]) - 'R' + 1
}

func find2(s string) int {
	if len(s) != 2 {
		return -1
	}

	v := 10
	for i := 0; i <= 26; i++ {
		a := 'R' + i
		if i > 9 {
			a = 'A' + i - 10
		}
		for b := a; b <= 'Z'; b++ {
			if a == 'J' || b == 'J' {
				continue
			}
			if s[0] == byte(a) && s[1] == byte(b) {
				return v
			}
			v++
		}
	}
	return -1
}
