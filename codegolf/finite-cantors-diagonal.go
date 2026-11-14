/*

Given a list of N integers, each with N digits, output a number which differs from the first number because of the first digit, the second number because of the second digit, etc.

Example
Given this list:

1234
4815
1623
4211
The number 2932's first digit is different from the first number's first digit, its second digit is different from the second number's second digit, etc. Therefore it would be a valid output.

Inputs
You may take both the list and N as input, or only the list if you wish.
Each integer in the list will necessarily have as many digits as the length of the list (N)
Numbers will not have any leading zeroes
The input list must contain numbers and not strings.
You may take inputs as function arguments, through STDIN, or anything similar.
You may assume that the list will not be longer than 10 elements (and no number in the list will be bigger than 2147483647)

Outputs
It is not sufficient that the output is not in the list. The digits must differ as explained above.
You can use any digit selection strategy that respects the constraint of different digits.
The number cannot have leading zeroes
You may output the number through STDOUT, return it from a function, etc.

Test cases
Input:
12345678
23456789
34567890
45678901
56789012
67890123
78901234
89012345

Possible output: 24680246


Input:
1

Possible output: 2

Scoring
This is code-golf, so the shortest answer in bytes wins.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(diagonalize([]string{
		"1234",
		"4815",
		"1623",
		"4211",
	}) == "2932")

	assert(diagonalize([]string{
		"12345678",
		"23456789",
		"34567890",
		"45678901",
		"56789012",
		"67890123",
		"78901234",
		"89012345",
	}) == "24680246")

	assert(diagonalize([]string{
		"1",
	}) == "2")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func diagonalize(s []string) string {
	w := new(bytes.Buffer)
	n := len(s)
	for i, t := range s {
		m := len(t)
		if n != m {
			return fmt.Sprintf("invalid list length at %d: %d", i, m)
		}

		c := t[i]
		if !('0' <= c && c <= '9') {
			return fmt.Sprintf("invalid string %q", t)
		}

		if c++; c > '9' {
			c = '0'
		}
		w.WriteByte(c)
	}
	return w.String()
}
