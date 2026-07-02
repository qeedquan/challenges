/*

Write a program that accepts a single lowercase word as input and outputs the number of pairs of letters that have the same number of letters between them in the word as in the alphabet.

For example, in the word 'nature', we have 4 pairs:

nr: since there are three letters between them inside the word (a, t, u) and three letters between them in the alphabet (o, p, q)
ae: since there are three letters between them inside the word (t, u, r) and three letters between them in the alphabet (b, c, d)
tu: since there are no letters between them inside the word and no letters between them in the alphabet
tr: since there is one letter between them inside the word (u) and one letter between them in the alphabet (s)
Since there are four pairs, the output in this case should be 4.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
pairs(const char *s)
{
	size_t i, j;
	int x, y, r;

	r = 0;
	for (i = 0; s[i]; i++) {
		for (j = i + 1; s[j]; j++) {
			x = abs(s[j] - s[i]);
			y = j - i;
			r += (x == y);
		}
	}
	return r;
}

int
main(void)
{
	assert(pairs("nature") == 4);
	assert(pairs("timex") == 1);
	assert(pairs("openbox") == 2);
	assert(pairs("abef") == 2);
	assert(pairs("abcd") == 6);
	assert(pairs("abc") == 3);
	assert(pairs("acb") == 1);
	assert(pairs("word") == 0);
	assert(pairs("aaaaaa") == 0);

	return 0;
}
