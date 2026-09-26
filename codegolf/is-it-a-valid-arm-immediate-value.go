/*

Exposition
In this challenge, I am talking about ARM assembly language. ARM is a 32-bit RISC processor; I'll use instruction set up to architecture v6.

To load a constant ("immediate") value into a register, use the MOV instruction:

MOV r8, #42
To load negative values, use the MVN instruction, with a bit-complement of the operand:

MVN r8, #41
You can't load any 32-bit value with this instruction. Acceptable values are:

Any 8-bit value: 0...255
Any 8-bit value, rotated right by an even number of bits, 2...30
A bit-complement of any value as described above (a good assembler will accept such operands and turn MOV into MVN)

Challenge
Make code which determines if the given input is a valid operand for a MOV instruction.

Input
A number in the range 0...2^32-1 or -2^31...2^31-1, whatever is easier.

If you represent the number as a string, use decimal notation.

Output
True or false, as usual.

Examples
(some of them taken from this nice site with explanations).

True:

0x000000FF
0xffffd63f
0xFF000000
0b1010101100000000 (8 arbitrary bits, followed by even number of zeros)
0b11110000000000000000000000001111 (11111111 rotated right by 4 bits)

False:

0x000001FE
0xF000F000
0x55550000
0xfffffe01
0b10101011000000000 (8 bits but followed by odd number of zeros)
0b11110000000000000010000000001111 (too many spread-out 1-bits)

*/

package main

import (
	"math"
	"math/bits"
)

func main() {
	assert(imm(42) == true)
	assert(imm(^uint32(41)) == true)
	assert(imm(0x000000FF) == true)
	assert(imm(0xffffd63f) == true)
	assert(imm(0xFF000000) == true)
	assert(imm(0b1010101100000000) == true)
	assert(imm(0b11110000000000000000000000001111) == true)

	assert(imm(0x000001FE) == false)
	assert(imm(0xF000F000) == false)
	assert(imm(0x55550000) == false)
	assert(imm(0xfffffe01) == false)
	assert(imm(0b10101011000000000) == false)
	assert(imm(0b11110000000000000010000000001111) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func imm(n uint32) bool {
	for i := 2; i < 31; i += 2 {
		x := bits.RotateLeft32(n, i)
		if bit8(x) {
			return true
		}
	}
	return bit8(n)
}

func bit8(n uint32) bool {
	return n <= math.MaxUint8 || ^n <= math.MaxUint8
}
