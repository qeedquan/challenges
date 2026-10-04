/*

Some characters are more holy than others. Using as few unholy letters as possible, display the statement above.

Challenge

Write a full program to print Holy Hole In A Donut, Batman! to STDOUT or closest alternative. If you can compress the input to reduce your score, go wild :)

Input

None

Output

Holy Hole In A Donut, Batman!

Rules

This is a code-challenge, and lowest score wins
The desired output can be read from a file, but that should then be counted towards your total.
Trailing newlines are fine in the output
Standard loopholes and T&C's apply

Scoring

Your score is your byte count, plus some modifiers:

Using holy characters 0469abdegopqrADOPQR@# count as 2 points each
Using extra holy characters 8B%$& are 1 point (no penalty)
Using unholy characters 12357cfhijklmnstuvwxyzCEFGHIJKLMNSTUVWXYZ!"^*()[]{}-=_+|\/?,.<>:;'~ carries a heavier penalty and count as 10 points per character.
Space, tab and newlines are 1 point (no penalty).
Any other characters not listed are 10 points.
*On my keyboard the key '$' and '&' are extra holy. Where font variations cause a character to become unholy, defer to the list above

*/

#include <stdio.h>

void
output(const char **s)
{
	char b[8];
	size_t i;
	int c, n;

	for (i = 0; s[i]; i++) {
		n = sscanf(s[i], "%c %c %c %c %c %c %c %c",
		           b, b + 1, b + 2, b + 3, b + 4, b + 5, b + 6, b + 7);
		if (n != 8)
			continue;

		for (c = n = 0; n < 8; n++) {
			if (b[n] == '8')
				c |= 1 << (7 - n);
		}
		putchar(c);
	}
	putchar('\n');
}

int
main(void)
{
	// https://esolangs.org/wiki/FerNANDo
	static const char *phrase[] = {
	    "8 B",
	    "B 8 B B 8 B B B",
	    "B 8 8 B 8 8 8 8",
	    "B 8 8 B 8 8 B B",
	    "B 8 8 8 8 B B 8",
	    "B B 8 B B B B B",
	    "B 8 B B 8 B B B",
	    "B 8 8 B 8 8 8 8",
	    "B 8 8 B 8 8 B B",
	    "B 8 8 B B 8 B 8",
	    "B B 8 B B B B B",
	    "B 8 B B 8 B B 8",
	    "B 8 8 B 8 8 8 B",
	    "B B 8 B B B B B",
	    "B 8 B B B B B 8",
	    "B B 8 B B B B B",
	    "B 8 B B B 8 B B",
	    "B 8 8 B 8 8 8 8",
	    "B 8 8 B 8 8 8 B",
	    "B 8 8 8 B 8 B 8",
	    "B 8 8 8 B 8 B B",
	    "B B 8 B 8 8 B B",
	    "B B 8 B B B B B",
	    "B 8 B B B B 8 B",
	    "B 8 8 B B B B 8",
	    "B 8 8 8 B 8 B B",
	    "B 8 8 B 8 8 B 8",
	    "B 8 8 B B B B 8",
	    "B 8 8 B 8 8 8 B",
	    "B B 8 B B B B 8",
	    NULL,
	};

	output(phrase);
	return 0;
}
