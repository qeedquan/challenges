/*

Introduction
While studying, I tried to come up with several ways to cheat a multiple choice test. It basically is a compressed version of the multiple choice answers. The method goes as following:

The answers to the test:

BCAABABA
These can be converted to 3 different arrays, which indicates true or false if the current letter is the answer:

    B  C  A  A  B  A  B  A
A: [0, 0, 1, 1, 0, 1, 0, 1]
B: [1, 0, 0, 0, 1, 0, 1, 0]
C: [0, 1, 0, 0, 0, 0, 0, 0]
Interpreting these numbers as binary would compress this a lot. But this can actually be compressed a bit more. If you know the positions of A and B, you don't need the positions for C. This can be done with a bitwise NOT operator:

A: [0, 0, 1, 1, 0, 1, 0, 1]
B: [1, 0, 0, 0, 1, 0, 1, 0]

A+B: [1, 0, 1, 1, 1, 1, 1, 1]
C:   [0, 1, 0, 0, 0, 0, 0, 0]
Converting the arrays A and B to binary numbers would result in:

A: 00110101
B: 10001010
That means that 8 multiple choice answers can be compressed to two bytes!

Task
Given two numbers in binary, or two arrays consisting of only 0's and 1's with the same length, output the multiple choice answers

Rules
Input can be in the any form you like, like [1, 0, 0, 1] or 1001.
You may provide a program or a function.
You may assume that the input is always valid.
You may also output as a list, separated with spaces, etc.
The multiple choice answers only consist of A's, B's and C's. You may however use lower case instead.
This is code-golf, so the submission with the least amount of bytes wins!
Test cases
Input: [1, 0, 0, 1, 0, 0, 1] [0, 1, 0, 0, 1, 0, 0]
Output: ABCABCA

Input: [0, 0, 0, 0, 1, 0, 1, 1] [1, 0, 1, 0, 0, 0, 0, 0]
Output: BCBCACAA

Input: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0] [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
Output: CCCCCCCCCC

*/

package main

import (
	"bytes"
)

func main() {
	assert(answers([]int{0, 0, 1, 1, 0, 1, 0, 1}, []int{1, 0, 0, 0, 1, 0, 1, 0}) == "BCAABABA")
	assert(answers([]int{1, 0, 0, 1, 0, 0, 1}, []int{0, 1, 0, 0, 1, 0, 0}) == "ABCABCA")
	assert(answers([]int{0, 0, 0, 0, 1, 0, 1, 1}, []int{1, 0, 1, 0, 0, 0, 0, 0}) == "BCBCACAA")
	assert(answers([]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}) == "CCCCCCCCCC")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func answers(a, b []int) string {
	const lut = "CBAC"
	w := new(bytes.Buffer)
	for i := range a {
		x := (a[i]<<1 | b[i]) & 3
		w.WriteByte(lut[x])
	}
	return w.String()
}
