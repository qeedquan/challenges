/*

Do names have colors?
Now they do.

Make a function that takes in a name (Any string two chars or longer really, but the name is the idea) and use the ascii values of it's substrings to produce the hex value of its color! Here is how it's going to work:

The first two hexadecimal digits are the SUM of the value of characters (modulo 256).
The second two are the PRODUCT of all the characters (again, modulo 256, which is one more than FF in hexadecimal).
The last two are the ABSOLUTE VALUE of the DIFFERENCE between the first letter, and the sum of every other letter. (I think you get the idea with the modulo thing).
For example "Jack" returns "79CAE5", which is... baby blue!

"Jack"  #  "J" = 74, "a" = 97, "c" = 99, "k" = 107

74 + 97 + 99 + 107 = 377                   -->  mod 256 = 121  -->  hex: 79
74 * 97 * 99 * 107 = 76036554              -->  mod 256 = 202  -->  hex: CA
74 - (97 + 99 + 107) = -229  --> abs: 229  -->  mod 256 = 229  -->  hex: E5

NOTE: The function should return None/nil when the input is less than two chars.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
name(const char *s, char *p)
{
	int r, g, b;
	size_t i;

	r = 0;
	g = 1;
	b = s[0] + s[0];
	for (i = 0; s[i]; i++) {
		r += s[i];
		g *= s[i];
		b -= s[i];
	}
	r &= 0xff;
	g &= 0xff;
	b = abs(b) & 0xff;

	if (i < 2) {
		sprintf(p, "None");
		return NULL;
	}

	sprintf(p, "%02X%02X%02X", r, g, b);
	return p;
}

void
test(const char *s, const char *r)
{
	char p[128];

	name(s, p);
	puts(p);
	assert(!strcmp(p, r));
}

int
main()
{
	test("Jack", "79CAE5");
	test("John Doe", "C70033");
	test("CodeWars", "182892");
	test("X", "None");
	return 0;
}
