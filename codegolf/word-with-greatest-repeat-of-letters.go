/*

Recently there was a question on Stack Overflow where the OP was trying to write a function to find the word in a string that has the most repeated letters. It is of course not hard to write one up in seconds, and I wrote one in Javascript as short as I can for fun. But I'm not an expert in code golfing, so I wonder how much shorter can this simple program be!

Challenge
Write a program or function that takes in a string of words and return or print the word with the most repeating single letters.

Rules:

Choose the word with the greatest number of repeating single letters (see examples below)

If no word has repeating letters, return -1.

If two words have the same maximum number of repeating letters, choose the one closer to the start of the string.

The shortest submission in bytes wins.

Input
Take as input a string consisting of one or more space-delimited words. Input can be from STDIN (or closest alternative), command line parameters, or function arguments.

Output
Print the output to STDOUT to return it.

Examples
Consider the string aaabbb cccc. This contains two words: aaabbb and cccc. The word aaabbb has 3 a's and 3 b's, and cccc has 4 c's. So the maximum number of repeated letters in aaabbb is 3 and the maximum in cccc is 4. We want to choose the word with the maximum number of repeated single letters, so the output for aaabbb cccc should be cccc.

Other test cases:

Today, is the greatest day ever!  --> greatest
This is a great day               --> -1
aaabbb cccc                       --> cccc

*/

package main

import (
	"strings"
)

func main() {
	assert(mwr("Today, is the greatest day ever!") == "greatest")
	assert(mwr("This is a great day") == "-1")
	assert(mwr("aaabbb cccc") == "cccc")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mwr(s string) string {
	r, m := "-1", 1
	w := strings.Split(s, " ")
	for i := range w {
		v := value(w[i])
		if v > m {
			r, m = w[i], v
		}
	}
	return r
}

func value(s string) int {
	m := make(map[rune]int)
	v := 0
	for _, r := range s {
		m[r] += 1
		v = max(v, m[r])
	}
	return v
}
