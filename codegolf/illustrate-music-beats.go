/*

You know—they look like this:

https://i.sstatic.net/t4uJx.jpg

The goal is to draw a music beats illustration like the following:

=     =      =
=  =  =      =          =
== = ==   =  ==     = ====
== ====  == ===   = = =======
======== == ====  = ========= =
=================================
The rules are:

The width of the illustration is 33 symbols, but if you need—any trailing spaces exceeding this width are allowed.
Each column is made of equals signs (=).
Each column has a random height (the height of the next column shouldn’t depend in any way on the height of the previous column), varying from 1 to 6. It’s also fine if it’s at least possible to get some input with no strict math probability (i.e. some inputs could appear more rarely than others).
A column can’t float above the bottom and have gaps in it.
Since every column has the minimal height of 1, the last row can’t have any gaps either—it always consists of 33 equals signs.
Since it’s possible to have no columns with the height of 6 (it’s all random after all): in this case you don’t need to have a top line made of spaces. Applies to any edge cases of this nature: if suddenly your code provided no columns with the height greater than 1, you don’t need to have additional lines made of spaces above the bottom line.
You don’t take any input.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	beats()
}

func beats() {
	const (
		W = 33
		H = 6
	)

	p := make([]int, W)
	for i := range p {
		p[i] = rand.Intn(H)
	}

	for y := range H {
		for x := range p {
			if p[x] <= y || y+1 >= H {
				fmt.Printf("=")
			} else {
				fmt.Printf(" ")
			}
		}
		fmt.Println()
	}
}
