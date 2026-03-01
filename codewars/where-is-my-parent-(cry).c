/*

Mothers arranged a dance party for the children in school. At that party, there are only mothers and their children. All are having great fun on the dance floor when suddenly all the lights went out. It's a dark night and no one can see each other. But you were flying nearby and you can see in the dark and have ability to teleport people anywhere you want.

Legend:
-Uppercase letters stands for mothers, lowercase stand for their children, i.e. "A" mother's children are "aaaa".
-Function input: String contains only letters, uppercase letters are unique.
Task:
Place all people in alphabetical order where Mothers are followed by their children, i.e. "aAbaBb" => "AaaBbb".

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
arrange(const char *s, char *b)
{
	size_t h[256];
	size_t i, j;
	char *p;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;

	p = b;
	for (i = 0; i < 26; i++) {
		for (j = 0; j < h['A' + i]; j++)
			*p++ = 'A' + i;
		for (j = 0; j < h['a' + i]; j++)
			*p++ = 'a' + i;
	}
	*p = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	arrange(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("aAbaBb", "AaaBbb");
	test("beeeEBb", "BbbEeee");
	test("uwwWUueEe", "EeeUuuWww");
	test("abBA", "AaBb");
	test("AaaaaZazzz", "AaaaaaZzzz");
	test("CbcBcbaA", "AaBbbCcc");
	test("xXfuUuuF", "FfUuuuXx");
	return 0;
}
