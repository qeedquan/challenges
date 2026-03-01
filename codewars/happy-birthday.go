/*

It's your best friend's birthday! You already bought a box for the present. Now you want to pack the present in the box. You want to decorate the box with a ribbon and a bow.

But how much cm of ribbon do you need?

Write the method wrap that calculates that!

A box has a height, a width and a length (in cm). The ribbon is crossed on the side with the largest area. Opposite this side (also the side with the largest area) the loop is bound, calculate with 20 cm more tape.

  wrap(17,32,11) => 162
  wrap(13,13,13) => 124
  wrap(1,3,1) => 32

Notes:
height, width and length will always be > 0

The ribbon and the bow on the present looks like this:

https://i.imgur.com/30HbqCZ.png

*/

package main

import "sort"

func main() {
	assert(wrap(17, 32, 11) == 162)
	assert(wrap(13, 13, 13) == 124)
	assert(wrap(1, 3, 1) == 32)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func wrap(height, width, length int) int {
	dimensions := []int{height, width, length}
	sort.Ints(dimensions)
	return 20 + 2*(dimensions[2]+dimensions[1]+dimensions[0]*2)
}
