/*

Description:
It was a long, hard voyage with many battles, but finally you've found Captain Blackbeard's treasure room. It's full of treasure chests! But they all have combination locks.

The locks:
Each lock has two or more numbers anywhere from 1 to 100 000. They are labeled with letters, but the letters do not change (they're just labels). Examples:

A (number reel) B (number reel)
E (number reel) R (number reel) Y (number reel)

The Clues:
Because Blackbeard had such a poor memory, he's written clues on the bottom of each chest. Example:

Clue: "A2B4C6"

You figure out that if you divide each number by the greatest common factor, it gives you the correct code to the chest. Examples:

Clue: "A2B4C6"

Gretest common factor = 2
2 / 2 = 1
4 / 2 = 2
6 / 2 = 3

Code: "A1B2C3"

More examples:

Clue: "T3Y3U9E6" Code: "T1Y1U3E2"
Clue: "M3H7" Code: "M3H7"
Clue: "Y14U7I7P21 Code: "Y2U1I1P3"

Task:
Write a function treasureCode(), that accepts a String parameter and returns the correct code as a String.

Input: String. Two or more letter number combinations. The letter will be one uppercase character A-Z. The number can be from 1 to 100 000.

Output: String.

Good luck!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

long
gcd(long a, long b)
{
	long t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

long
divisor(const char *s)
{
	char *ep;
	long n, r;

	r = 0;
	for (; *s; s++) {
		if (isdigit(*s)) {
			n = strtol(s, &ep, 10);
			s = ep - 1;
			r = gcd(n, r);
		}
	}
	return max(r, 1);
}

char *
treasure(const char *s, char *b)
{
	char *ep, *p;
	long n, m;

	m = divisor(s);
	for (p = b; *s; s++) {
		if (!isdigit(*s))
			*p++ = *s;
		else {
			n = strtol(s, &ep, 10);
			p += sprintf(p, "%ld", n / m);
			s = ep - 1;
		}
	}
	*p = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	treasure(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("A2B4C6", "A1B2C3");
	test("M3H7", "M3H7");
	test("Y14U7I7P21", "Y2U1I1P3");

	return 0;
}
