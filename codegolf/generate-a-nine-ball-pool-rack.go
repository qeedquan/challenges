/*

Introduction
Nine-Ball is a popular pool game played casually and as a competitive sport.

There is one of each numbered ball, with the numbers 1 to 9. The game starts with all 9 of the balls in a diamond shaped rack, like so:

  1
 2 3
4 9 6
 5 7
  8
The 1 ball is always at the front of the diamond, and the 9 ball is always in the middle, with all the other balls placed randomly (the "X"s in this diagram):

  1
 X X
X 9 X
 X X
  X
Challenge
Your challenge, given no input, is to generate and output random 9-ball pool racks in the text format of the examples. Extra surrounding whitespace is allowed.

Output may be through any convenient method, standard loopholes apply. A new rack MUST be generated on each run, you cannot just produce a single randomly-chosen rack every time. Extra surrounding whitespace is allowed.

Example Outputs
  1
 2 3
4 9 5
 6 7
  8
  1
 8 3
2 9 7
 4 6
  5
  1
 2 8
3 9 7
 5 4
  6

Least bytes per language wins.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	rack()
}

func rack() {
	tab := []string{
		"..1..",
		".2.3.",
		"4.9.6",
		".5.7.",
		"..8..",
	}

	p := rand.Perm(9)
	swap(p, 0, 0)
	swap(p, 4, 8)

	i := 0
	for _, s := range tab {
		for _, c := range s {
			switch c {
			case '.':
				fmt.Printf(" ")
			default:
				fmt.Printf("%d", p[i]+1)
				i++
			}
		}
		fmt.Println()
	}
}

func swap(p []int, n, v int) {
	for i := range p {
		if p[i] == v {
			p[n], p[i] = p[i], p[n]
			break
		}
	}
}
