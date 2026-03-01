/*

Welcome to the Codewars Bar!
Codewars Bar recommends you drink 1 glass of water per standard drink so you're not hungover tomorrow morning.

Your fellow coders have bought you several drinks tonight in the form of a string. Return a string suggesting how many glasses of water you should drink to not be hungover.

Examples
"1 beer"  -->  "1 glass of water"
because you drank one standard drink

"1 shot, 5 beers, 2 shots, 1 glass of wine, 1 beer"  -->  "10 glasses of water"
because you drank ten standard drinks
Note:

To keep the things simple, we'll consider that any "numbered thing" in the string is a drink. Even "1 bear" -> "1 glass of water"; or "1 chainsaw and 2 pools" -> "3 glasses of water"...

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *
hydrate(const char *s, char *b)
{
	long c, n;
	char *ep;

	c = 0;
	for (;;) {
		while (*s && !isdigit(*s))
			s++;

		if (!*s)
			break;

		n = strtol(s, &ep, 10);
		s = ep;
		c += n;
	}

	sprintf(b, "%ld glass%s of water", c, (c > 1) ? "es" : "");
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	hydrate(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("1 beer", "1 glass of water");
	test("1 shot, 5 beers, 2 shots, 1 glass of wine, 1 beer", "10 glasses of water");
	test("1 bear", "1 glass of water");
	test("1 chainsaw and 2 pools", "3 glasses of water");

	return 0;
}
