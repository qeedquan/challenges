/*

Challenge
Inspired by this video.

As you may know, a palindrome is a word that is spelled the same forward as it is backward. The word "PULP" is not a palindrome, but when translated into Morse Code (with the spacing between letters removed), "PULP" becomes ".--...-.-...--." which is a palindrome. Your task is to write a program or function which takes a string and returns whether that word is a palindrome in International Morse Code.

A: .-
B: -...
C: -.-.
D: -..
E: .
F: ..-.
G: --.
H: ....
I: ..
J: .---
K: -.-
L: .-..
M: --
N: -.
O: ---
P: .--.
Q: --.-
R: .-.
S: ...
T: -
U: ..-
V: ...-
W: .--
X: -..-
Y: -.--
Z: --..
Rules
Input
Input can be taken in any reasonable format. The input string will contain only letters in any case you prefer. The string will not contain spaces, numbers, or punctuation.

Output
Your program should output 1 of 2 constant distinct results based on whether the input is a palindrome, e.g. True/False, 1/0, HOTDOG/NOTHOTDOG

Scoring
This is code-golf so shortest answer in bytes wins. Standard loopholes are forbidden.

Test Cases
Input	Output
"PULP"	True
"RESEARCHER"	True
"HOTDOGS"	True
""	True
"A"	False
"RACECAR"	False
"PROGRAMMING"	False
"PUZZLES"	False

*/

package main

import (
	"bytes"
	"slices"
	"strings"
)

func main() {
	assert(palindrome("PULP") == true)
	assert(palindrome("RESEARCHER") == true)
	assert(palindrome("HOTDOGS") == true)
	assert(palindrome("") == true)
	assert(palindrome("A") == false)
	assert(palindrome("RACECAR") == false)
	assert(palindrome("PROGRAMMING") == false)
	assert(palindrome("PUZZLES") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func palindrome(s string) bool {
	w := new(bytes.Buffer)
	for _, r := range s {
		w.WriteString(char2morse(r))
	}

	b := w.Bytes()
	for i := 0; i < len(b)/2; i++ {
		if b[i] != b[len(b)-i-1] {
			return false
		}
	}
	return true
}

/*

@lynn

https://i.sstatic.net/zkE3i.png

*/

func char2morse(c rune) string {
	const tree = " ETIANMSURWDKGOHVF L PJBXCYZQ"

	w := new(bytes.Buffer)
	i := strings.IndexRune(tree, c)
	for ; i > 0; i = (i - 1) >> 1 {
		if i&1 == 0 {
			w.WriteRune('-')
		} else {
			w.WriteRune('.')
		}
	}

	b := w.Bytes()
	slices.Reverse(b)
	return string(b)
}
