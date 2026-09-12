/*

Just about every store nowadays uses Universal Product Code (UPC) barcodes to simplify the checking out process.
If the name doesn't mean anything to you, you will surely recognize what they look like:

https://i.sstatic.net/Mwqut.png

Format
The most common system is UPC-A, which uses 12 digits to represent each specific product.
Each digit is encoded into a series of black and white stripes to allow machines to read the code, a length of seven bits.
There are a total of 11 bits worth of patterns that indicate the beginning, middle, and end of the barcode.
This comes to a total barcode length of 12 × 7 + 11 = 95 bits. (From now on, when binary is used to refer to the color of each bit, 0 is white and 1 is black.)

The beginning and end both have a pattern of 101.
The digits are then divided into 2 groups of 6 and encoded as shown below, with a pattern 01010 between the left and right groups.
This table lists the pattern for each number.
Note that the pattern is different depending on if the digit is on the right or left side (This allows the barcode to be scanned upside down).
However, the pattern for the right is the opposite (swap black for white and vice versa) of that of the left.

https://i.sstatic.net/Hr9TN.png

If you can't see the image above, this is each number's binary equivalent.

#   Left    Right
0   0001101 1110010
1   0011001 1100110
2   0010011 1101100
3   0111101 1000010
4   0100011 1011100
5   0110001 1001110
6   0101111 1010000
7   0111011 1000100
8   0110111 1001000
9   0001011 1110100
Example
Say you have the UPC 022000 125033. (Those aren't random numbers. Leave a comment if you figure out their significance.) You start with this boilerplate that is the same in every barcode:

101xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx01010xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx101
For the digits, you replace each one with the corresponding encoding for the side (left or right) it's on. If you're still confused, see the image below.

https://i.sstatic.net/SYQCC.png

Here is the output in binary with | pipes separating the parts.

101|0001101|0010011|0010011|0001101|0001101|0001101|01010|1100110|1101100|1001110|1110010|1000010|1000010|101
Challenge
Write a program that outputs the UPC-A barcode for the user input. The image's dimensions should be 95 × 30 pixels, with each "bit" being one pixel wide and 30 pixels tall. Black stripes are in rgb(0, 0, 0) and white stripes are consistently transparent or rgb(255, 255, 255).

Notes
Take input from stdin or the command line, or write a function that takes a string or integer (note that input can have leading zeroes, and most languages remove them or convert the number to octal).
Output the image in one of the following ways:
Save it to a file with a name and format (PNG, PBM, etc.) of your choice.
Display it on the screen.
Output its file data to stdout.
You may not use libraries or builtins that generate barcodes (I'm looking at you, Mathematica), although you may use image or graphics libraries.
The last digit of a UPC is usually a check digit, but for these purposes you don't have to worry about it.
Examples
Here are some more examples to test your code with. The binary output is also given for convenience.

Input: 012345678910
Output:
10100011010011001001001101111010100011011000101010101000010001001001000111010011001101110010101
https://i.sstatic.net/TahrX.png

Input: 777777222222
Output:
10101110110111011011101101110110111011011101101010110110011011001101100110110011011001101100101
https://i.sstatic.net/lBWsO.png

Scoring
This is code golf, so the shortest submission (in bytes wins). Tiebreaker goes to the earliest post.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

char *
upcdec(const char *s, char *b)
{
	static const char *sym[][2] = {
		{ "0001101", "1110010" },
		{ "0011001", "1100110" },
		{ "0010011", "1101100" },
		{ "0111101", "1000010" },
		{ "0100011", "1011100" },
		{ "0110001", "1001110" },
		{ "0101111", "1010000" },
		{ "0111011", "1000100" },
		{ "0110111", "1001000" },
		{ "0001011", "1110100" },
	};

	size_t i;
	char *p;
	int c;

	p = b;
	p += sprintf(p, "101");
	for (i = 0; i < 13 && s[i]; i++) {
		if (!isdigit(s[i]))
			return NULL;

		c = s[i] - '0';
		if (i < 6)
			p += sprintf(p, "%s", sym[c][0]);
		else
			p += sprintf(p, "%s", sym[c][1]);

		if (i == 5)
			p += sprintf(p, "01010");
	}
	p += sprintf(p, "101");
	*p = '\0';

	return (i == 12) ? b : NULL;
}

int
upcpbm(const char *fn, const char *s)
{
	FILE *fp;
	int x, y, w, h;

	fp = fopen(fn, "w");
	if (!fp)
		return -errno;

	w = 95;
	h = 30;
	fprintf(fp, "P1\n%d %d\n\n", w, h);
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			fprintf(fp, "%c\n", s[x]);
		}
	}

	fclose(fp);
	return 0;
}

void
test(const char *s, const char *r)
{
	char fn[32];
	char b[128];

	assert(upcdec(s, b));
	puts(b);
	assert(!strcmp(b, r));

	snprintf(fn, sizeof(fn), "%s.pbm", s);
	upcpbm(fn, b);
}

int
main()
{
	test("012345678910", "10100011010011001001001101111010100011011000101010101000010001001001000111010011001101110010101");
	test("777777222222", "10101110110111011011101101110110111011011101101010110110011011001101100110110011011001101100101");

	return 0;
}
