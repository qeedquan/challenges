/*

This challenge is simple, given a decimal number, convert to binary, and calculate the sum of the sub-strings of the binary number, whose length is shorter than the original number. Here is an example:

Input:
  11
Binary:
  11 -> 1011
Substrings:
  101 = 5
  011 = 3
  10  = 2
  01  = 1
  11  = 3
  1   = 1
  0   = 0
  1   = 1
  1   = 1
Sum:
  5+3+2+1+3+1+0+1+1=17
Output:
  17
Your program should take a single decimal integer as input and output the sum of the binary sub-strings, as seen above. You may assume the input will always have more than two digits in its binary representation and that in input will not cause any errors during your program's execution.

This is code-golf, shortest code in bytes wins!

Test cases:

2  => 1
3  => 2
4  => 3
5  => 5
6  => 7
7  => 9
8  => 7
9  => 10
10 => 14
11 => 17

*/

package main

import (
	"math/bits"
)

func main() {
	tab := []int{0, 0, 1, 2, 3, 5, 7, 9, 7, 10, 14, 17}
	for i := range tab {
		assert(binsubsum(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func binsubsum(n int) int {
	if n < 2 {
		return 0
	}

	r := 0
	b := bits.UintSize - bits.LeadingZeros(uint(n))
	for i := 0; i < b; i++ {
		for j := 0; j < b-i+1; j++ {
			m := 1<<(b-j) - 1
			s := b - i - j
			r += (n & m) >> s
		}
	}
	return r
}
