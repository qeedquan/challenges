/*

Background
Given an elementary cellular automaton rule number like, for example, 28 = 00011100…

https://i.stack.imgur.com/Kp6M2.png

We can swap the 2nd bit with the 5th bit
 and the 4th bit with the 7th bit
 to get a rule that acts the same way but mirrored horizontally. This gets us 01000110 = 70.
We can reverse and flip all the bits to get a rule that does the same thing but with black and white reversed: 11000111 = 199.
And we can combine these two processes — it doesn't matter which order we apply them in — to get a mirrored, reversed rule: 10011101 = 157.
Or, as MathWorld puts it:

The mirror image, complement, and mirror complement are rules 70, 199, and 157, respectively.

The automata identified by rules {28, 70, 199, 157} all behave the same way, up to arbitrary distinctions of colors and axis orientation. But because 28 is the lowest of these four numbers, it is the "canonical" rule number.

Task
Write a program or function that takes an input 0≤n≤255
 and decides whether it is a canonical rule number.

These 88 inputs should be give a "true" result:

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 18 19 22 23 24 25 26 27 28 29 30 32 33 34 35 36 37 38 40 41 42 43 44 45 46 50 51 54 56 57 58 60 62 72 73 74 76 77 78 90 94 104 105 106 108 110 122 126 128 130 132 134 136 138 140 142 146 150 152 154 156 160 162 164 168 170 172 178 184 200 204 232
and all other inputs should give a "false" result.

This is code-golf. The I/O defaults apply.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

uint8_t
mirror(uint8_t x)
{
	uint8_t r;

	r = x & 0xa5;
	r |= (x & 0x50) >> 3;
	r |= (x & 0x0a) << 3;
	return r;
}

uint8_t
reverse(uint8_t x)
{
	x = (x & 0xF0) >> 4 | (x & 0x0F) << 4;
	x = (x & 0xCC) >> 2 | (x & 0x33) << 2;
	x = (x & 0xAA) >> 1 | (x & 0x55) << 1;
	return x;
}

bool
canonical(uint8_t x)
{
	uint8_t y, z, w;

	y = mirror(x);
	z = ~reverse(x);
	w = mirror(z);
	return x == min(x, min(y, min(z, w)));
}

int
main(void)
{
	static const uint8_t tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 18, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 32, 33, 34, 35, 36, 37, 38, 40, 41, 42, 43, 44, 45, 46, 50, 51, 54, 56, 57, 58, 60, 62, 72, 73, 74, 76, 77, 78, 90, 94, 104, 105, 106, 108, 110, 122, 126, 128, 130, 132, 134, 136, 138, 140, 142, 146, 150, 152, 154, 156, 160, 162, 164, 168, 170, 172, 178, 184, 200, 204, 232};

	bool lut[256];
	size_t i;

	memset(lut, 0, sizeof(lut));
	for (i = 0; i < nelem(tab); i++)
		lut[tab[i]] = true;

	for (i = 0; i < nelem(lut); i++)
		assert(canonical(i) == lut[i]);

	return 0;
}
