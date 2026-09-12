/*

Given a mathematical equation that has *,+,-,/, reverse it as follows:

solve("100*b/y") = "y/b*100"
solve("a+b-c/d*30") = "30*d/c-b+a"

More examples in test cases.

Good luck!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t
token(const char *s)
{
	size_t i;

	i = 0;
	if (isdigit(s[i])) {
		do {
			i++;
		} while (isdigit(s[i]));
	} else if (s[0])
		i = 1;

	return i;
}

void
solve(const char *s, char *b)
{
	size_t n;
	char *p;

	p = b + strlen(s);
	p[1] = '\0';
	while ((n = token(s))) {
		p -= n;
		memcpy(p, s, n);
		s += n;
	}
}

void
test(const char *s, const char *r)
{
	char b[128];

	solve(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("", "");
	test("100*b/y", "y/b*100");
	test("a+b-c/d*30", "30*d/c-b+a");
	test("a*b/c+50", "50+c/b*a");
	test("999", "999");

	return 0;
}
