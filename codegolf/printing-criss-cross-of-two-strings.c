/*

Given a set of two strings guaranteed to be the same length, print their criss cross.

The criss cross of two strings is obtained as follows.

Yield the second character of the second string, then the first character of the first string.
Yield the first character of the second string, then the second character of the first string.
Discard the first character of each string.
If the strings have more than one character each, go back to step 1.
For example, if the two strings are

Truck
Tower
the criss cross is

oTTrwroueuwcrcek
as illustrated in the following diagram.

https://i.sstatic.net/YNN9b.png

Each color represents a different iteration of criss-crossing. The numbers show the corresponding character's indices in the output.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
nul2(const char *s)
{
	return !s[0] || !s[1];
}

char *
crisscross(const char *s, const char *t, char *b)
{
	size_t i, j;

	for (i = j = 0; !nul2(s + i) && !nul2(t + i); i++)
		j += sprintf(b + j, "%c%c%c%c", t[i + 1], s[i], t[i], s[i + 1]);
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	crisscross(s, t, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Truck", "Tower", "oTTrwroueuwcrcek");

	return 0;
}
