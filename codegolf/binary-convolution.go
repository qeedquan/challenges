/*

A binary convolution is described by a number M, and is applied to a number N.
For each bit in the binary representation of M, if the bit is set (1), the corresponding bit in the output is given by XORing the two bits adjacent to the corresponding bit in N (wrapping around when necessary).
If the bit is not set (0), then the corresponding bit in the output is given by the corresponding bit in N.

A worked example (with 8-bit values):

Let N = 150, M = 59. Their binary respresentations are (respectively) 10010110 and 00111011.
Based on M's binary representation, bits 0, 1, 3, 4, and 5 are convolved.
The result for bit 0 is given by XORing bits 1 and 7 (since we wrap around), yielding 1.
The result for bit 1 is given by XORing bits 0 and 2, yielding 0.
The result for bit 2 is given by the original bit 2, yielding 1.
The result for bit 3 is given by XORing bits 2 and 4, yielding 0.
The result for bit 4 is given by XORing bits 3 and 5, yielding 0.
The result for bit 5 is given by XORing bits 4 and 6, yielding 1.
The results for bits 6 and 7 are given by the original bits 6 and 7, yielding 0 and 1.
The output is thus 10100110 (166).

The Challenge
Given N and M, output the result of performing the binary convolution described by M upon N.
Input and output may be in any convenient, consistent, and unambiguous format.
N and M will always be in the (inclusive) range [0, 255] (8-bit unsigned integers), and their binary representations should be padded to 8 bits for performing the binary convolution.

Test Cases
150 59 -> 166
242 209 -> 178
1 17 -> 0
189 139 -> 181
215 104 -> 215
79 214 -> 25
190 207 -> 50
61 139 -> 180
140 110 -> 206
252 115 -> 143
83 76 -> 31
244 25 -> 245
24 124 -> 60
180 41 -> 181
105 239 -> 102
215 125 -> 198
49 183 -> 178
183 158 -> 181
158 55 -> 186
215 117 -> 198
255 12 -> 243

*/

package main

func main() {
	assert(binconv(150, 59) == 166)
	assert(binconv(242, 209) == 178)
	assert(binconv(1, 17) == 0)
	assert(binconv(189, 139) == 181)
	assert(binconv(215, 104) == 215)
	assert(binconv(79, 214) == 25)
	assert(binconv(190, 207) == 50)
	assert(binconv(61, 139) == 180)
	assert(binconv(140, 110) == 206)
	assert(binconv(252, 115) == 143)
	assert(binconv(83, 76) == 31)
	assert(binconv(244, 25) == 245)
	assert(binconv(24, 124) == 60)
	assert(binconv(180, 41) == 181)
	assert(binconv(105, 239) == 102)
	assert(binconv(215, 125) == 198)
	assert(binconv(49, 183) == 178)
	assert(binconv(183, 158) == 181)
	assert(binconv(158, 55) == 186)
	assert(binconv(215, 117) == 198)
	assert(binconv(255, 12) == 243)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func binconv(n, m uint) uint {
	x := n * 257
	return n ^ m&(n^(x>>1)^(x>>7))
}
