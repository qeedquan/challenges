/*

https://i.sstatic.net/RyZuW.png

Can you render out a version of the BBC Micro Owl logo as per above from code?

Rules:

You can use any programming language you like.
Output can be text or graphic.
Circles don't have to overlap.
Winner:

The answer with the most upvotes wins.
Kudos for anyone that attempts this in BBC basic.

You can read about the BBC Micro here

*/

package main

import "fmt"

func main() {
	owl()
}

// ported from @Oberon solution
func owl() {
	x := []int{256, 191, 424, 104, 376, 60, 316, 30, 286, 15, 287, 15, 383, 67, 403, 153, 325, 102, 341, 153, 511}
	for i := len(x) - 1; i >= 0; i-- {
		if i&1 != 0 {
			fmt.Print(" ")
		}
		for ; x[i] > 0; x[i] >>= 1 {
			if x[i]&1 != 0 {
				fmt.Print("* ")
			} else {
				fmt.Print("  ")
			}
		}
		fmt.Println()
	}
}
