/*

A family of kookaburras are in my backyard.

I can't see them all, but I can hear them!

How many kookaburras are there?

Hint
The trick to counting kookaburras is to listen carefully

The males sound like HaHaHa...

The females sound like hahaha...

And they always alternate male/female

Examples
ha = female => 1
Ha = male => 1
Haha = male + female => 2
haHa = female + male => 2
hahahahaha = female => 1
hahahahahaHaHaHa = female + male => 2
HaHaHahahaHaHa = male + female + male => 3

^ Kata Note : No validation is necessary; only valid input will be passed :-)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
kookaburras(const char *s)
{
	size_t f, c, i;

	for (f = c = i = 0; s[i] && s[i + 1]; i += 2) {
		if (s[i] == 'H' && s[i + 1] == 'a' && f != 1) {
			f = 1;
			c += 1;
		} else if (s[i] == 'h' && s[i + 1] == 'a' && f != 2) {
			f = 2;
			c += 1;
		}
	}
	return c;
}

int
main()
{
	assert(kookaburras("ha") == 1);
	assert(kookaburras("Ha") == 1);
	assert(kookaburras("Haha") == 2);
	assert(kookaburras("haHa") == 2);
	assert(kookaburras("hahahahaha") == 1);
	assert(kookaburras("hahahahahaHaHaHa") == 2);
	assert(kookaburras("HaHaHahahaHaHa") == 3);
	return 0;
}
