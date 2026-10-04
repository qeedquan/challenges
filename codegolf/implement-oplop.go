/*

Oplop is an algorithm to generate website specific passwords based on a master password and a keyword.

It is described here: http://code.google.com/p/oplop/wiki/HowItWorks

There's an online implementation here: https://oplop.appspot.com/

My attempt in Q is 204 200 167 165 139 characters ignoring whitespace:

{d:.Q.A,.Q.a,(n:"0123456789"),"-_";
b:d 2 sv'6 cut(,/)0b vs'(md5 x,y),2#0x00;
i:b in n;j:i?1b;k:(j _i)?0b;
8#$[0=0+/i;"1";8>j;();b j+(!)k],b}
EDIT: I achieved significant character savings by removing some redundant code from my Hex->Base64 conversion.

2012.03.07 - Cut out 2 more characters

2012.03.11 - Removed duplication and got accurate char count

2012.03.20 - Down to 141

Criteria

Candidate functions/implementations should take two strings as arguments and return an 8 character password as defined in the algorithm.

Judging

Code golf so shortest code takes the prize.

*/

package main

import (
	"bytes"
	"crypto/md5"
	"encoding/base64"
	"strings"
	"unicode"
)

func main() {
	assert(oplop("hello", "world") == "_F4DjTil")
	assert(oplop("12345", "56789") == "dFMJyRx6")
	assert(oplop("", "") == "1B2M2Y8A")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://github.com/brettcannon/oplop

Oplop is a password hashing algorithm. The steps it takes to generate an account password is:

1. Concatenate the master password with the nickname (in that order!).
2. Generate the MD5 hash of the concatenated string.
3. Convert the MD5 hash to URL-safe Base64.
4. See if there are any digits in the first 8 characters.
   If no digits are found ...
   1. Search for the first uninterrupted substring of digits.
   2. If a substring of digits is found, prepend them to the Base64 string.
   3. If no substring is found, prepend a 1.
5. Use the first 8 characters as the account password.

*/

func oplop(pass, nick string) string {
	sum := md5.Sum([]byte(pass + nick))

	enc := base64.StdEncoding.EncodeToString(sum[:])
	enc = escape(enc)

	i := strings.IndexAny(enc, "0123456789")
	switch {
	case i < 0:
		enc = "1" + enc
	case i > 8:
		j := i + 1
		for j < len(enc) && unicode.IsDigit(rune(enc[j])) {
			j++
		}
		enc = enc[i:j] + enc
	}
	return enc[:8]
}

func escape(str string) string {
	buf := new(bytes.Buffer)
	for _, r := range str {
		switch r {
		case '+':
			r = '-'
		case '/':
			r = '_'
		}
		buf.WriteRune(r)
	}
	return buf.String()
}
