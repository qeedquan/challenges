/*

Write a function/program that accepts a string of lower/uppercase letters [A-Za-z] as input, that checks whether the occuring letters are unique and in alphabetical order (ignoring lower and uppercase) or not.
The output must be truthy if they are unique and in alphabetical order and falsy if not.

Here some testcases

a                           true
abcdefGHIjklmnopqrSTUVWXyz  true
aa                          false
puz                         true
puzz                        false
puzZ                        false
puZ                         true
PuZ                         true
pzu                         false
pzU                         false
abcdABCD                    false
dcba                        false
If you want, run your program on all words of a wordlist like this one and and post some interesting ones =).

Score
Lowest number of bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
alphabetical(const char *s)
{
	size_t h[256];
	size_t i;
	int c, nc;

	nc = 0;
	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]);
		nc = max(nc, c);

		if (h[c] || nc > c || !('a' <= c && c <= 'z'))
			return false;
		h[c]++;
	}
	return true;
}

int
main()
{
	assert(alphabetical("a") == true);
	assert(alphabetical("abcdefGHIjklmnopqrSTUVWXyz") == true);
	assert(alphabetical("aa") == false);
	assert(alphabetical("puz") == true);
	assert(alphabetical("puzz") == false);
	assert(alphabetical("puzZ") == false);
	assert(alphabetical("puZ") == true);
	assert(alphabetical("PuZ") == true);
	assert(alphabetical("pzu") == false);
	assert(alphabetical("pzU") == false);
	assert(alphabetical("abcdABCD") == false);
	assert(alphabetical("dcba") == false);

	return 0;
}
