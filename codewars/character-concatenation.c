/*

Given a string, you progressively need to concatenate the first letter from the left and the first letter to the right and "1", then the second letter from the left and the second letter to the right and "2", and so on.

If the string"s length is odd drop the central element.

For example:

charConcat("abcdef")    == "af1be2cd3"
charConcat("abc!def")   == "af1be2cd3" // same result

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
charconcat(const char *s, char *b)
{
	size_t c, i, n;
	char *p;

	p = b;
	c = 1;
	n = strlen(s);
	if (n)
		n -= 1;
	for (i = 0; i < n; c++) {
		p += sprintf(p, "%c%c%zu", s[i], s[n], c);
		i += 1;
		n -= 1;
	}
	*p = '\0';
}

void
test(const char *s, const char *r)
{
	char b[32];

	charconcat(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("abcdef", "af1be2cd3");
	test("abc!def", "af1be2cd3");
	test("abc def", "af1be2cd3");
	test("CodeWars", "Cs1or2da3eW4");
	test("CodeWars Rocks", "Cs1ok2dc3eo4WR5a 6rs7");
	test("1234567890", "101292383474565");
	test("$\"D8KB)%PO@s", "$s1\"@2DO38P4K%5B)6");

	return 0;
}
