/*

You've just been hired by a German car manufacturing company. Your first task, as an engineer, is to write a program that computes the ecological footprint of ASCII strings.

The ecological footprint of character is computed as follows:

Write the character's ASCII code in binary, and count the number of 1's.

For example, A has a footprint of 2, but O is dirtier with a footprint of 5.

The global footprint of a string is the sum of the footprints of its characters. An empty string has a footprint of zero.

Your program must accept an ASCII string as parameter (through command line or input), compute its ecological footprint, and output it. The program itself must be ASCII encoded.

There is a hiccup though. As your company wishes to enter a new market with stricter environmental rules, you need to tune your program so that it behaves differently in "test mode". Thus:

The program should output 0 when it receives the string test as parameter.

Scoring

The source code with the smallest ecological footprint wins (and yes, the answer test is forbidden!)

*/

package main

import "math/bits"

func main() {
	assert(footprint("test") == 0)
	assert(footprint("A") == 2)
	assert(footprint("O") == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func footprint(s string) int {
	if s == "test" {
		return 0
	}

	v := 0
	for _, r := range s {
		v += bits.OnesCount(uint(r))
	}
	return v
}
