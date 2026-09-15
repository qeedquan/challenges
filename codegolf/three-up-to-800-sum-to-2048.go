/*

(flexibly) Output 3 random integers such that:

Each number is 1 to 800 inclusive
Their sum is 2048
Each valid possibility should be (hypothetically) equally likely.

Unless explicitly designed otherwise, psuedorandom number generators in your language should be assumed to be uniform; for example, random.randrange(100) in Python and Math.floor(100*Math.random()) in JavaScript both hypothetically generate a random integer from 0 to 99 inclusive, where each possibility is equally likely - you can assume this is actually true

Example: All of the following (and more) should be equally likely:

The 3 permutations of [648, 700, 700]
The 3 permutations of [448, 800, 800]
The 6 permutations of [600, 700, 748]
...and so on for every valid triplet of integers.

This is code-golf - shortest code in bytes "wins".

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	x := lut(1, 800, 2048)
	i := rand.Intn(len(x))
	fmt.Println(x[i])
}

func lut(n, m, t int) [][3]int {
	r := [][3]int{}
	for a := n; a <= m; a++ {
		for b := n; b <= m; b++ {
			for c := n; c <= m; c++ {
				if a+b+c == t {
					r = append(r, [3]int{a, b, c})
				}
			}
		}
	}
	return r
}
