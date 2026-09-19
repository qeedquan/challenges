/*

Disclaimer: Levenshtein coding is completely unrelated to the Levenshtein edit distance metric.

<Insert long story about why Levenshtein codes need to be calculated here.>

The code
Levenshtein coding is a system of assigning binary codes to nonnegative integers that retains some weird property in probability which isn't relevant for this challenge.
We will denote this code as L(n). Wikipedia describes this as a five-step process:

Initialize the step count variable C to 1.
Write the binary representation of the number without the leading 1 to the beginning of the code.
Let M be the number of bits written in step 2.
If M is not 0, increment C, repeat from step 2 with M as the new number.
Write C 1 bits and a 0 to the beginning of the code.
However, the code can also be described recursively:

If the number is 0, then its code is 0.
Write the binary representation of the number without the leading 1 to the beginning of the code.
Let M be the number of bits written in step 2.
Write L(M) to the beginning of the code.
Write a 1 bit to the beginning of the code.
For those who prefer examples, here is the recursive process for L(87654321), with  denoting concatenation:

https://i.stack.imgur.com/oDKYp.png

The challenge
Write a program or function that, given a number n, outputs the bitstring L(n) in any reasonable format (this includes returning a number with said bits). Standard loopholes are, as always, disallowed.

Examples
Input: 5

Output: 1110001

Input: 30

Output: 111100001110

Input: 87654321

Output: 111110000101001001110010111111110110001

Input: 0

Output: 0

*/

package main

import "fmt"

func main() {
	assert(levcode(5) == "1110001")
	assert(levcode(30) == "111100001110")
	assert(levcode(87654321) == "111110000101001001110010111111110110001")
	assert(levcode(0) == "0")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func levcode(n int) string {
	if n < 0 {
		return ""
	}

	if n == 0 {
		return "0"
	}

	s := fmt.Sprintf("%b", n)
	return fmt.Sprintf("1%s%s", levcode(len(s)-1), s[1:])
}
