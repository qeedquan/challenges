/*

For example, dddogg (3 d’s, 1 o, 2 g’s) turns into ddddooggg (4 d’s, 2 o’s, 3 g’s).

This is code-golf: the shortest answer in bytes wins.

Test cases
aabbcccc -> aaabbbccccc
doorbell -> ddooorrbbeelll
uuuuuuuuuz -> uuuuuuuuuuzz
q -> qq
xyxyxy -> xxyyxxyyxxyy
xxxyyy -> xxxxyyyy

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
lengthen(const char *s, char *b)
{
	size_t i, j;
	char *p;

	p = b;
	for (i = 0; s[i]; i = j) {
		for (j = i; s[i] == s[j]; j++)
			*p++ = s[i];
		*p++ = s[i];
	}
	*p = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	lengthen(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("aabbcccc", "aaabbbccccc");
	test("doorbell", "ddooorrbbeelll");
	test("uuuuuuuuuz", "uuuuuuuuuuzz");
	test("q", "qq");
	test("xyxyxy", "xxyyxxyyxxyy");
	test("xxxyyy", "xxxxyyyy");

	return 0;
}
