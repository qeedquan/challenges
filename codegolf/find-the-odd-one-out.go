/*

Challenge
The goal of this challenge is to generate and output a 16×32 (height × width) grid where all cells contain a decoy character, except for a random single cell that contains the target character.
The input will be a pair of ASCII characters: [target,decoy], where target is the character to find, and decoy is the character that fills the rest of the grid.
The selection of the target cell must be uniformly random from among the 512 cells, ensuring that each cell has an equal chance (1/512) of being chosen for modification.

Examples
Input

[0,O]

Output

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOO0OOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
Input

[v,w]

Output

wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wvwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

[target,decoy] suggestions
[0,O] [1,l] [1,I] [2,Z] [5,S] [8,B] [v,u] [m,n]
[b,d] [p,q] [C,G] [E,F] [V,U] [V,Y] [s,z] [6,9]
[D,O] [&,8] [C,O] [$,S] [R,P] [8,3] [4,A] [c,¢]

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fakeout('0', 'O')
	fakeout('v', 'w')
}

func fakeout(t, d rune) {
	const (
		W = 32
		H = 16
	)

	i := rand.Intn(W * H)
	X := i % W
	Y := i / W
	for y := range H {
		for x := range W {
			if x == X && y == Y {
				fmt.Printf("%c", t)
			} else {
				fmt.Printf("%c", d)
			}
		}
		fmt.Println()
	}
	fmt.Println()
}
