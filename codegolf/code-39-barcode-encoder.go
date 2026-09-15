/*

Write a function or program that encodes a string into a Code 39 format barcode, where each character is encoded as five bars separated by four gaps. Either two of the bars and one of the gaps are wide and others are narrow (10*4 codes), or three of the gaps are wide and none of the bars are (4 codes). This gives 44 different codes, from which one is a reserved code that is used to denote the start and end of the encoded string.

The challenge
The input is a string containing only characters from the set

1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ-. +/$%
The output is the string encoded as a barcode string. The narrow gap and intercharacter gaps are a single space and a wide gap is three spaces. The narrow bar is the UTF-8 byte sequence for the Unicode character "Full block", █, i.e. 0xE2 0x96 0x88 and wide bar is three such byte sequences / characters (███). The full list of codes is:

      Spaces
      0100 0010 0001 1000 1011 1101 1110 0111
Bars
00000                       +    /    $   %
10001   1    A    K    U
01001   2    B    L    V
11000   3    C    M    W
00101   4    D    N    X
10100   5    E    O    Y
01100   6    F    P    Z
00011   7    G    Q    -
10010   8    H    R    .
01010   9    I    S  space          1=wide
00110   0    J    T  start/end      0=narrow
The bars and spaces are interleaved, starting at a bar, so for example Q is

bar   0 0 0  1     1
code  █ █ █ ███   ███
space  0 0 0    1
After encoding all the characters, the string is delimited at both ends with █   █ ███ ███ █. The intercharacter gap, a single space, is inserted between every letter. Your solution may output trailing spaces and a trailing newline (in that order).

Examples
""     → "█   █ ███ ███ █ █   █ ███ ███ █"

"A"    → "█   █ ███ ███ █ ███ █ █   █ ███ █   █ ███ ███ █"

"C++"  → "█   █ ███ ███ █ ███ ███ █   █ █ █   █ █   █   █ █   █ █   █   █ █   █ ███ ███ █"

"GOLF" → "█   █ ███ ███ █ █ █ █   ███ ███ ███ █ ███ █   █ █ ███ █ █   ███ █ ███ ███   █ █ █   █ ███ ███ █"

Standard input/output formats are allowed and standard loopholes are disallowed. This is code-golf, so the shortest code measured in bytes wins!

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(barcode("") == "█   █ ███ ███ █ █   █ ███ ███ █")
	assert(barcode("A") == "█   █ ███ ███ █ ███ █ █   █ ███ █   █ ███ ███ █")
	assert(barcode("C++") == "█   █ ███ ███ █ ███ ███ █   █ █ █   █ █   █   █ █   █ █   █   █ █   █ ███ ███ █")
	assert(barcode("GOLF") == "█   █ ███ ███ █ █ █ █   ███ ███ ███ █ ███ █   █ █ ███ █ █   ███ █ ███ ███   █ █ █   █ ███ ███ █")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func barcode(s string) string {
	w := new(bytes.Buffer)
	fmt.Fprintf(w, "%s ", marker)
	for _, r := range s {
		fmt.Fprintf(w, "%s ", symbols[r])
	}
	fmt.Fprint(w, marker)
	return w.String()
}

const marker = "█   █ ███ ███ █"

var symbols = map[rune]string{
	' ': "█   ███ █ ███ █",
	'$': "█   █   █   █ █",
	'%': "█ █   █   █   █",
	'+': "█   █ █   █   █",
	'-': "█   █ █ ███ ███",
	'.': "███   █ █ ███ █",
	'/': "█   █   █ █   █",
	'0': "█ █   ███ ███ █",
	'1': "███ █   █ █ ███",
	'2': "█ ███   █ █ ███",
	'3': "███ ███   █ █ █",
	'4': "█ █   ███ █ ███",
	'5': "███ █   ███ █ █",
	'6': "█ ███   ███ █ █",
	'7': "█ █   █ ███ ███",
	'8': "███ █   █ ███ █",
	'9': "█ ███   █ ███ █",
	'A': "███ █ █   █ ███",
	'B': "█ ███ █   █ ███",
	'C': "███ ███ █   █ █",
	'D': "█ █ ███   █ ███",
	'E': "███ █ ███   █ █",
	'F': "█ ███ ███   █ █",
	'G': "█ █ █   ███ ███",
	'H': "███ █ █   ███ █",
	'I': "█ ███ █   ███ █",
	'J': "█ █ ███   ███ █",
	'K': "███ █ █ █   ███",
	'L': "█ ███ █ █   ███",
	'M': "███ ███ █ █   █",
	'N': "█ █ ███ █   ███",
	'O': "███ █ ███ █   █",
	'P': "█ ███ ███ █   █",
	'Q': "█ █ █ ███   ███",
	'R': "███ █ █ ███   █",
	'S': "█ ███ █ ███   █",
	'T': "█ █ ███ ███   █",
	'U': "███   █ █ █ ███",
	'V': "█   ███ █ █ ███",
	'W': "███   ███ █ █ █",
	'X': "█   █ ███ █ ███",
	'Y': "███   █ ███ █ █",
	'Z': "█   ███ ███ █ █",
}
