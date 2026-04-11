/*

Perfect Software, Inc. has obtained a government contract to examine text flowing through a highspeed network for the occurrence of certain words.
Your boss, Wally Perfect, has designed a parallel
processing system which checks each word against a group of small perfect hash tables.
A perfect hash function maps its input directly to a fully occupied table. Your job is to construct
the perfect hash functions from the lists of words in each table. The hash function is of the form
⌊C/w⌋ mod n, where C is a positive integer you are to discover, w is an integer representation of an
input word, and n is the length of the table. C must be as small as possible. Note that ⌊⌋ is the floor
function and that ⌊R⌋ for some real number R is the largest integer that is ≤ R.
Here are Wally’s notes on the subject:
Let W = {w1, w2, . . . , wn} consist of positive integers w1 < w2 < . . . < wn. The problem is to find
the smallest positive integer C such that

floor(C/w[i]) mod n != floor(C/w[j]) mod n for all 1 <= i < j <= n

then the next largest C that could resolve the conflict is at least

C must be a multiple of at least one element of W.
If some

floor(C/w[i]) mod n != floor(C/w[j]) mod n for all i != j

then the next largest C that could resolve the conflict is at least

min(floor(C/w[i])+1 * w[i], floor(C/w[j])+1 * w[j])

Since all such conflicts must be resolved, it is advantageous to choose the largest candidate from
among the conflicts as the next C to test.
You are to convert each word to a number by processing each letter from left to right. Consider ‘a’
to be 1, ‘b’ to be 2, . . ., ‘z’ to be 26. Use 5 bits for each letter (shift left by 5 or multiply by 32). Thus
‘a’ = 1, ‘bz’ = (2 · 32) + 26 = 90.

Input
Input to your program will be a series of word lists, one per line, terminated by the end-of-file. Each
line consists of between two and thirteen words of at most five lower case letters each, separated from
each other by at least one blank. There will always be at least one one-letter word.
For each list, you are to print the input line. On the next line, print the C for the hash function
determined by the list. Print a blank line after each C.
C will always fit in a 32-bit integer.

Sample Input
this is a test of some words to try out
a bee see dee
the of and to a in that is i it with for as

Sample Output
this is a test of some words to try out
17247663
a bee see dee
4427
the of and to a in that is i it with for as
667241

*/

package main

func main() {
	assert(gen([]string{"this", "is", "a", "test", "of", "some", "words", "to", "try", "out"}) == 17247663)
	assert(gen([]string{"a", "bee", "see", "dee"}) == 4427)
	assert(gen([]string{"the", "of", "and", "to", "a", "in", "that", "is", "i", "it", "with", "for", "as"}) == 667241)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(w []string) int {
	n := len(w)
	x := make([]int, n)
	for i := range n {
		x[i] = 0
		for j := 0; j < len(w[i]); j++ {
			x[i] = (x[i] << 5) + int(w[i][j]) - 'a' + 1
		}
	}

	c := 1
	for {
		f := false
		for i := range n {
			for j := range i {
				if (c/x[i])%n == (c/x[j])%n {
					f = true
					c = max(c, min(x[i]*(c/x[i]+1), x[j]*(c/x[j]+1)))
				}
			}
		}
		if !f {
			break
		}
	}
	return c
}
