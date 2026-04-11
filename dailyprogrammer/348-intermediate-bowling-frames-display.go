/*

Description
Today's challenge will be a variation on a popular introductory programming task, scoring a game of bowling.
However, in this challenge, we won't even actually have to calculate the score.
Today's challenge is to produce the display for the individual frames, given a list of the number of pins knocked down on each frame.

The basic rules are as follows:

The game of bowling consists of 10 frames, where a player gets 2 attempts to knock down 10 pins.

If the player knocks down all 10 pins on the first roll, that should be displayed as X, and the next number will be the first roll of the next frame.

If the player doesn't knock down any pins, that should be displayed as -

If the player gets a spare (knocks down the remaining pins on the second roll of the frame, that should be displayed as /

If you want more details about the rules, see: Challenge #235 [Intermediate] Scoring a Bowling Game

Input Description
You will be given a list of integers that represent the number of pins knocked down on each roll.
Not that this list is not a fixed size, as bowling a perfect game requires only 12 rolls, while most games would use more rolls.

Example:

6 4 5 3 10 10 8 1 8 0 10 6 3 7 3 5 3
Output Description
Your program should output the bowling frames including strikes and spares. The total score is not necessary.

Example:

6/ 53 X  X  81 8- X  63 7/ 53
Challenge Inputs
9  0  9  0  9  0  9  0  9  0  9  0  9  0  9  0  9  0  9  0
10 10 10 10 10 10 10 10 10 10 10 10
5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5
10 3  7  6  1  10 10 10 2  8  9  0  7  3  10 10 10
9  0  3  7  6  1  3  7  8  1  5  5  0  10 8  0  7  3  8  2  8
Challenge Outputs
9- 9- 9- 9- 9- 9- 9- 9- 9- 9-
X  X  X  X  X  X  X  X  X  XXX
5/ 5/ 5/ 5/ 5/ 5/ 5/ 5/ 5/ 5/5
X  3/ 61 X  X  X  2/ 9- 7/ XXX
9- 3/ 61 3/ 81 5/ -/ 8- 7/ 8/8

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(bowlframe("6 4 5 3 10 10 8 1 8 0 10 6 3 7 3 5 3") == "6/ 53 X  X  81 8- X  63 7/ 53")
	assert(bowlframe("9  0  9  0  9  0  9  0  9  0  9  0  9  0  9  0  9  0  9  0") == "9- 9- 9- 9- 9- 9- 9- 9- 9- 9-")
	assert(bowlframe("10 10 10 10 10 10 10 10 10 10 10 10") == "X  X  X  X  X  X  X  X  X  XXX")
	assert(bowlframe("5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5  5") == "5/ 5/ 5/ 5/ 5/ 5/ 5/ 5/ 5/ 5/5")
	assert(bowlframe("10 3  7  6  1  10 10 10 2  8  9  0  7  3  10 10 10") == "X  3/ 61 X  X  X  2/ 9- 7/ XXX")
	assert(bowlframe("9  0  3  7  6  1  3  7  8  1  5  5  0  10 8  0  7  3  8  2  8") == "9- 3/ 61 3/ 81 5/ -/ 8- 7/ 8/8")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bowlframe(s string) string {
	var a, b, c int
	r := bytes.NewBufferString(s)
	w := new(bytes.Buffer)
	for range 9 {
		fmt.Fscan(r, &a)
		b = 10
		if a != 10 {
			fmt.Fscan(r, &b)
		}
		fmt.Fprintf(w, "%c", DIGITS0[a])
		if a+b == 10 {
			fmt.Fprintf(w, "/")
		} else {
			fmt.Fprintf(w, "%c", DIGITS1[b])
		}
		fmt.Fprintf(w, " ")
	}

	fmt.Fscan(r, &a, &b)
	fmt.Fprintf(w, "%c", DIGITS0[a])
	switch {
	case a == 10 && b == 10:
		fmt.Fscan(r, &c)
		fmt.Fprintf(w, "X%c", DIGITS0[c])
	case a == 10:
		fmt.Fscan(r, &c)
		fmt.Fprintf(w, "%c", DIGITS0[b])
		if b+c == 10 {
			fmt.Fprintf(w, "/")
		} else {
			fmt.Fprintf(w, "%c", DIGITS1[c])
		}
	case a+b == 10:
		fmt.Fscan(r, &c)
		fmt.Fprintf(w, "/%c", DIGITS0[c])
	default:
		if a+b == 10 {
			fmt.Fprintf(w, "/")
		} else {
			fmt.Fprintf(w, "%c", DIGITS1[b])
		}
	}
	return w.String()
}

const DIGITS0 = "-123456789X"
const DIGITS1 = "-123456789 "
