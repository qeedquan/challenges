/*

Credits
This challenge originated from @miles.

Create a function that computes the CRC32 hash of an input string. The input will be an ASCII string of any length. The output will be the CRC32 hash of that input string.

Explanation
The algorithm of CRC32 and other CRC are essentially the same, so only CRC3 will be demonstrated here.

Firstly, you have the generator polynomial, which is actually a 4-bit [n+1] integer (would be 33-bit in CRC32).

In this example, the generator polynomial is 1101.

Then, you will have the string to be hashed, which in this example would be 00010010111100101011001101.

00010010111100101011001101|000 (1)    append three [n] "0"s
   1101                        (2)    align with highest bit
00001000111100101011001101|000 (3)    XOR (1) and (2)
    1101                       (4)    align with highest bit
00000101111100101011001101|000 (5)    XOR (3) and (4)
     1101                      (6)    align with highest bit
00000011011100101011001101|000 (7)    XOR (5) and (6)
      1101                     (8)    align with highest bit
00000000001100101011001101|000 (9)    XOR (7) and (8)
          1101                 (10)   align with highest bit
00000000000001101011001101|000 (11)   XOR (9) and (10)
             1101              (12)   align with highest bit
00000000000000000011001101|000 (13)   XOR (11) and (12)
                  1101         (14)   align with highest bit
00000000000000000000011101|000 (15)   XOR (13) and (14)
                     1101      (16)   align with highest bit
00000000000000000000000111|000 (17)   XOR (15) and (16)
                       110 1   (18)   align with highest bit
00000000000000000000000001|100 (19)   XOR (17) and (18)
                         1 101 (20)   align with highest bit
00000000000000000000000000|001 (21)   XOR (19) and (20)
^--------REGION 1--------^ ^2^
The remainder obtained at (21), when region 1 is zero, which is 001, would be the result of the CRC3 hash.

Specs
The generator polynomial is 0x104C11DB7, or 0b100000100110000010001110110110111, or 4374732215.
Input can be a string or a list of integers, or any other reasonable format.
Output be a hex string or just an integer, or any other reasonable format.
Built-ins that compute the CRC32 hash are not allowed.
Goal
Standard rules for code-golf apply.

The shortest code wins.

Test cases
input         output      (hex)
"code-golf"   147743960   08CE64D8
"jelly"       1699969158  65537886
""            0           00000000

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

void
maketable(ulong poly, ulong tab[256])
{
	ulong i, j, c;

	for (i = 0; i < 256; i++) {
		c = i << 24;
		for (j = 0; j < 8; j++) {
			if (c & 0x80000000UL)
				c = (c << 1) ^ poly;
			else
				c = (c << 1);
		}
		tab[i] = c & 0xFFFFFFFFUL;
	}
}

ulong
crc32(ulong crc, const uchar *data, size_t len, ulong tab[256])
{
	ulong i;
	size_t n;

	for (n = 0; n < len; n++) {
		i = ((crc >> 24) ^ data[n]) & 0xFF;
		crc = (crc << 8) ^ tab[i];
	}
	crc &= 0xFFFFFFFFUL;
	return crc;
}

void
test(const uchar *data, size_t len, ulong result)
{
	ulong tab[256];
	ulong crc;

	maketable(0x4C11DB7UL, tab);
	crc = crc32(0, data, len, tab);
	printf("%#lx\n", crc);
	assert(crc == result);
}

int
main(void)
{
	uchar data1[] = "code-golf";
	uchar data2[] = "jelly";

	test(data1, sizeof(data1) - 1, 0x08CE64D8UL);
	test(data2, sizeof(data2) - 1, 0x65537886UL);
	test(NULL, 0, 0x0UL);

	return 0;
}
