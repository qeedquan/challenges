/*

Description
There is a crisis unfolding in Reddit. For many years, Redditors have continued to evolve sh*tposting to new highs, but it seems progress has slowed in recent times. Your mission, should you choose to accept it, is to create a state of the art rektangular sh*tpost generator and bring sh*tposting into the 21st century.

Given a word, a width and a length, you must print a rektangle with the word of the given dimensions.

Formal Inputs & Outputs
Input description
The input is a string word, a width and a height

Output description
Quality rektangles. See examples. Any orientation of the rektangle is acceptable

Examples
Input: "REKT", width=1, height=1

Output:

 R E K T
 E     K
 K     E
 T K E R
Input: "REKT", width=2, height=2

Output:

  T K E R E K T
  K     E     K
  E     K     E
  R E K T K E R
  E     K     E
  K     E     K
  T K E R E K T
Notes/Hints
None

Bonus
Many fun bonuses possible - the more ways you can squeeze REKT into different shapes, the better.

Print rektangles rotated by 45 degrees.

Print words in other shapes (? surprise me)

Creatively colored output? Rainbow rektangles would be glorious.

Credit
This challenge was submitted by u/stonerbobo

Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas. Thank you!

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	recktangle("REKT", 1, 1)
	recktangle("REKT", 2, 2)
	recktangle("ABCDEF", 3, 3)
	recktangle("HILLBILL", 3, 2)
}

func recktangle(word string, width, height int) {
	if width < 1 || height < 1 {
		return
	}

	if len(word) < 2 {
		fmt.Println(word)
		return
	}

	if height&1 == 0 {
		word = reverse(word)
	}
	order := word + reverse(word)[1:len(word)-1]
	size := len(word) - 1

	for y := range size*height + 1 {
		for x := range size*width + 1 {
			if x%size == 0 || y%size == 0 {
				fmt.Printf("%c ", order[(x+y)%len(order)])
			} else {
				fmt.Printf("  ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func reverse(word string) string {
	runes := []rune(word)
	slices.Reverse(runes)
	return string(runes)
}
