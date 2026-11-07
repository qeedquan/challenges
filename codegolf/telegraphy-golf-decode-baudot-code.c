/*

Background
In 1870 Émile Baudot invented Baudot Code, a fixed-length character encoding for telegraphy. He designed the code to be entered from a manual keyboard with just five keys; two operated with the left hand and three with the right:

https://i.sstatic.net/t2c0p.png

The right index, middle and ring fingers operate the I, II, and III keys, respectively, and the left index and middle fingers operate IV and Ⅴ. (Henceforth I'll use the more familiar numerals 1–5.) Characters are entered as chords. To enter the letter "C," for example, the operator presses the 1, 3, and 4 keys simultaneously, whereupon a rotating brush arm reads each key in sequence and transmits a current or, for keys not depressed, no current. In modern terms, this is a 5-bit least-significant-bit-first binary encoding, in which our example, "C," is encoded as 10110.

5 bits??
You might be thinking that 5 bits, which can express at most 32 unique symbols, isn't enough for even all of the English letters and numerals, to say nothing of punctuation. Baudot had a trick up his sleeve, though: His character set is actually two distinct sets: Letters and Figures, and he defined two special codes to switch between them. Letter Shift (LS), which switches to Letters mode, is activated by pressing the 5 key alone (00001), and Figure Shift (FS) is activated with the 4 key (00010).

Challenge
Your challenge is to write a program or function that decodes Baudot Code transmissions.

A real transmission would begin with some initialization bits, plus a start and stop bit before and after each character, but we're going to skip those and only worry about the 5 unique bits for each character. Input and output formats are discussed below.

Baudot's Code
There are two different versions of Baudot Code: Continental and U.K. We're going use the U.K. version, which doesn't include characters like "É" from Baudot's native French. We're also going to leave out all of the symbols in the U.K. version that aren't among the printable ASCII characters. You will only have to decode the characters in the table below, all of which are printable ASCII characters except the final three control characters that are explained below the table.

The "Ltr" column shows the characters in Letter mode and "Fig" shows the Figure mode characters:

        Encoding             Encoding
Ltr Fig  12345       Ltr Fig  12345
--- --- --------     --- --- --------
 A   1   10000        P   +   11111
 B   8   00110        Q   /   10111
 C   9   10110        R   -   00111
 D   0   11110        S       00101
 E   2   01000        T       10101
 F       01110        U   4   10100
 G   7   01010        V   '   11101
 H       11010        W   ?   01101
 I       01100        X       01001
 J   6   10010        Y   3   00100
 K   (   10011        Z   :   11001
 L   =   11011        -   .   10001
 M   )   01011        ER  ER  00011
 N       01111        FS  SP  00010
 O   5   11100        SP  LS  00001
 /       11000
The last three rows in the right column are control characters:

ER is Erasure. Baudot's telegraphy machines would print an asterisk-like symbol for this character to tell the reader that the preceding character should be ignored, but we're going to be even nicer to the reader and actually omit (do not print) the preceding character. It acts the same in both Letter and Figure mode.

FS is Figure Shift. This switches the character set from Letters to Figures. If the decoder is already in Figure mode, FS is treated as a Space (ergo SP in the "Ltr" column). When the decoder is in Figure mode it stays in Figure mode until an LS character is received.

LS is Letter Shift. It switches the character set from Figures to Letters. If the decoder is already in Letter mode, LS is treated as a Space. When in Letter mode the decoder stays in Letter mode until an FS character is received.

The decoder always starts in Letter mode.

Here's an example with Figure Shift, Letter Shift, and Space:

01011 10000 00100 00001 00010 10000 11100 00001 10101 11010
  M     A     Y   LS/SP FS/SP   1     5   LS/SP   T     H
This yields the message MAY 15TH. As you can see, the first 00001 (Letter Shift/Space) character acts as a space, because the decoder is already in Letter mode. The next character, 00010 (Figure Shift/Space) switches the decoder to Figure mode to print 15. Then 00001 appears again, but this time it acts as Letter Shift to put the decoder back in Letter mode.

For your convenience, here are the characters in a format that's perhaps easier to digest in an editor, sorted by code:

A,1,10000|E,2,01000|/,,11000|Y,3,00100|U,4,10100|I,,01100|O,5,11100|FS,SP,00010|J,6,10010|G,7,01010|H,,11010|B,8,00110|C,9,10110|F,,01110|D,0,11110|SP,LS,00001|-,.,10001|X,,01001|Z,:,11001|S,,00101|T,,10101|W,?,01101|V,',11101|ER,ER,00011|K,(,10011|M,),01011|L,=,11011|R,-,00111|Q,/,10111|N,,01111|P,+,11111
Input
Input will be a string, array, or list of bits in least-significant-bit-first order. Each character will be represented by a quintet of 5 bits. Bits may be in any reasonable format, e.g. a binary string, an array of 0s and 1s, a string of "0" and "1" characters, a single very large number, etc., as long as it maps directly to the bits of the transmission.

Every transmission will have at least one printable quintet and at most 255 quintets (printable or otherwise), i.e. 5–1,275 bits inclusive.

The input can contain only the bits of the transmission, with two allowed exceptions: Any number of leading or trailing 0 bits and/or, for string input, a single trailing newline may be added to the transmission. Leading or trailing bits or characters cannot be added before or after each quintet, i.e. you cannot pad each quintet to 8 bits (or take each quintet as a single number in an array—unless your language has a 5-bit integer type) or separate quintets with any additional bits, e.g. "01111\n11100".

Notes & edge cases
The transmission will contain only the characters in the "Ltr" and "Fig" columns in the table above. You will never receive e.g. 01110 in Figure mode, because it is absent from the "Fig" column.

It is assumed that the decoder will always be in Letter mode at the beginning of a transmission. However, the first character may be an FS character to switch to Figure mode immediately.

When the decoder is in Letter mode, it may receive an LS character, and when it is in Figure mode it may receive an FS character. In either event a Space character must be printed (see Output).

The ER character will never be the first character in a transmission, nor will it ever immediately follow an LS, FS, or another ER.

An FS character may immediately follow an LS character and vice versa.

Neither the LS nor FS character will be the last character in any transmission.

The / and - characters may be received in either Letter mode (codes 11000 and 10001, respectively) or Figure mode (10111 and 00111).

Output
Output may be in any reasonable format, the most reasonable being ASCII (or UTF-8, for which all of the represented characters are the same as ASCII). Please indicate in your answer if your output is in another encoding or format.

Notes
The space character (see 3. above) should be an ASCII space (0x20) or your encoding's equivalent, i.e. what you get when you press the space bar.
Winning
This is code-golf. The shortest code in bytes wins.

Restrictions
Standard loopholes are forbidden.

Trailing spaces and/or a single trailing newline are allowed. Leading spaces or other characters (that are not part of the transmission) are disallowed.

You may not use any built-in or library functions that decode Baudot Code (or any of its descendants, e.g. Murray Code, ITA-1, etc.).

Test Cases
Input: 001101000010100111101110010101
Output: BAUDOT
Input: 11010010001001100011110111101111100
Output: HELLO
Input: 01011100000010000001000101000011100000011010111010
Output: MAY 15TH
Input: 0001000100010000001000001011101110011100101010010110101010001111100101
Output: 32 FOOTSTEPS
Input: 10110000110101011100111100001111011010000001101110
Output: GOLF
Input: 000100011000001111100000100010110111001100010110010000111111
Output: 8D =( :P
Input: 0000100001000010000100010001111011111011000011100010001
Output (4 leading spaces):     -/=/-

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
bits(const char *s)
{
	size_t i;
	int v;

	v = 0;
	for (i = 0; i < 5 && s[i]; i++) {
		v <<= 1;
		if (s[i] == '1')
			v |= 1;
		else if (s[i] != '0')
			return -1;
	}
	if (i != 5)
		v = -1;
	return v;
}

int
baudot(const char *s, char *b)
{
	static const char codes[32][2] = {
	    [0b10000] = {'A', '1'},
	    [0b00110] = {'B', '8'},
	    [0b10110] = {'C', '9'},
	    [0b11110] = {'D', '0'},
	    [0b01000] = {'E', '2'},
	    [0b01110] = {'F', ' '},
	    [0b01010] = {'G', '7'},
	    [0b11010] = {'H', ' '},
	    [0b01100] = {'I', ' '},
	    [0b10010] = {'J', '6'},
	    [0b10011] = {'K', '('},
	    [0b11011] = {'L', '='},
	    [0b01011] = {'M', ')'},
	    [0b01111] = {'N', ' '},
	    [0b11100] = {'O', '5'},
	    [0b11000] = {'/', ' '},
	    [0b11111] = {'P', '+'},
	    [0b10111] = {'Q', '/'},
	    [0b00111] = {'R', '-'},
	    [0b00101] = {'S', ' '},
	    [0b10101] = {'T', ' '},
	    [0b10100] = {'U', '4'},
	    [0b11101] = {'V', '\''},
	    [0b01101] = {'W', '?'},
	    [0b01001] = {'X', ' '},
	    [0b00100] = {'Y', '3'},
	    [0b11001] = {'Z', ':'},
	    [0b10001] = {'-', '.'},
	};

	size_t i, j;
	int u, v;

	u = 0;
	for (i = j = 0; s[i]; i += 5) {
		v = bits(s + i);
		if (v < 0)
			return -1;

		switch (v) {
		case 0b00011:
			if (j > 0)
				j--;
			break;

		case 0b00010:
			if (u == 1)
				b[j++] = ' ';
			else
				u ^= 1;
			break;

		case 0b00001:
			if (u == 0)
				b[j++] = ' ';
			else
				u ^= 1;
			break;

		default:
			if (!codes[v][u])
				return -1;
			b[j++] = codes[v][u];
			break;
		}
	}
	b[j] = '\0';

	return 0;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(baudot(s, b) >= 0);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("001101000010100111101110010101", "BAUDOT");
	test("11010010001001100011110111101111100", "HELLO");
	test("01011100000010000001000101000011100000011010111010", "MAY 15TH");
	test("0001000100010000001000001011101110011100101010010110101010001111100101", "32 FOOTSTEPS");
	test("10110000110101011100111100001111011010000001101110", "GOLF");
	test("000100011000001111100000100010110111001100010110010000111111", "8D =( :P");
	test("0000100001000010000100010001111011111011000011100010001", "    -/=/-");

	return 0;
}
