/*

Concept
In what ways can you scramble the English alphabet so that it can still be sung to the tune Twinkle Twinkle Little Star without ruining the tune?

Rules
Swapping

Let's just assume the letters contained in each of the following sets can be swapped freely by default without ruining the tune:

{ A, J, K }
{ B, C, D, E, G, P, T, V, Z }
{ I, Y }
{ Q, U }
{ S, X, F }
{ M, N }

Therefore H, L, O, R, and W are locked in place
Output

The program needs to output a single RANDOM string (or list of characters) containing the complete English alphabet in any order provided that order satisfies the conditions above.
There should be no way for you to predict which string your program will output(if we ignore seeding), meaning you can't just hardcode it.

Your program must have some positive probability (not necessarily uniform) of generating each of the 9!⋅3!⋅3!⋅2!⋅2!⋅2!=104509440 outputs.

There are no particular formatting restrictions regarding spacing, delimiters or case, just be consistent.

Goal

Fewest bytes wins!

Examples:
KCDBPSVHIAJLMNOZQRXGUEWFYT
A,G,Z,V,P,X,C,H,Y,K,J,L,N,M,O,T,U,R,S,D,Q,B,W,F,I,E
KVTDCFBHIJALNMOPURSZQGWXYE
j c d e b x t h i k a l n m o g u r s v q p w f y z
ABCDEFGHIJKLMNOPQRSTUVWXYZ
Nonexample:
HLWROABCDEFZXYGIJKMNPQTSVU

Proof of Concept: (Python3, 529 bytes)
import random
g1 = ['A', 'J', 'K']
g2 = ['B', 'C', 'D', 'E', 'G', 'P', 'T', 'V', 'Z']
g3 = ['I', 'Y']
g4 = ['Q', 'U']
g5 = ['S', 'X', 'F']
g6 = ['M', 'N']
random.shuffle(g1)
random.shuffle(g2)
random.shuffle(g3)
random.shuffle(g4)
random.shuffle(g5)
random.shuffle(g6)
print(g1[0] + g2[0] + g2[1] + g2[2] + g2[3] + g5[0] + g2[4] + 'H' + g3[0] + g1[1] + g1[2] + 'L' + g6[0] + g6[1] + 'O' + g2[5] + g4[0] + 'R' + g5[1] + g2[6] + g4[1] + g2[7] + 'W' + g5[2] + g3[1] + g2[8])

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(output())
}

func output() string {
	g1 := shuffle([]rune{'A', 'J', 'K'})
	g2 := shuffle([]rune{'B', 'C', 'D', 'E', 'G', 'P', 'T', 'V', 'Z'})
	g3 := shuffle([]rune{'I', 'Y'})
	g4 := shuffle([]rune{'Q', 'U'})
	g5 := shuffle([]rune{'S', 'X', 'F'})
	g6 := shuffle([]rune{'M', 'N'})

	return fmt.Sprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
		g1[0], g2[0], g2[1], g2[2], g2[3], g5[0], g2[4], 'H',
		g3[0], g1[1], g1[2], 'L', g6[0], g6[1], 'O',
		g2[5], g4[0], 'R',
		g5[1], g2[6], g4[1], g2[7], 'W',
		g5[2], g3[1], g2[8],
	)
}

func shuffle(a []rune) []rune {
	n := len(a)
	p := rand.Perm(n)
	r := make([]rune, n)
	for i := range r {
		r[i] = a[p[i]]
	}
	return r
}
