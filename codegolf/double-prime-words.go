/*

Consider a word/string of length n, only including the letters A-Z, a-z.
A word/string is a double prime word if and only if n is prime and the sum of the letters, s, is also prime, using their numeric position in the alphabet (a=1, B=2, c=3, etc.).

Input can be any combination of upper or lower case alphabetic characters, as there is no numeric difference between a or A.

Output is any appropriate logical format related to your language. i.e. True or False, T or F, 1 or 0, etc.
Specifying what format your output will appear is highly appreciated, but not required. (Output need not include n, s, but I include them below as demonstration and example)

Winning condition is shortest code in bytes able to detect if a string is a double prime, fitting both conditions for n and s to be prime. (I've now included cases from all 4 possible situations of n, s.)

Examples
Input -> Output (n, s)

Prime -> True (5, 61)
han -> True (3, 23)
ASK -> True (3, 31)
pOpCoRn -> True (7, 97)
DiningTable -> True (11, 97)
METER -> True (5, 61)

Hello -> False (5, 52)
SMILE -> False (5, 58)
frown -> False (5, 76)

HelpMe -> False (6, 59)
John -> False (4, 47)
TwEnTy -> False (6, 107)

HelloWorld -> False (10, 124)
Donald -> False (6, 50)
telePHONES -> False (10, 119)

A -> False (1, 1)
C -> False (1, 3) {1 is not prime}
d -> False (1, 4)

*/

package main

import "math/big"

func main() {
	assert(primeword("Prime") == true)
	assert(primeword("han") == true)
	assert(primeword("ASK") == true)
	assert(primeword("pOpCoRn") == true)
	assert(primeword("DiningTable") == true)
	assert(primeword("METER") == true)

	assert(primeword("Hello") == false)
	assert(primeword("SMILE") == false)
	assert(primeword("frown") == false)
	assert(primeword("HelpMe") == false)
	assert(primeword("John") == false)
	assert(primeword("TwEnTy") == false)
	assert(primeword("HelloWorld") == false)
	assert(primeword("Donald") == false)
	assert(primeword("telePHONES") == false)
	assert(primeword("A") == false)
	assert(primeword("C") == false)
	assert(primeword("D") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func primeword(s string) bool {
	var n, v int64
	for _, r := range s {
		switch {
		case 'a' <= r && r <= 'z':
			r = r - 'a' + 1
		case 'A' <= r && r <= 'Z':
			r = r - 'A' + 1
		}

		v += int64(r)
		n += 1
	}

	x := big.NewInt(v)
	y := big.NewInt(n)
	return x.ProbablyPrime(2) && y.ProbablyPrime(2)
}
