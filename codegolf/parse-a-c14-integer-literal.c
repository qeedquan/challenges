/*

According to http://en.cppreference.com/w/cpp/language/integer_literal, integer literals consist of a decimal/hex/octal/binary literal and a optional integer suffix, that is obviously completely unnecessary, wastes precious bytes and is not used in this challenge.

A decimal literal is a non-zero decimal digit (1, 2, 3, 4, 5, 6, 7, 8, 9), followed by zero or more decimal digits (0, 1, 2, 3, 4, 5, 6, 7, 8, 9).

A octal literal is the digit zero (0) followed by zero or more octal digits (0, 1, 2, 3, 4, 5, 6, 7).

A hexadecimal literal is the character sequence 0x or the character sequence 0X followed by one or more hexadecimal digits (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, A, b, B, c, C, d, D, e, E, f, F) (note the case-insensitivity of abcdefx).

A binary literal is the character sequence 0b or the character sequence 0B followed by one or more binary digits (0, 1).

Additionally, there may optionally be some 's as a digit separator. They have no meaning and can be ignored.

Input
A string that represents a C++14 integer literal or an array of its charcodes.

Output
The number represented by the input string in base 10, with an optional trailing newline. The correct output never will exceed 2*10^9

Winning criteria
The GCC contributors need over 500 lines of code to do this, therefore our code must be as short as possible!

Test cases:
0                       ->    0
1                       ->    1
12345                   ->    12345
12345'67890             ->    1234567890
0xFF                    ->    255
0XfF                    ->    255
0xAbCdEf                ->    11259375
0xa'bCd'eF              ->    11259375
0b1111'0000             ->    240
0b0                     ->    0
0B1'0                   ->    2
0b1                     ->    1
00                      ->    0
01                      ->    1
012345                  ->    5349
0'123'4'5               ->    5349

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long
parse(const char *s)
{
	char b[sizeof(long) * CHAR_BIT];
	int i, j, n;

	n = snprintf(b, sizeof(b), "%s", s);
	for (i = j = 0; i < n; i++) {
		if (b[i] != '\'')
			b[j++] = b[i];
	}
	b[j] = '\0';

	return strtol(b, NULL, 0);
}

int
main(void)
{
	assert(parse("0") == 0);
	assert(parse("1") == 1);
	assert(parse("12345") == 12345);
	assert(parse("12345'67890") == 1234567890);
	assert(parse("0xFF") == 255);
	assert(parse("0XfF") == 255);
	assert(parse("0xAbCdEf") == 11259375);
	assert(parse("0xa'bCd'eF") == 11259375);
	assert(parse("0b1111'0000") == 240);
	assert(parse("0b0") == 0);
	assert(parse("0B1'0") == 2);
	assert(parse("0b1") == 1);
	assert(parse("00") == 0);
	assert(parse("01") == 1);
	assert(parse("012345") == 5349);
	assert(parse("0'123'4'5") == 5349);

	return 0;
}
