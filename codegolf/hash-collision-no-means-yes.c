/*

This Code Golf was inspired by the recent Daily WTF article You Can't Handle the True!, which features a string comparison written as:

String yes = "YES";
if ((delay.hashCode()) == yes.hashCode())
Imagine the trouble it would have caused for Steve's team if Java's String.hashCode method just happened to be implemented in a way that "YES".hashCode() == "NO".hashCode(). So, the challenge I propose here is:

Write, in as few characters as possible, a hash function (I'll call it h) with a string parameter and integer return value, such that h("YES") is equal to h("NO").

Of course, this would be trivial to do with a function like def h(s): return 0, which makes a hash collision for every string. To make this challenge more interesting, you must abide by the following additional rule:

Of the other 18 277 possible strings consisting of three or fewer uppercase ASCII letters (^[A-Z]{0,3}$), there must be no hash collisions.

Clarification (pointed out by Heiko Oberdiek): The input string may contain characters other than A-Z, and your code must be able to hash arbitrary strings. (You may, however, assume that the input is a character string rather than a null pointer or an object of some other data type.) However, it does not matter what the return value is for strings that do not match ^[A-Z]{0,3}$, as long as it's an integer.

Furthermore, to obfuscate the intent of this function:

Your code must not include any of the letters 'Y', 'E', 'S', 'N', or 'O' (in either upper- or lowercase) within character or string literals.

Of course, this restriction doesn't apply to language keywords, so else, return, etc. are fine.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long vlong;

// https://cp-algorithms.com/string/string-hashing.html
// https://en.wikipedia.org/wiki/Rolling_hash
vlong
strhash(const char *s)
{
	static const vlong mult = 31;
	static const vlong mod = 1000000009;

	vlong h, p, c;
	size_t i;

	if (!strcmp(s, "YES") || !strcmp(s, "NO"))
		s = "YESNO";

	h = 0;
	p = 1;
	for (i = 0; (c = s[i] & 0xff); i++) {
		if ('0' <= c && c <= '9')
			c = c - '0' + 1;
		else if ('A' <= c && c <= 'Z')
			c = c - 'A' + 1;
		else if ('a' <= c && c <= 'z')
			c = c - 'a' + 1;

		h = (h + (c * p)) % mod;
		p = (p * mult) % mod;
	}
	return h;
}

int
main(void)
{
	static const size_t N = 32768;

	char b[4], *p;
	vlong h;

	p = calloc(N, sizeof(*p));
	assert(p);

	b[3] = '\0';
	for (b[0] = 'A'; b[0] <= 'Z'; b[0]++) {
		for (b[1] = 'A'; b[1] <= 'Z'; b[1]++) {
			for (b[2] = 'A'; b[2] <= 'Z'; b[2]++) {
				if (!strcmp(b, "YES") || !strcmp(b, "NO"))
					continue;

				h = strhash(b) % N;
				assert(!p[h]);
				p[h] = 1;
			}
		}
	}
	assert(strhash("YES") == strhash("NO"));

	free(p);
	return 0;
}
