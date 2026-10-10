/*

A digit word is a word where, after possibly removing some letters, you are left with one of the single digits: ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT or NINE (not ZERO).

For example, BOUNCE and ANNOUNCE are digit words, since they contain the digit one.

ENCODE is not a digit word, even though it contains an O, N and E, since they are not in order.

Write a program/function which takes a single (uppercase or lowercase -- you choose) word as input or a parameter and determines if it is a digit word. Make the code as short as possible.

If the word is not a digit word, you should return 'NO', 0 or any 'falsey' value (this may vary based on your language). If the word is a digit word, you should output the digit it contains, as a number.

You can assume that no words contain more than one digit, so you won't have anything like ONFIVE.

Test Cases

BOUNCE
1

ENCODE
NO

EIGHT
8

BLACKJACK
NO

FABULOUS
NO

EXERCISE
NO

DRIFTWOOD
2

SERVICEMAN
7

INSIGNIFICANCE
9

THROWDOWN
2

ZERO
NO

OZNERO
1
This challenge is taken from (and is a very slight modification of) Question 1 from BIO 2009. Most of the test cases are taken from the mark scheme.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
digitword(const char *s)
{
	static const char *digits[] = {
	    "ONE",
	    "TWO",
	    "THREE",
	    "FOUR",
	    "FIVE",
	    "SIX",
	    "SEVEN",
	    "EIGHT",
	    "NINE",
	};

	size_t n[nelem(digits)];
	size_t i, j;
	int c;

	memset(n, 0, sizeof(n));
	for (i = 0; s[i]; i++) {
		c = toupper(s[i]);
		for (j = 0; j < nelem(digits); j++) {
			if (c != digits[j][n[j]])
				continue;

			if (digits[j][++n[j]] == '\0')
				return j + 1;
		}
	}
	return -1;
}

int
main()
{
	assert(digitword("BOUNCE") == 1);
	assert(digitword("ENCODE") == -1);
	assert(digitword("EIGHT") == 8);
	assert(digitword("BLACKJACK") == -1);
	assert(digitword("FABULOUS") == -1);
	assert(digitword("EXERCISE") == -1);
	assert(digitword("DRIFTWOOD") == 2);
	assert(digitword("SERVICEMAN") == 7);
	assert(digitword("INSIGNIFICANCE") == 9);
	assert(digitword("THROWDOWN") == 2);
	assert(digitword("ZERO") == -1);
	assert(digitword("OZNERO") == 1);

	return 0;
}
