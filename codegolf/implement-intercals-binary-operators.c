/*

The Compiler Language With No Pronounceable Acronym, abbreviated INTERCAL, is a very unique programming language. Among its unreproducible qualities are its binary operators.

INTERCAL's two binary operators are interleave (also known as mingle), and select. Interleave is represented with a change (¢), and select is represented with a sqiggle (~).

Interleave works by taking two numbers in the range 0-65535 and alternating their bits. For instance:

234 ¢ 4321
234   = 0000011101010
4321  = 1000011100001
Result: 01000000001111110010001001
Output: 16841865
Select works by taking two numbers in the range 0-65535, taking the bits in the first operand which are in the same position as 1s in the second operand, and right packing those bits.

2345 ~ 7245
2345  = 0100100101001
7245  = 1110001001101
Taken : 010   0  10 1
Result: 0100101
Output: 37
In this challenge, you will be given a binary expression using either the interleave or select operation. You must calculate the result, using the fewest possible bytes.

The expression will be given as a space separated string, consisting of an integer in 0-65535, a space, either ¢ or ~, a space, and an integer in 0-65535.

Input and output may be through any standard system (STDIN, function, command line, etc.). Standard loopholes banned.

Examples:

5 ¢ 6
54

5 ~ 6
2

51234 ¢ 60003
4106492941

51234 ~ 60003
422
This is code golf - fewest bytes wins. Good luck.

EDIT: Since some languages do not support INTERCAL's change (¢) symbol, you may use the big money ($) symbol instead, at a 5 byte penalty.

*/

#include <assert.h>
#include <stdint.h>

uint32_t
interleave(uint16_t a, uint16_t b)
{
	uint32_t i, r, x, y;

	r = 0;
	for (i = 0; i < 16; i++) {
		x = a & (1UL << i);
		y = b & (1UL << i);
		x <<= i + 1;
		y <<= i;
		r |= x | y;
	}
	return r;
}

uint16_t
select(uint16_t a, uint16_t b)
{
	uint16_t i, r, x, y;

	r = 0;
	for (i = 16; i > 0; i--) {
		x = a & (1UL << (i - 1));
		y = b & (1UL << (i - 1));
		if (y)
			r = (r << 1) | !!(x & y);
	}
	return r;
}

int
main(void)
{
	assert(interleave(234, 4321) == 16841865UL);
	assert(interleave(5, 6) == 54);
	assert(interleave(51234UL, 60003UL) == 4106492941UL);

	assert(select(2345, 7245) == 37);
	assert(select(5, 6) == 2);
	assert(select(51234UL, 60003UL) == 422);

	return 0;
}
