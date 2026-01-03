/*

I often send "bit letter" to my colleagues to talk about our boss or what do we have for dinner.

A bit letter takes 1 char, just like ASCII, but there are some "parameters" in upper 3 bits to describe it.

0           0       0       0  0  0  0  0
[flaguation]   [capital]   [letter index]
[flaguation]
0 = null;
1 = space (before letter);
2 = comma (after letter);
3 = dot (after letter)

[capital]
0 = lowercase;
1 = uppercase;


[letter index]
The letter's index in alphabet, start with 0.

==========================

For example:

  'a'  = 0B00000000 = 0   (a)
  'A'  = 0B00100000 = 32  (A)
  " a" = 0B01000000 = 64  (space + a)
  "A," = 0B10100000 = 160 (A + comma)
  "a." = 0B11000000 = 192 (a + dot)

==========================

Complete function bit_letter(n), for example, if n=[39,4,11,11,142,86,14,17,11,195], function will return 'Hello, world.'.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
bitletter(int *bits, size_t nbits, char *buf)
{
	size_t i;
	int bit;
	int flag;

	for (i = 0; i < nbits; i++) {
		bit = bits[i];
		flag = (bit >> 6) & 3;
		if (flag == 1)
			*buf++ = ' ';

		if (bit & 0x20)
			*buf++ = 'A' + (bit & 0x1f);
		else
			*buf++ = 'a' + (bit & 0x1f);

		if (flag == 2)
			*buf++ = ',';
		else if (flag == 3)
			*buf++ = '.';
	}
	*buf = '\0';
}

void
test(int *bits, size_t nbits, const char *res)
{
	char buf[64];

	bitletter(bits, nbits, buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	int bits1[] = { 39, 4, 11, 11, 142, 86, 14, 17, 11, 195 };
	int bits2[] = { 52, 47, 47, 36, 49, 98, 32, 50, 36 };
	int bits3[] = { 11, 14, 22, 4, 17, 66, 0, 18, 4 };
	int bits4[] = { 52, 15, 47, 4, 49, 64, 45, 3, 107, 14, 54, 4, 49, 66, 32, 18, 36 };
	int bits5[] = { 104, 13, 8, 19, 8, 0, 11, 82, 15, 0, 2, 196 };
	int bits6[] = { 227, 238, 243, 242, 115, 14, 206, 108, 192, 13, 216, 99, 14, 19, 210 };
	int bits7[] = { 34, 14, 12, 12, 0, 146, 68, 149, 132, 145, 152, 150, 135, 132, 145, 132 };
	int bits8[] = { 236, 200, 215, 196, 131, 66, 128, 18, 196, 96, 173, 227, 79, 180, 13, 2, 243, 20, 32, 147, 40, 14, 205 };

	test(bits1, nelem(bits1), "Hello, world.");
	test(bits2, nelem(bits2), "UPPER CASE");
	test(bits3, nelem(bits3), "lower case");
	test(bits4, nelem(bits4), "UpPeR aNd LoWeR cAsE");
	test(bits5, nelem(bits5), " Initial space.");
	test(bits6, nelem(bits6), "D.O.T.S. Too. Ma.ny. Dots.");
	test(bits7, nelem(bits7), "Commas, ev,e,r,y,w,h,e,r,e,");
	test(bits8, nelem(bits8), "M.i.x.e.d, ca,se. AN,D. pU,ncT.uAt,Ion.");

	return 0;
}
