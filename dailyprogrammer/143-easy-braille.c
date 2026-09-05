/*

Braille is a writing system based on a series of raised / lowered bumps on a material, for the purpose of being read through touch rather than sight.
It's an incredibly powerful reading & writing system for those who are blind / visually impaired. Though the letter system has up to 64 unique glyph, 26 are used in English Braille for letters.
The rest are used for numbers, words, accents, ligatures, etc.

Your goal is to read in a string of Braille characters (using standard English Braille defined here) and print off the word in standard English letters. You only have to support the 26 English letters.

Formal Inputs & Outputs
Input Description
Input will consistent of an array of 2x6 space-delimited Braille characters.
This array is always on the same line, so regardless of how long the text is, it will always be on 3-rows of text.
A lowered bump is a dot character '.', while a raised bump is an upper-case 'O' character.

Output Description
Print the transcribed Braille.

Sample Inputs & Outputs
Sample Input
O. O. O. O. O. .O O. O. O. OO
OO .O O. O. .O OO .O OO O. .O
.. .. O. O. O. .O O. O. O. ..

Sample Output
helloworld

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
getbits(const char *p[3], size_t i)
{
	size_t x, y;
	int b;

	b = 0;
	for (y = 0; y < 3; y++) {
		for (x = 0; x < 2; x++) {
			if (p[y][x + i] == 'O')
				b |= 1 << ((y * 2) + x);
		}
	}
	return b;
}

int
getasc(int b)
{
	switch (b) {
	case 0x1:
		return 'a';
	case 0x5:
		return 'b';
	case 0x3:
		return 'c';
	case 0xb:
		return 'd';
	case 0x9:
		return 'e';
	case 0x7:
		return 'f';
	case 0xf:
		return 'g';
	case 0xd:
		return 'h';
	case 0x6:
		return 'i';
	case 0xe:
		return 'j';
	case 0x11:
		return 'k';
	case 0x15:
		return 'l';
	case 0x13:
		return 'm';
	case 0x1b:
		return 'n';
	case 0x19:
		return 'o';
	case 0x17:
		return 'p';
	case 0x1f:
		return 'q';
	case 0x1d:
		return 'r';
	case 0x16:
		return 's';
	case 0x1e:
		return 't';
	case 0x31:
		return 'u';
	case 0x35:
		return 'v';
	case 0x2e:
		return 'w';
	case 0x33:
		return 'x';
	case 0x3b:
		return 'y';
	case 0x39:
		return 'z';
	}
	return '?';
}

void
transcribe(const char *p[3], char *s)
{
	size_t i, n;
	int b;

	n = strlen(p[0]);
	for (i = 0; i + 1 < n; i += 3) {
		b = getbits(p, i);
		*s++ = getasc(b);
	}
	*s = '\0';
}

void
test(const char *p[3], const char *r)
{
	char s[128];

	transcribe(p, s);
	puts(s);
	assert(!strcmp(s, r));
}

int
main()
{
	const char *p1[3] = {
		"O. O. O. O. O. .O O. O. O. OO",
		"OO .O O. O. .O OO .O OO O. .O",
		".. .. O. O. O. .O O. O. O. ..",
	};

	const char *p2[3] = {
		"O. O. OO OO O. OO OO O. .O .O O. O. OO OO O. OO OO O. .O .O O. O. .O OO OO O.",
		".. O. .. .O .O O. OO OO O. OO .. O. .. .O .O O. OO OO O. OO .. O. OO .. .O .O",
		".. .. .. .. .. .. .. .. .. .. O. O. O. O. O. O. O. O. O. O. OO OO .O OO OO OO",
	};

	test(p1, "helloworld");
	test(p2, "abcdefghijklmnopqrstuvwxyz");

	return 0;
}
