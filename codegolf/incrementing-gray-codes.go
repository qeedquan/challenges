/*

Introduction
A Gray Code is an alternative to binary representation in which a number is incremented by toggling only one bit, rather than a variable amount of bits. Here are some gray codes along with their decimal and binary equivalents:

 decimal | binary | gray
-------------------------
       0 |      0 |    0
-------------------------
       1 |      1 |    1
-------------------------
       2 |     10 |   11
-------------------------
       3 |     11 |   10
-------------------------
       4 |    100 |  110
-------------------------
       5 |    101 |  111
-------------------------
       6 |    110 |  101
-------------------------
       7 |    111 |  100
-------------------------
       8 |   1000 | 1100
-------------------------
       9 |   1001 | 1101
-------------------------
      10 |   1010 | 1111
-------------------------
      11 |   1011 | 1110
-------------------------
      12 |   1100 | 1010
-------------------------
      13 |   1101 | 1011
-------------------------
      14 |   1110 | 1001
-------------------------
      15 |   1111 | 1000
Cyclic Bit Pattern of a Gray Code
Sometimes called "reflected binary", the property of changing only one bit at a time is easily achieved with cyclic bit patterns for each column starting from the least significant bit:

bit 0: 0110011001100110011001100110011001100110011001100110011001100110
bit 1: 0011110000111100001111000011110000111100001111000011110000111100
bit 2: 0000111111110000000011111111000000001111111100000000111111110000
bit 3: 0000000011111111111111110000000000000000111111111111111100000000
bit 4: 0000000000000000111111111111111111111111111111110000000000000000
bit 5: 0000000000000000000000000000000011111111111111111111111111111111
...and so on.

Objective
Given a non-padded input string of a gray code, increment the gray code by alternating a single character in the sequence or prepending a 1 (when incrementing to the next power of 2), then output the result as a non-padded gray code.

Caveats
Do not worry about taking 0 or an empty string as input.
The lowest input will be 1, and there is no upper-bound to the string length other than memory limitations imposed by the environment.
By non-padded string, I mean there will be no leading or trailing whitespace (other than an optional trailing newline), and no leading 0s in the input or output.
I/O formats
The following formats are accepted form for input and output, but strings are encouraged over other formats:

most significant "bit" first
non-padded character array or string of ASCII '1's and '0's
non-padded integer array of 1s and 0s
non-padded boolean array
What's not allowed:

least significant "bit" first
decimal, binary or unary integer
fixed-length data-structure
character array or string of non-printable ASCII indices 1 and 0
Tests
input -> output
1 -> 11
11 -> 10
111 -> 101
1011 -> 1001
1111 -> 1110
10111 -> 10110
101100 -> 100100
100000 -> 1100000
More tests can be added by request.

Criteria
This is code-golf, so shortest program in bytes wins! All ties will be broken by favoring earlier submissions; standard loopholes apply. The best submitted answer will be accepted October 9th, 2016, and updated whenever better answers are given.

*/

package main

func main() {
	assert(inc(0b1) == 0b11)
	assert(inc(0b11) == 0b10)
	assert(inc(0b111) == 0b101)
	assert(inc(0b1011) == 0b1001)
	assert(inc(0b1111) == 0b1110)
	assert(inc(0b10111) == 0b10110)
	assert(inc(0b101100) == 0b100100)
	assert(inc(0b100000) == 0b1100000)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func inc(n uint64) uint64 {
	return int2gray(gray2int(n) + 1)
}

// https://oeis.org/A003188
func int2gray(n uint64) uint64 {
	return n ^ (n >> 1)
}

// https://oeis.org/A006068
func gray2int(n uint64) uint64 {
	s := uint64(1)
	for {
		m := n >> s
		if m == 0 {
			break
		}
		n ^= m
		s <<= 1
	}
	return n
}
