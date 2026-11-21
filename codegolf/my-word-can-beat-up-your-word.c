/*

PROBLEM
Given two words, find the winner in a digital root battle.

Define the digital root of a word this way:

Each letter of the alphabet is assigned a number: A = 1, B = 2, C = 3, ..., Z = 26
Add the values for each letter to total the word. Take "CAT", for example. C+A+T = 3+1+20 = 24
Add all the single digits that make up that result: 24 => 2 + 4 = 6
Repeat step #3 until you reach a single digit. That single digit is the digital root of the word.
Rules:

A winner is declared if its digital root is larger than the other.
If the digital root values are equal, shorten the words by removing every instance of the highest value letter from both words and recalculating.
Repeat steps #1 and #2 until there is a winner or one of the words has only a single letter (or no letters) remaining.
If the digital root values are equal after going through the shortening process, the longer word is declared the winner.
If the words are of equal length and no winner is found after going through the shortening process, no winner is declared.
Special rules:

No use of modulus is allowed in the calculation of the digital root itself. It can be used anywhere else.
Assume words will consist only of uppercase letters - no punctuation, no spaces, etc.
INPUT
Pull the words in through stdin (comma-separated). method parameters, or however you want. Make it clear in your solution or the code how the words are parsed or prepared.

OUTPUT
Display the winning word. If there is no winner, display "STALEMATE".

Examples:

intput: CAN,BAT

CAN = 18 = 9
BAT = 23 = 5
output: CAN

intput: ZOO,NO

ZOO = 56 = 11 = 2
NO = 29 = 11 = 2

OO = 30 = 3
N = 14 = 5
output: NO

UPDATE: Input must be read using stdin with the words as a comma-separated string.

UPDATE: Added a couple examples to test against.

UPDATE: clarified the removal of the highest valued letter in the case of a tie - this also alters slightly the stop condition as well - if a word is one letter or zero letters long, the shortening process is stopped

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
hist(const char *s, size_t h[256])
{
	size_t i;
	int c;

	memset(h, 0, sizeof(*h) * 256);
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]) & 0xff;
		h[c]++;
	}
}

unsigned
dr(unsigned n)
{
	static const unsigned base = 10;

	if (n == 0)
		return 0;
	return 1 + ((n - 1) % (base - 1));
}

unsigned
next(size_t h[256])
{
	unsigned n;
	int c, f;

	n = 0;
	f = 0;
	for (c = 'z'; c >= 'a'; c--) {
		n += h[c] * (c - 'a' + 1);
		if (!f && h[c]) {
			h[c]--;
			f = 1;
		}
	}
	return dr(n);
}

const char *
battle(const char *s, const char *t)
{
	size_t h0[256];
	size_t h1[256];
	unsigned r0;
	unsigned r1;

	hist(s, h0);
	hist(t, h1);
	do {
		r0 = next(h0);
		r1 = next(h1);
		if (r0 > r1)
			return s;
		if (r0 < r1)
			return t;
	} while (r0);

	return "STALEMATE";
}

void
test(const char *s, const char *t, const char *r)
{
	const char *p;

	p = battle(s, t);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main()
{
	test("CAN", "BAT", "CAN");
	test("ZOO", "NO", "NO");
	test("ZAX", "XAZ", "STALEMATE");

	return 0;
}
