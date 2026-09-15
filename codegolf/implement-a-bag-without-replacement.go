/*

Intro
The Tetris Guidelines specify what RNG is needed for the piece selection to be called a Tetris game, called the Random Generator. Yes, that's the actual name ("Random Generator"). In essence, it acts like a bag without replacement: You can draw pieces out of the bag, but you cannot draw the same piece from the bag until the bag is refilled.

Write a full program, function, or data structure that simulates such a bag without replacement.

Specification
Your program/function/data structure must be able to do the following:

Represent a bag containing 7 distinct integers.
Draw 1 piece from the bag, removing it from the pool of possible pieces. Output the drawn piece.
Each piece drawn is picked uniformly and randomly from the pool of existing pieces.
When the bag is empty, refill the bag.

Other Rules
This is code-golf, so lowest byte count wins!
Standard loopholes are forbidden.
You can use any reasonable I/O method.

"Bonuses"
These bonuses aren't worth anything, but imaginary internet cookies if you are able to do them in your solution.

Your bag can hold an arbitrary n distinct items.
Your bag can hold any type of piece (a generic bag).
Your bag can draw an arbitrary n number of pieces at once, refilling as needed.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	sim(7)
}

func sim(n int) {
	for {
		p := rand.Perm(n)
		for i := range p {
			p[i]++
		}
		fmt.Println(p)
	}
}
