/*

Description
Start with a grid h units high by w units wide. Set a point particle in motion from the upper-left corner of the grid, 45 degrees from the horizontal, so that it crosses from one corner of each unit square to the other. When the particle reaches the bounds of the grid, it ricochets and continues until it reaches another corner.

Given the size of the grid (h and w), and the velocity (v) of the particle in unit squares per second, determine C: the corner where the particle will stop, b: how many times the particle ricocheted off the bounds of the grid, and t: the time it took for the particle to reach C.

Constraints
The particle always starts from the upper-left corner of the grid (and will therefore always end up in one of the other corners).

Since we'll be working with unit squares, h and w are always integers.

Formal Inputs & Outputs
Input description
The input will be an arbitrary number of lines containing h, w, and v, each separated by spaces:

 8 3 1
 15 4 2
Output description
For each line of input, your program should output a line containing C, b, and t, where C can be UR, LR, or LL depending on where the particle ends up:

 LL 9 24
 UR 17 30
Bonus
Instead of a particle, determine the behavior of a rectangle m units high by n units wide. Input should be as follows: h w m n v. So for a 10 by 7 grid with a 3 by 2 rectangle, the input would be:

 10 7 3 2 1
The output format is the same:

 LR 10 35
Finally
Have a good challenge idea like u/sceleris927 did?

Consider submitting it to r/dailyprogrammer_ideas

*/

package main

import "fmt"

func main() {
	assert(solve(8, 3, 0, 0, 1) == "LL 9 24")
	assert(solve(15, 4, 0, 0, 2) == "UR 17 30")
	assert(solve(10, 7, 3, 2, 1) == "LR 10 35")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @ericula solution
func solve(hgt, wdt, dh, dw, vel int) string {
	h0 := hgt - dh
	w0 := wdt - dw
	path := h0 * w0 / gcd(h0, w0)
	time := path / gcd(vel, path)
	nrounds := (vel * time) / path
	vertical := 'U'
	horizontal := 'L'
	if (vel*time/h0)%2 != 0 {
		vertical = 'L'
	}
	if (vel*time/w0)%2 != 0 {
		horizontal = 'R'
	}
	nbounce := (path/h0+path/w0-1)*nrounds - 1
	return fmt.Sprintf("%c%c %d %d", vertical, horizontal, nbounce, time)
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
