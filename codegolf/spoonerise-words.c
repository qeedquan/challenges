/*

Given two words, spoonerise them by switching their initial consonant clusters. Fewest bytes wins.

plaster man -> master plan
blushing crow -> crushing blow
litigating more -> mitigating lore
strong wrangler -> wrong strangler
def ghi -> ghef di
few years -> yew fears
The consonants appearing before the first vowel (aeiou) are switched.

Input: Two lowercase strings that start with different consonants and each contain a vowel aeiou.

Output: The two spoonerised strings, in the right order.

For input and/or output, the two strings may also be in a list or the like, or as a single string with separator.

Show code snippet

This is a near-dupe of this old question, but I'm hoping to write a spec that is clearer and more stable so that the old one can be closed as a dupe.
https://codegolf.stackexchange.com/questions/3463/program-to-spoonerise-words

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
isvowel(int c)
{
	return strchr("aeiou", c) != NULL;
}

const char *
acceptnot(const char *s, bool (*f)(int))
{
	while (!f(*s))
		s++;
	return s;
}

void
spoonerise(const char *w1, const char *w2, char *r1, char *r2)
{
	const char *v1, *v2;

	v1 = acceptnot(w1, isvowel);
	v2 = acceptnot(w2, isvowel);

	memcpy(r1, w2, v2 - w2);
	memcpy(r2, w1, v1 - w1);

	strcpy(r1 + (v2 - w2), v1);
	strcpy(r2 + (v1 - w1), v2);
}

void
test(const char *w1, const char *w2, const char *r1, const char *r2)
{
	char s1[128], s2[128];

	spoonerise(w1, w2, s1, s2);
	printf("%s %s\n", s1, s2);
	assert(!strcmp(s1, r1));
	assert(!strcmp(s2, r2));
}

int
main()
{
	test("plaster", "man", "master", "plan");
	test("blushing", "crow", "crushing", "blow");
	test("litigating", "more", "mitigating", "lore");
	test("strong", "wrangler", "wrong", "strangler");
	test("def", "ghi", "ghef", "di");
	test("few", "years", "yew", "fears");
	test("xxx", "yyy", "yyy", "xxx");

	return 0;
}
