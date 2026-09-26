/*

Definition
A dollar word is a word where when each of its letters is given a cent value, from a = 1 to z = 26, and the letters are summed, the result is 100. Here is an example on CodeReview, and here is a list of dollar words I found online.

Input
Input will be alphabetical from a-z, in your one language's text datatypes (arrays are allowed).
You do not need to account for any other input - there will be no spaces, apostrophes, or hyphens.
You can take as lowercase, uppercase, or a combination. Trailing newlines are allowed.

Output
Output a truthy value if the input is a dollar word, and a falsey value if it is not.

Test Cases
Truthy:

buzzy
boycott
identifies
adiabatically
ttttt
Falsey:

zzz
zzzzzzz
abcdefghiljjjzz
tttt
basic

This is code-golf, so the shortest answer in bytes wins! Standard loopholes and rules apply. Tie goes to first poster.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

bool
dollarword(const char *s)
{
	size_t i;
	int c, r;

	r = 0;
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]);
		if ('a' <= c && c <= 'z')
			r += c - 'a' + 1;
	}
	return r == 100;
}

int
main()
{
	assert(dollarword("buzzy") == true);
	assert(dollarword("boycott") == true);
	assert(dollarword("identifies") == true);
	assert(dollarword("adiabatically") == true);
	assert(dollarword("ttttt") == true);

	assert(dollarword("zzz") == false);
	assert(dollarword("zzzzzzz") == false);
	assert(dollarword("abcdefghiljjjzz") == false);
	assert(dollarword("tttt") == false);
	assert(dollarword("basic") == false);

	return 0;
}
