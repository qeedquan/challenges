/*

Inspired by this chat mini-challenge.

https://chat.stackexchange.com/transcript/message/49893872#49893872

Given a string as input (ASCII printable characters only), output the string with the letters "raining" down. Each letter must be a random number of lines downward (random between 0 and the length of the string, each having non-zero probability), and only one character per column. All possible outputs must again have a non-zero probability of occurring.

That's maybe a little confusing, so here's an example (taken from that CMC):

Hello World

          d
H
       o
  llo

         l
      W
 e
        r

Note how the H is one space down, the d is zero down, and the llo all happen to line up. The r is the farthest down, at 9, but is still less than the string length away from the top. This is just one example, there are dozens of other possibilities for input Hello World.

Other examples could be:

test

t
 e
  s
   t


PP&CG

  & G
 P

P  C

    Input and output can be given by any convenient method.
    The input is guaranteed non-empty (i.e., you'll never receive "" as input).
    You can print it to STDOUT or return it as a function result.
    Either a full program or a function are acceptable.
    Any amount of extraneous whitespace is acceptable, so long as the characters line up appropriately (e.g., feel free to pad as a rectangle).
    Standard loopholes are forbidden.
    This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	rain("Hello World")
	rain("test")
	rain("PP&CG")
}

func rain(s string) {
	r := []rune(s)
	n := len(r)
	p := make([]int, n)
	for i := range p {
		p[i] = rand.Intn(n)
	}
	for y := 0; y < n; y++ {
		for x := 0; x < n; x++ {
			if p[x] == y {
				fmt.Printf("%c", r[x])
			} else {
				fmt.Printf(" ")
			}
		}
		fmt.Println()
	}
}
