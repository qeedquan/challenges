/*

Input: a number

Output : the next higher number that uses the same set of digits.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
swap(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

bool
nextperm(char *b)
{
	char *p, *s, *t;

	p = b;
	if (!p || !*p)
		return false;

	while (*p)
		p++;

	t = --p;
	while (p != b && p[-1] >= p[0])
		p--;

	if (p == b)
		return false;

	s = t;
	for (p--; *p >= *s;)
		s--;

	swap(p, s);
	for (p++; p < t; p++, t--)
		swap(p, t);

	return true;
}

void
test(char *b, bool r0, const char *r1)
{
	assert(nextperm(b) == r0);
	assert(!strcmp(b, r1));
}

int
main()
{
	char b1[] = "5";
	char b2[] = "5987643";
	char b3[] = "38276";
	char b4[] = "987654321";
	char b5[] = "9376544321";

	test(b1, false, "5");
	test(b2, true, "6345789");
	test(b3, true, "38627");
	test(b4, false, "987654321");
	test(b5, true, "9412334567");

	return 0;
}
