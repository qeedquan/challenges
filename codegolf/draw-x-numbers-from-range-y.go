/*

Inspired by this question
https://mathematica.stackexchange.com/questions/312265/how-to-select-a-random-element-from-a-list-without-repetition-until-all-elements

Task:
Given integers X and Y:
Randomly select an int in 1..Y (inclusive), X times. This selection is to be performed without replacement until all values in 1..Y are exhausted, at which point they all become replaced at the same time. This could happen several times.

X may (but is not guaranteed to) be greater than Y and always greater than 0.

Y is greater than 0.

"random" means that for each selection, each value not yet exhausted has about an equal chance of being selected. Relevant defaults (notably, no xkcd 221) apply.

You may not select in 0..Y or any other range instead.

Output format is flexible (array, ordered list, stdout) but each Y-length run may not be differentiable. For example, it is forbidden to output a newline after each Y-wide selection run if selections aren't normally separated by newlines.

examples (obviously since this is random the actual results may vary):

x=5, y=10 -> [ 10, 6, 2, 8, 9 ]
x=10, y=10 -> [ 5, 3, 1, 7, 6, 4, 10, 8, 9, 2 ]
x=15, y=10 -> [ 5, 6, 2, 4, 9, 3, 8, 1, 7, 10, 7, 1, 2, 9, 3 ]
This is code-golf.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(draw(5, 10))
	fmt.Println(draw(10, 10))
	fmt.Println(draw(15, 10))
}

func draw(x, y int) []int {
	r := []int{}
	for len(r) < x {
		for _, v := range rand.Perm(y) {
			r = append(r, v+1)
		}
	}
	return r[:x]
}
