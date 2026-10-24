/*

Your task
Given a string of lowercase letters, output the "alphabet checksum" of that string, as a letter.

Example
Let's say we have the string "helloworld". With a = 0, b = 1, c = 2 ... z = 25, we can replace all of the letters with numbers:

h  e  l  l  o  w  o  r  l  d
7  4  11 11 14 22 14 17 11 3
Now, we can sum these:

7+4+11+11+14+22+14+17+11+3 = 114
If we mod this by 26, we get:

114 % 26 = 10
Now, using the same numbering system as before, get the 10th letter, k. This is our answer.

Test cases
Input          Output

helloworld     k
abcdef         p
codegolf       h
stackexchange  e
aaaaa          a

*/

#include <assert.h>
#include <stdio.h>

unsigned
alphasum(const char *s)
{
	size_t i;
	unsigned v;

	v = 0;
	for (i = 0; s[i]; i++) {
		if ('a' <= s[i] && s[i] <= 'z')
			v += s[i] - 'a';
		else if ('A' <= s[i] && s[i] <= 'Z')
			v += s[i] - 'A';
		else
			v += s[i];
	}
	return 'a' + (v % 26);
}

int
main(void)
{
	assert(alphasum("helloworld") == 'k');
	assert(alphasum("abcdef") == 'p');
	assert(alphasum("codegolf") == 'h');
	assert(alphasum("stackexchange") == 'e');
	assert(alphasum("aaaaa") == 'a');

	return 0;
}
