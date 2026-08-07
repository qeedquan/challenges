/*

This is a simple randomness challenge:
Given a non-negative integer n, and positive integer m,
simulate rolling and summing the results of fair dice,
each of which have sides numbered through.

Here is a basic ungolfed example in Python:

from random import randint
def roll(n, m):
    return sum([randint(1, m) for i in range(n)])

Try it online! (Also includes a basic visualization of the resulting distribution)

This is code golf, so shortest code wins!

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(roll(100, 6))
}

func roll(n, m int) int {
	r := 0
	for i := 0; i < n; i++ {
		r += rand.Intn(m) + 1
	}
	return r
}
