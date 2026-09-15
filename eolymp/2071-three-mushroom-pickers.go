/*

Three mushroom pickers — Petro, Vasyl, and Mykola — were returning home from the forest when they decided to take a break and have a snack.
As is often the case, soon they began to boast about their day's successes and eventually started sharing the mushrooms they had found with each other.
Before the break, each of them had a certain integer number of mushrooms.

First, Petro gave Vasyl and Mykola as many mushrooms as they already had.
Mykola quickly realized this wasn't fair, so he gave Vasyl and Petro as many mushrooms as they had at that moment.
Not wanting to be left out, Vasyl also gave each friend as many mushrooms as they had at that moment.
To their surprise, they found that they all ended up with the same number of mushrooms.

Determine how many mushrooms each had before the break, given that together they collected N mushrooms.

Input
A single natural number N (N≤30000) is given in one line.

Output
On a single line, output the numbers of mushrooms each had before the break for Petro, Vasyl, and Mykola, separated by spaces.
It is guaranteed that all input data is correct.

Examples

Input #1
120

Answer #1
65 20 35

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(120))
}

func solve(n int) (int, int, int) {
	l := n / 3
	m := n / 3
	k := n / 3
	a := l / 2
	c := k / 2
	b := m + a + c
	x := a / 2
	y := b / 2
	z := c + x + y

	r0 := z / 2
	r1 := y / 2
	r2 := x + r1 + r0
	return r2, r1, r0
}
