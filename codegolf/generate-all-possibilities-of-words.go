/*

This is not the same as m-ss-ng-lette-s

Challenge:

Given a string with masked characters, generate all possible words, inclusive of non-meaningfull words.

Rules:

The sequence of the characters in the string does not change.
The masked character (*) will be one of an English alphabets [a-z].
There are no line breaks, space, numbers, special characters or punctuations.
The output can be a list of non-meaningfull words too.
Any characters in a string can be masked. Not necessarily alternating characters.
For memory constraint, lets keep the maximum length of input as 10.

Example 1:

Input:

*o*
Output:

aoa
aob
aoc
...
...
...
boa
bob
boc
...
...
...
zoa
zob
zoc
...
...
...
zoz
Example 2:

Input:

*e*c*m*
Output:

aeacama
aeacamb
...
...
...
welcome
...
...
zezczmz

This is code-golf, so shortest answer in bytes wins!

*/

package main

import "fmt"

func main() {
	gen("*o*")
	gen("*e*c*m*")
}

func gen(s string) {
	recurse(s, 0, "")
}

func recurse(s string, n int, r string) {
	if n >= len(s) {
		fmt.Println(r)
		return
	}

	c0, c1 := s[n], s[n]
	if s[n] == '*' {
		c0, c1 = 'a', 'z'
	}

	for c := c0; c <= c1; c++ {
		recurse(s, n+1, r+string(c))
	}
}
