/*

Greeklish, a portmanteau of the words Greek and English, is a way of writing modern Greek using only ASCII characters. This informal way of writing was extensively used in older applications / web forums that did not support Unicode, and were not programmed to show Greek characters. Nowadays, its use is minimized due to the Unicode support of modern platforms, but there are still some users who opt to write in it.

Input / Output:
Your task in this challenge, should you choose to accept it, is to take as input a lowercase, non-punctuated sentence written in Greeklish and output it in the same format in non-accented modern Greek. To do this conversion you should use the table below. Note that the digraph characters take precedence over single characters during conversion. You are free to opt any acceptable string format that works best for you (e.g., a sentence, a list of words, etc.).

Conversion table
ASCII Character(s)	Greek Character
a	α
b	β
g	γ
d	δ
e	ε
z	ζ
h	η
8	θ
i	ι
k	κ
l	λ
m	μ
n	ν
ks, 3	ξ
o	ο
p	π
r	ρ
s	σ
t	τ
y	υ
f	φ
x	χ
ps, 4	ψ
w	ω

Test cases
geia soy kosme                         ->  γεια σου κοσμε
epsaxna gia mia aggelia sth thleorash  ->  εψαχνα για μια αγγελια στη τηλεοραση
kati 3erei sxetika me ayto             ->  κατι ξερει σχετικα με αυτο
pswnisa ksylina spa8ia                 ->  ψωνισα ξυλινα σπαθια
ekeinh agorase 4aria kai 8ymari        ->  εκεινη αγορασε ψαρια και θυμαρι

Rules
You may use any standard I/O method
Standard loopholes are forbidden
This is code-golf, so shortest answer in bytes wins.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(conv("geia soy kosme") == "γεια σου κοσμε")
	assert(conv("epsaxna gia mia aggelia sth thleorash") == "εψαχνα για μια αγγελια στη τηλεοραση")
	assert(conv("kati 3erei sxetika me ayto") == "κατι ξερει σχετικα με αυτο")
	assert(conv("pswnisa ksylina spa8ia") == "ψωνισα ξυλινα σπαθια")
	assert(conv("ekeinh agorase 4aria kai 8ymari") == "εκεινη αγορασε ψαρια και θυμαρι")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func conv(s string) string {
	m := map[string]rune{
		"a":  'α',
		"b":  'β',
		"g":  'γ',
		"d":  'δ',
		"e":  'ε',
		"z":  'ζ',
		"h":  'η',
		"8":  'θ',
		"i":  'ι',
		"k":  'κ',
		"l":  'λ',
		"m":  'μ',
		"n":  'ν',
		"ks": 'ξ',
		"3":  'ξ',
		"o":  'ο',
		"p":  'π',
		"r":  'ρ',
		"s":  'σ',
		"t":  'τ',
		"y":  'υ',
		"f":  'φ',
		"x":  'χ',
		"ps": 'ψ',
		"4":  'ψ',
		"w":  'ω',
	}

	w := new(bytes.Buffer)
	n := len(s)
	for i := 0; i < n; i++ {
		k0 := fmt.Sprintf("%c", s[i])
		k1 := ""
		if i+1 < n {
			k1 = fmt.Sprintf("%c%c", s[i], s[i+1])
		}

		r0 := m[k0]
		r1 := m[k1]
		switch {
		case r1 != 0:
			w.WriteRune(r1)
			i += 1
		case r0 != 0:
			w.WriteRune(r0)
		default:
			w.WriteByte(s[i])
		}
	}
	return w.String()
}
