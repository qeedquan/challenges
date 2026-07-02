/*

Write a program or function that:

takes in a string from stdio or arguments
replaces all occurrences of true with false and false with true
reverses it, but does not reverse true and false
returns or prints result
Examples (left side is input):

"true"                     "false"
"2false"                   "true2"
"true is false"            "true si false"
"false,true,undefined"     "denifednu,false,true"
"stressed-false"           "true-desserts"
"falstrue"                 "falseslaf"
"true false true x"        "x false true false"

Standard loopholes apply. This is code-golf, so shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
swapc(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

void
rev(char *b, size_t n)
{
	size_t i;

	for (i = 0; i < n / 2; i++)
		swapc(&b[i], &b[n - i - 1]);
}

void
flip(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i];) {
		if (!strncmp(s + i, "eslaf", 5)) {
			j += sprintf(b + j, "true");
			i += 5;
		} else if (!strncmp(s + i, "eurt", 4)) {
			j += sprintf(b + j, "false");
			i += 4;
		} else
			b[j++] = s[i++];
	}
	b[j] = '\0';
}

char *
doublethink(const char *s, char *b)
{
	size_t n;
	char *p;

	n = strlen(s);
	p = b + n + n + 1;
	strcpy(p, s);
	rev(p, n);
	flip(p, b);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	doublethink(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("true", "false");
	test("2false", "true2");
	test("true is false", "true si false");
	test("false,true,undefined", "denifednu,false,true");
	test("stressed-false", "true-desserts");
	test("falstrue", "falseslaf");
	test("true false true x", "x false true false");

	return 0;
}
