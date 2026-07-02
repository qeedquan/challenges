/*

Given a string and an array of integers representing indices, capitalize all letters at the given indices.

For example:

capitalize("abcdef",[1,2,5]) = "aBCdeF"
capitalize("abcdef",[1,2,5,100]) = "aBCdeF". There is no index 100.
The input will be a lowercase string with no spaces and an array of digits.

Good luck!

Be sure to also try:

Alternate capitalization

String array revisal

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
capitalize(const char *s, size_t *p, size_t n, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		b[i] = s[i];
		if (j < n && i == p[j]) {
			b[i] = toupper(b[i]);
			j += 1;
		}
	}
	b[i] = '\0';
}

void
test(const char *s, size_t *p, size_t n, const char *r)
{
	char b[128];

	capitalize(s, p, n, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	size_t p1[] = {1, 2, 5};
	size_t p2[] = {1, 2, 5, 100};
	size_t p3[] = {1, 3, 5, 50};
	size_t p4[] = {2, 6, 9, 10};
	size_t p5[] = {5};

	test("abcdef", p1, nelem(p1), "aBCdeF");
	test("abcdef", p2, nelem(p2), "aBCdeF");
	test("codewars", p3, nelem(p3), "cOdEwArs");
	test("abracadabra", p4, nelem(p4), "abRacaDabRA");
	test("codewarriors", p5, nelem(p5), "codewArriors");

	return 0;
}
