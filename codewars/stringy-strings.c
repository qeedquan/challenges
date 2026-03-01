/*

write me a function stringy that takes a size and returns a string of alternating '1s' and '0s'.

the string should start with a 1.

a string with size 6 should return :'101010'.

with size 4 should return : '1010'.

with size 12 should return : '101010101010'.

The size will always be positive and will only use whole numbers.q

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
stringy(size_t n, char *b)
{
	size_t i;
	char *p;

	p = b;
	for (i = 0; i < n; i++)
		*p++ = '1' ^ (i & 1);
	*p = '\0';
	return b;
}

void
test(size_t n, const char *r)
{
	char b[128];

	stringy(n, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(6, "101010");
	test(4, "1010");
	test(12, "101010101010");

	return 0;
}
