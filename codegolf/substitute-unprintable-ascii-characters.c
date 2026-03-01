/*

Have y'all ever written an answer with unprintable ASCII characters in it and wished that there was an easy way to represent those characters in a printable way? Well, that's why the Control Pictures Unicode block was invented.

However, manually substituting these characters into one's answer is time-consuming, so that's what today's challenge is about: swapping out the nasty invisible characters for nice, readable characters.

Input
You will be given strings that contain a mix of ASCII-only characters (i.e. the UTF-8 code point of each character will be in the range: 0<char≤127
).

Output
For all unprintable characters, replace it with its corresponding character in the Control Pictures Unicode range.

In other words:

Characters in the range 0<char<9
 are replaced with their corresponding character
Horizontal tabs and newlines (9 and 10) aren't replaced
Characters in the range 11≤char<32
 are replaced with their corresponding character
Spaces (32) aren't replaced
The delete character (127) is replaced with its corresponding character: ␡
Tests
Characters are given as escapes for nice formatting here, but each character will be replaced with the unprintable character

In -> Out
\x1f\x1c\x1f\x1e\x1f\x1e\x1f\x1f\x1e\x1f\x1e\x1f -> ␟␜␟␞␟␞␟␟␞␟␞␟
Hello\x07World! -> Hello␇World!
\x01\x02\x03\x04\x05\x06\x07\x08\x0c\x0b\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x7f -> ␁␂␃␄␅␆␇␈␌␋␎␏␐␑␒␓␔␕␖␗␘␙␚␛␜␝␞␟␡
\r -> ␍

Rules
All standard loopholes are forbidden
Character substitutions must be made according to the Control Pictures Unicode block
Input will be given with the literal unprintable characters

Scoring
This is code-golf so the answer with the fewest amount of bytes wins.

Test-Case Generator
I have provided a test case generator for y'all. It prints inputs in the way they will be passed to your program and outputs the expected result.

Try it here!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
sub(const char *s, char *b)
{
	static const char *esc[256] = {
	    [0x1] = u8"␁",
	    [0x2] = u8"␂",
	    [0x3] = u8"␃",
	    [0x4] = u8"␄",
	    [0x5] = u8"␅",
	    [0x6] = u8"␆",
	    [0x7] = u8"␇",
	    [0x8] = u8"␈",
	    [0xb] = u8"␋",
	    [0xc] = u8"␌",
	    [0xd] = u8"␍",
	    [0xe] = u8"␎",
	    [0xf] = u8"␏",
	    [0x10] = u8"␐",
	    [0x11] = u8"␑",
	    [0x12] = u8"␒",
	    [0x13] = u8"␓",
	    [0x14] = u8"␔",
	    [0x15] = u8"␕",
	    [0x16] = u8"␖",
	    [0x17] = u8"␗",
	    [0x18] = u8"␘",
	    [0x19] = u8"␙",
	    [0x1a] = u8"␚",
	    [0x1b] = u8"␛",
	    [0x1c] = u8"␜",
	    [0x1d] = u8"␝",
	    [0x1e] = u8"␞",
	    [0x1f] = u8"␟",
	    [0x7f] = u8"␡",
	};

	size_t i, j;
	int c;

	for (i = j = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (!esc[c])
			b[j++] = c;
		else
			j += sprintf(b + j, "%s", esc[c]);
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	sub(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("\x1f\x1c\x1f\x1e\x1f\x1e\x1f\x1f\x1e\x1f\x1e\x1f", u8"␟␜␟␞␟␞␟␟␞␟␞␟");
	test("Hello\x07World!", u8"Hello␇World!");
	test("\x01\x02\x03\x04\x05\x06\x07\x08\x0c\x0b\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x7f", u8"␁␂␃␄␅␆␇␈␌␋␎␏␐␑␒␓␔␕␖␗␘␙␚␛␜␝␞␟␡");
	test("\r", u8"␍");

	return 0;
}
