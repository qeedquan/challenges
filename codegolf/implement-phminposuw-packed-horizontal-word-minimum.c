/*

PHMINPOSUW (Packed Horizontal Word Minimum) is a specialized x86 instruction that finds the minimum value and location of a 16-bit unsigned integer in an 8-element vector packed into a 128-bit register, and places it in another 128-bit register. Write the shortest program, function, or snippet that implements this instruction. (This challenge will use little-endian ordering.)

Input
Input can be in any reasonable format that represents eight unsorted unsigned 16-bit integers. Representing the input as a single 128-bit unsigned integer is preferred. Endianness of the input must be specified in your answer.

(in big endian)
bit: 0123456789ABCDEF 0123456789ABCDEF ... 0123456789ABCDEF 0123456789ABCDEF
     aaaaaaaaaaaaaaaa bbbbbbbbbbbbbbbb ... gggggggggggggggg hhhhhhhhhhhhhhhh
Output
Output can be in any reasonable format that represents eight unsigned 16-bit integers. Representing the output as a single 128-bit unsigned integer is preferred. Endianness of the output must be specified in your answer.

The lowest 16 bits are the minimum value. The next 3 bits are the index of the minimum value. All other bits are zeroed. If there are multiple of the same minimum value, use the lowest index.

(in big endian)
bit: 0123456789ABCDEF 0123456789ABCDEF ... 0123456789ABCDEF 0123456789ABCDEF
     0000000000000000 0000000000000000 ... 0000000000000iii mmmmmmmmmmmmmmmm
Examples
These examples has input/output represented as a list of eight big-endian 16-bit unsigned integers in hexadecimal. For brevity, the output is truncated to the lowest 32 bits, as the rest are zeroes.

08d4 1a45 bb93 0069 f5c0 7a1d c280 a49c
 => 0003 0069
b4e2 c156 78f0 3a0d ef2e f6b0 9a47 2b83
 => 0007 2b83
fdbe 3cca daa0 f39b caee 23ef 4a62 d5ee
 => 0005 23ef
ea03 26b6 3ac9 3d1b e8cb edb5 f9ad 2ed8
 => 0001 26b6
0005 0005 0005 0001 0001 0005 0005 0005
 => 0003 0001
0000 0000 0000 0000 0000 0000 0000 0000
 => 0000 0000
Inspired by "The obscure x86 instruction that made my board game AI only 4% faster but I had fun anyway" by Srcerer

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

void
phminposuw(uint16_t x[8], uint16_t r[2])
{
	int i;

	r[0] = 0;
	r[1] = x[0];
	for (i = 1; i < 8; i++) {
		if (x[i] < r[1]) {
			r[0] = i;
			r[1] = x[i];
		}
	}
}

void
test(uint16_t x[8], uint16_t r[2])
{
	uint16_t v[2];

	phminposuw(x, v);
	printf("%04x %04x\n", v[0], v[1]);
	assert(!memcmp(v, r, sizeof(v)));
}

int
main()
{
	uint16_t x1[] = { 0x08d4, 0x1a45, 0xbb93, 0x0069, 0xf5c0, 0x7a1d, 0xc280, 0xa49c };
	uint16_t x2[] = { 0xb4e2, 0xc156, 0x78f0, 0x3a0d, 0xef2e, 0xf6b0, 0x9a47, 0x2b83 };
	uint16_t x3[] = { 0xfdbe, 0x3cca, 0xdaa0, 0xf39b, 0xcaee, 0x23ef, 0x4a62, 0xd5ee };
	uint16_t x4[] = { 0xea03, 0x26b6, 0x3ac9, 0x3d1b, 0xe8cb, 0xedb5, 0xf9ad, 0x2ed8 };
	uint16_t x5[] = { 0x0005, 0x0005, 0x0005, 0x0001, 0x0001, 0x0005, 0x0005, 0x0005 };
	uint16_t x6[] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 };

	uint16_t r1[] = { 0x0003, 0x0069 };
	uint16_t r2[] = { 0x0007, 0x2b83 };
	uint16_t r3[] = { 0x0005, 0x23ef };
	uint16_t r4[] = { 0x0001, 0x26b6 };
	uint16_t r5[] = { 0x0003, 0x0001 };
	uint16_t r6[] = { 0x0000, 0x0000 };

	test(x1, r1);
	test(x2, r2);
	test(x3, r3);
	test(x4, r4);
	test(x5, r5);
	test(x6, r6);

	return 0;
}
