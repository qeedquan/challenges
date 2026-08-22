/*

You receive the name of a city as a string, and you need to return a string that shows how many times each letter shows up in the string by using asterisks (*).

For example:

"Chicago"  -->  "c:**,h:*,i:*,a:*,g:*,o:*"
As you can see, the letter c is shown only once, but with 2 asterisks.

The return string should include only the letters (not the dashes, spaces, apostrophes, etc). There should be no spaces in the output, and the different letters are separated by a comma (,) as seen in the example above.

Note that the return string must list the letters in order of their first appearance in the original string.

More examples:

"Bangkok"    -->  "b:*,a:*,n:*,g:*,k:**,o:*"
"Las Vegas"  -->  "l:*,a:**,s:**,v:*,e:*,g:*"

Have fun! ;)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
count(const char *s, char *b)
{
	size_t h[256];
	size_t i, j;
	int c;
	char *p;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[tolower(s[i]) & 0xff]++;

	p = b;
	*p = '\0';
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]) & 0xff;
		if (!('a' <= c && c <= 'z') || !h[c])
			continue;

		p += sprintf(p, "%c:", c);
		for (j = 0; j < h[c]; j++)
			p += sprintf(p, "*");
		p += sprintf(p, ",");

		h[c] = 0;
	}
	if (p != b)
		p[-1] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	count(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Chicago", "c:**,h:*,i:*,a:*,g:*,o:*");
	test("Bangkok", "b:*,a:*,n:*,g:*,k:**,o:*");
	test("Las Vegas", "l:*,a:**,s:**,v:*,e:*,g:*");
	return 0;
}
