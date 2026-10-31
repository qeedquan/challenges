/*

Story
The Pied Piper has been enlisted to play his magical tune and coax all the rats out of town.

But some of the rats are deaf and are going the wrong way!

Kata Task
How many deaf rats are there?

Legend
P = The Pied Piper
O~ = Rat going left
~O = Rat going right
Example
ex1 ~O~O~O~O P has 0 deaf rats
ex2 P O~ O~ ~O O~ has 1 deaf rat
ex3 ~O~O~O~OP~O~OO~ has 2 deaf rats

*/

package main

import "strings"

func main() {
	assert(deafrats("~O~O~O~O P") == 0)
	assert(deafrats("P O~ O~ ~O O~") == 1)
	assert(deafrats("~O~O~O~OP~O~OO~") == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func deafrats(s string) int {
	s = strings.Replace(s, " ", "", -1)
	p := strings.IndexRune(s, 'P')
	if p < 0 {
		return 0
	}

	c := 0
	for i := 0; i < p; i += 2 {
		if s[i] == 'O' {
			c += 1
		}
	}
	for i := p + 1; i < len(s); i += 2 {
		if s[i] == '~' {
			c += 1
		}
	}
	return c
}
