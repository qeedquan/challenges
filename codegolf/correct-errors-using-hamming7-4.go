/*

The Hamming(7,4) code goes back to 1950. Back then Richard Hamming worked as a mathematician at Bell Labs. Every Friday Hamming set the calculating machines to perform a series of calculation, and collected the results on the following Monday. Using parity checks, these machines were able to detect errors during the computation. Frustrated, because he received error messages way too often, Hamming decided to improve the error detection and discovered the famous Hamming codes.

Mechanics of the Hamming(7,4)
The goal of Hamming codes is to create a set of parity bits that overlap such that a single-bit error (one bit is flipped) in a data bit or a parity bit can be detected and corrected. Only if there occur multiple errors, the Hamming code fails of recovering the original data. It may not notice an error at all, or even correct it falsely. Therefore in this challenge we will only deal with single-bit errors.

As an example of the Hamming codes, we will look at the Hamming(7,4) code. Additionally to 4 bits of data d1, d2, d3, d4 it uses 3 parity bits p1, p2, p3, which are calculated using the following equations:

p1 = (d1 + d2 + d4) % 2
p2 = (d1 + d3 + d4) % 2
p3 = (d2 + d3 + d4) % 2
The resulting codeword (data + parity bits) is of the form p1 p2 d1 p3 d2 d3 d4.

Detecting an error works the following way. You recalculate the parity bits, and check if they match the received parity bits. In the following table you can see, that every variety of a single-bit error yields a different matching of the parity bits. Therefore every single-bit error can be localized and corrected.

error in bit | p1 | p2 | d1 | p3 | d2 | d3 | d4 | no error
-------------|---------------------------------------------
p1 matches   | no | yes| no | yes| no | yes| no | yes
p2 matches   | yes| no | no | yes| yes| no | no | yes
p3 matches   | yes| yes| yes| no | no | no | no | yes
Example
Let your data be 1011. The parity bits are p1 = 1 + 0 + 1 = 0, p2 = 1 + 1 + 1 = 1 and p3 = 0 + 1 + 1 = 0. Combine the data and the parity bits and you get the codeword 0110011.

data bits   |   1 011
parity bits | 01 0
--------------------
codeword    | 0110011
Lets say during a transmission or a computation the 6th bit (= 3rd data bit) flips. You receive the word 0110001. The alleged received data is 1001. You calculate the parity bits again p1 = 1 + 0 + 1 = 0, p2 = 1 + 0 + 1 = 0, p3 = 0 + 0 + 1 = 1. Only p1 matches the parity bits of the codeword 0110001. Therefore an error occurred. Looking at the table above, tells us that the error occurred in d3 and you can recover the original data 1011.

Challenge:
Write a function or a program, that receives a word (7 bits), one of the bits might be wrong, and recover the original data. The input (via STDIN, command-line argument, prompt or function argument) format may be a string "0110001", a list or an array [0, 1, 1, 0, 0, 0, 1] or an integer in MSB 0b0110001 = 49. As described above, the order of the input is p1 p2 d1 p3 d2 d3 d4. The output (via return value or STDOUT) has to be of the same format, but in the order d1 d2 d3 d4. Only return/output the 4 data bits.

This is code-golf. Therefore the shortest code wins.

Test cases:
1110000 -> 1000  # no error
1100000 -> 1000  # error at 1st data bit
1111011 -> 1111  # error at 2nd data bit
0110001 -> 1011  # error at 3rd data bit (example)
1011011 -> 1010  # error at 4th data bit
0101001 -> 0001  # error at 1st parity bit
1010000 -> 1000  # error at 2nd parity bit
0100010 -> 0010  # error at 3rd parity bit

*/

package main

func main() {
	assert(fix(0b1110000) == 0b1000)
	assert(fix(0b1100000) == 0b1000)
	assert(fix(0b1111011) == 0b1111)
	assert(fix(0b0110001) == 0b1011)
	assert(fix(0b1011011) == 0b1010)
	assert(fix(0b0101001) == 0b0001)
	assert(fix(0b1010000) == 0b1000)
	assert(fix(0b0100010) == 0b0010)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @edc65 solution
func fix(w uint8) uint8 {
	x := (w ^ w*2 ^ w*4 ^ w/2) & 4
	y := (w/8 ^ w ^ w*2 ^ w/16) & 2
	z := (w/16 ^ w/4 ^ w ^ w/64) & 1
	w ^= 128 >> (x | y | z)
	w = w&7 | ((w / 2) & 8)
	return w
}
